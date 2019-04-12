from ryu.base import app_manager
from ryu.controller import ofp_event
from ryu.controller.handler import CONFIG_DISPATCHER, MAIN_DISPATCHER
from ryu.controller.handler import set_ev_cls
from ryu.ofproto import ofproto_v1_3
from ryu.topology import event, switches
from ryu.topology.api import get_switch, get_link
from ryu.lib.type_desc import BPFProgram, BPFMatch, ExecBpf
from struct import *

from ryu.lib.packet import packet
from ryu.lib.packet import ethernet
from ryu.lib.packet import ether_types
from ryu.ofproto import ether
from ryu.ofproto import inet
from ryu.lib.packet import arp
from ryu.lib.packet import ipv4
from ryu.lib.packet import udp
from ryu.lib.packet import tcp
from ryu.lib.packet import icmp

from ryu.app.wsgi import ControllerBase

import networkx as nx

import os

class IcnSdnApp(app_manager.RyuApp):
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]

    def __init__(self, *args, **kwargs):
        super(IcnSdnApp, self).__init__(*args, **kwargs)
        self.ip_mac = {}
        self.mac_to_port = {}
        self.topology_api_app = self
        self.net=nx.DiGraph()
        self.nodes = {}
        self.links = {}
        self.no_of_nodes = 0
        self.no_of_links = 0
        self.i=0
        self.drones = []
        self.humans = []
        self.sensors = []
        self.vehicles = []
        self.registered_data = {}


    #Parte do arp
    def receive_arp(self, datapath, packet, etherFrame, inPort):
        arpPacket = packet.get_protocol(arp.arp)

        arp_dstIp = arpPacket.dst_ip
        if arpPacket.opcode == 1:
            #caso seja um ARP Request, tenta responder a solicitacao
            self.logger.debug("receive ARP request %s => %s (port%d) IP: %s"
                       %(etherFrame.src, etherFrame.dst, inPort, arp_dstIp))
            #self.Fluxo.set_mac_host(arpPacket.src_ip, etherFrame.src)
            if arpPacket.src_ip not in self.ip_mac.keys():
                self.ip_mac[arpPacket.src_ip] = etherFrame.src
            if arpPacket.dst_ip in self.ip_mac.keys():
                self.reply_arp(datapath, etherFrame, arpPacket, arp_dstIp, inPort)

        elif arpPacket.opcode == 2:
            #Caso seja um ARP Reply, ignora.
            self.logger.debug("receive ARP reply %s => %s (port%d) IP: %s"
                       %(etherFrame.src, etherFrame.dst, inPort, arp_dstIp))



    def reply_arp(self, datapath, etherFrame, arpPacket, arp_dstIp, inPort):
        dstIp = arpPacket.src_ip
        srcIp = arpPacket.dst_ip
        dstMac = etherFrame.src

        
        srcMac = self.ip_mac[arp_dstIp]
        outPort = inPort
        for ips in self.ip_mac:
            print (ips, self.ip_mac[ips])
        print '----------------------------------'
        #Chamada da funcao para criar um ARP reply e enviar para o host
        self.send_arp(datapath, 2, srcMac, srcIp, dstMac, dstIp, outPort)
        self.logger.debug("send ARP reply %s => %s (port%d)\n" %(srcMac, dstMac, outPort))
        

        #Funcao para criar um ARP reply e envia-lo para o host que fez a solicitacao.
    def send_arp(self, datapath, opcode, srcMac, srcIp, dstMac, dstIp, outPort):
        if opcode == 1:
            targetMac = "00:00:00:00:00:00"
            targetIp = dstIp
        elif opcode == 2:
            targetMac = dstMac
            targetIp = dstIp

        #Cria o pacote ethernet
        e = ethernet.ethernet(dstMac, srcMac, ether.ETH_TYPE_ARP)
        #Cria o pacote arp
        a = arp.arp(1,  0x0800, 6, 4, opcode, srcMac, srcIp, targetMac, targetIp)
        p = packet.Packet()
        p.add_protocol(e)
        p.add_protocol(a)
        p.serialize()
        #Cria ainstrucao de saida. Enviar o ARP Reply pela porta de entrada do ARP Request
        actions = [datapath.ofproto_parser.OFPActionOutput(outPort, 0)]
        out = datapath.ofproto_parser.OFPPacketOut(
            datapath=datapath,
            buffer_id=0xffffffff,
            in_port=datapath.ofproto.OFPP_CONTROLLER,
            actions=actions,
            data=p.data)
        datapath.send_msg(out) #Envia para  o switch a instrucao.

    @set_ev_cls(ofp_event.EventOFPPacketIn, MAIN_DISPATCHER)
    def packet_in_handler(self, ev):
        msg = ev.msg
        datapath = msg.datapath
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        in_port = msg.match['in_port']


        pkt = packet.Packet(msg.data)
        eth = pkt.get_protocol(ethernet.ethernet)

        dst = eth.dst
        src = eth.src
        dpid = datapath.id
        self.mac_to_port.setdefault(dpid, {})


        if src not in self.net:
            self.net.add_node(src)
            self.net.add_edge(dpid,src, port = in_port)
            self.net.add_edge(src,dpid)
        if dst in self.net:
            path=nx.shortest_path(self.net,src,dst)
            next=path[path.index(dpid)+1]
            out_port=self.net[dpid][next]['port']
        else:
            out_port = ofproto.OFPP_FLOOD

        #Verifica se eh um pacote ARP ou IPv4
        if eth.ethertype == ether_types.ETH_TYPE_ARP:
            #Se for ARP, verifica se pode responder a solicitacao.
            self.receive_arp(datapath, pkt, eth, in_port)
            return 0

        actions = [datapath.ofproto_parser.OFPActionOutput(out_port)]
        # install a flow to avoid packet_in next time
        if out_port != ofproto.OFPP_FLOOD:
            if eth.ethertype == ether_types.ETH_TYPE_IP:
                ip = pkt.get_protocol(ipv4.ipv4)
                ipdst = ip.dst
                ipsrc = ip.src
                # print ipsrc, " ", ipdst
                pkt_udp = pkt.get_protocol(udp.udp)
                pkt_icmp = pkt.get_protocol(icmp.icmp)
                if pkt_udp:
                    if pkt[-1].find( "controladddrone", 0) == 6:
                        if ipsrc not in self.drones:
                            self.drones.append(ipsrc)
                            print "drone added "+ipsrc
                        return 0
                    elif pkt[-1].find( "controladdhuman", 0) == 6:
                        if ipsrc not in self.humans:
                            self.humans.append(ipsrc)
                            print "human added "+ipsrc
                        return 0
                    elif pkt[-1].find( "controladdvehicle", 0) == 6:
                        if ipsrc not in self.vehicles:
                            self.vehicles.append(ipsrc)
                            print "vehicle added "+ipsrc
                        return 0
                    elif pkt[-1].find( "controladdsensor", 0) == 6:
                        if ipsrc not in self.sensors:
                            self.sensors.append(ipsrc)
                            print "sensor added "+ipsrc
                        return 0
                    elif pkt[-1].find( "drone", 0) == 6 or pkt[-1].find( "sensor", 0) == 6 or pkt[-1].find( "vehicle", 0) == 6 or pkt[-1].find( "human", 0) == 6:
                        if pkt[-1].find( "drone", 0) == 6:
                            bpfOfpmatch = BPFMatch(0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, "drone")
                            target = self.drones
                        elif pkt[-1].find( "sensor", 0) == 6:
                            bpfOfpmatch = BPFMatch(0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, "sensor")
                            target = self.sensors
                        elif pkt[-1].find( "vehicle", 0) == 6:
                            bpfOfpmatch = BPFMatch(0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, "vehicle")
                            target = self.vehicles
                        elif pkt[-1].find( "human", 0) == 6:
                            bpfOfpmatch = BPFMatch(0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, "human")
                            target = self.humans
                        shortest = 999999
                        ip_shortest = ""
                        new_out_port = 1
                        print '--------------ips--------------'
                        for element in target:
                            print element
                        print '-------------------------------'

                        for element in target:
                            if element == ipsrc:
                                continue
                            aux = nx.shortest_path_length(self.net, src, self.ip_mac[element])
                            path = nx.shortest_path(self.net, src, self.ip_mac[element])
                            if aux < shortest:
                                shortest = aux
                                ip_shortest = element
                                print "Shortest path ip is "+ip_shortest
                                new_out_port = self.net[dpid][path[path.index(dpid)+1]]['port']
                        if not ip_shortest:
                            return
                        match = datapath.ofproto_parser.OFPMatch(in_port=in_port, ipv4_src=ipsrc, eth_dst=dst, exec_bpf=bpfOfpmatch)
                        actions = [
                            parser.OFPActionSetField(eth_dst=self.ip_mac[ip_shortest]),
                            parser.OFPActionSetField(ipv4_dst=ip_shortest),
                            parser.OFPActionOutput(new_out_port)
                        ]
                        self.add_flow(datapath, in_port, dst, match, actions)
                elif not pkt_icmp:
                    match = datapath.ofproto_parser.OFPMatch(in_port=in_port, eth_dst=dst)
                    self.add_flow(datapath, in_port, dst, match, actions)


        out = datapath.ofproto_parser.OFPPacketOut(
            datapath=datapath, buffer_id=msg.buffer_id, in_port=in_port,
            actions=actions)
        datapath.send_msg(out)


    @set_ev_cls(ofp_event.EventOFPSwitchFeatures, CONFIG_DISPATCHER)
    def switch_features_handler(self, ev):
        datapath = ev.msg.datapath
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        action_controller = [datapath.ofproto_parser.OFPActionOutput(ofproto.OFPP_CONTROLLER, ofproto.OFPCML_NO_BUFFER)]


        print 'Clearing the flow table'
        datapath.send_msg(self.remove_table_flows(datapath, 0, parser.OFPMatch(), []))

        match = parser.OFPMatch()
        actions = [parser.OFPActionOutput(ofproto.OFPP_CONTROLLER, ofproto.OFPCML_NO_BUFFER)]
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS , actions)]
        mod = datapath.ofproto_parser.OFPFlowMod(
        datapath=datapath, match=match, cookie=0,
        command=ofproto.OFPFC_ADD, idle_timeout=0, hard_timeout=0, priority=0, instructions=inst)

        datapath.send_msg(mod)

        print 'Transmitting interest bpf program'
        f = open('match_param_icn.o','r')
        self.send_bpf_program(datapath, 0, f.read())


    @set_ev_cls(event.EventSwitchEnter)
    def get_topology_data(self, ev):
       switch_list = get_switch(self.topology_api_app, None)  
       switches=[switch.dp.id for switch in switch_list]
       self.net.add_nodes_from(switches)
       
       print "**********List of switches"
       for switch in switch_list:
         print switch
      
       links_list = get_link(self.topology_api_app, None)
       links=[(link.src.dpid,link.dst.dpid,{'port':link.src.port_no}) for link in links_list]
       self.net.add_edges_from(links)
       links=[(link.dst.dpid,link.src.dpid,{'port':link.dst.port_no}) for link in links_list]
       self.net.add_edges_from(links)
       print "**********List of links"
       print self.net.edges()


    def send_bpf_program(self, datapath, prog_num, bpf_prog):
        print 'sending bpf program'
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser

        prog_len = len(bpf_prog)

        print "prog len: " + str(prog_len) + "\n"

        payload = pack("!II" + str(prog_len)  + "s",prog_num,prog_len,bpf_prog)
        msg = parser.OFPExperimenter(datapath=datapath, experimenter=0x66666666,exp_type=0,data=payload)
        
        datapath.send_msg(msg)


    def add_flow(self, datapath, in_port, dst, match, actions):
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser      
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS, actions)] 
        mod = datapath.ofproto_parser.OFPFlowMod(
           datapath=datapath, match=match, cookie=0,
           command=ofproto.OFPFC_ADD, idle_timeout=0, hard_timeout=5,
           priority=ofproto.OFP_DEFAULT_PRIORITY, instructions=inst
           )
        datapath.send_msg(mod)


    def remove_table_flows(self, datapath, table_id, match, instructions):
        """Create OFP flow mod message to remove flows from table."""
        ofproto = datapath.ofproto
        flow_mod = datapath.ofproto_parser.OFPFlowMod(datapath, 0, 0, table_id, ofproto.OFPFC_DELETE, 0, 0, 1, ofproto.OFPCML_NO_BUFFER, ofproto.OFPP_ANY, ofproto.OFPG_ANY, 0, match, instructions)
        return flow_mod
