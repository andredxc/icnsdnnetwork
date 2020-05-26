# ICN SDN Network

This repository has the objective of executing experiments that are capable to validate the integration of an ICN (Information-centric Network) along with a SDN (Software-defined Network). 

To setup and execute the experiments it is needed to install all the components present in this repository (netbee, ryu, minindn along with mininet and uBPF). All the steps to install them are present inside their own folders in the READ.md.

After all the dependencies are installed it is possible to execute a few ready experiments.

## Working explanation

### 1. Switches
The switches have to be programmable so they can process forwarding by name, and not by location. Using this version of the ofsoftswitch integrated with eBPF it is possible to receive C programs which specify how a packet is processed and forwarded. Those programs in this work are received incoming from the controller. Currently there is a program working appropriately which is defined on [ryu/bin/match_param_icn.c](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/ryu/bin/match_param_icn.c), and it defines that every UDP packet that matches with an [NDN packet format](https://named-data.net/doc/NDN-packet-spec/current/) with a name that has some specific forwarding rule defined by the controller should be forwarded accordingly.

### 2. NDN Hosts
The NDN hosts are defined by the NDN packet format, and works within the minindn. But ICN doesn't run using location, and something has to be done to forward the packets. It is possible to map names to some network interface, or IP, or even a socket using the [nfdc](https://named-data.net/doc/NFD/current/manpages/nfdc.html). 
For example, run in your terminal with a ndn host ready:
```
nfdc face create udp://<ip>:<port>
nfdc route add <name> udp://<ip>:<port>
```
  
Those commands will forward every name to the ip and port previsouly set.

### 3. Controller
The controller is able to define routes defined by name, and also the controller sends the programs to the switches so they can recognize a pattern based on the name. As example it is possible to see a controller program on [ryu/bin/icn_sdn.py](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/ryu/bin/icn_sdn.py).


ICN are networks that maps the content based on their name, not their location, however this 

## Setup and running

### 1. Initializing the controller
Initialize the controller program you want to apply the filter rules:

```
ryu-manager --observe-links icn_sdn.py
```

PS: it is important the --observe-links since it helps to track new switches dinamically entering the network.

### 2. Initializing the topology and minindn
There are two different options to initialize the minindn network and topology:

```
sudo minindn
```
This command will initialize with a default topology set by the minindn, but it is also possible to use some ready topologies from minindn. (Details about minindn can be found [here](https://github.com/named-data/mini-ndn))

Also it is possible to construct your own topology, and it is possible to save or load them using

```
sudo minindnedit
```

The topology example for this work can be found on [execution scripts/topology.mnndn](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/execution%20scripts/topology.mnndn)

### 3. Getting ready the ARP and faces (name-IP,port forwarding)

Using the controler program [ryu/bin/icn_sdn.py](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/ryu/bin/icn_sdn.py) it is necessary to ping at least one time to map the MAC to IP to all the network, i.e. setup the ARP table.

In this work all names are mapped to an arbitrary face (IP), since it only have to reach a switch. When the switch detects packet-in the controller knows to forward optimally accordingly with the network current status and the object name. So it is possible to initialize the forwarding rules as follow:

```
nfdc face create udp://10.0.0.7
nfdc route add drone udp://10.0.0.7
nfdc route add human udp://10.0.0.7
nfdc route add sensor udp://10.0.0.7
nfdc route add vehicle udp://10.0.0.7
```

This initialization has to be executed to each host. The script [execution scripts/setup_experiment.py](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/execution%20scripts/setup_experiment.py) is able to set all this configuration to the topology present on [execution scripts/topology.mnndn](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/execution%20scripts/topology.mnndn).

### 4. Command and control/application
Now that the network and the controller have started, it is possible to forward packets between hosts. The program on the mini-ndn/ndn-cxx/examples/masterwork.cpp shows how it can be done using the NDN library. (Soon it'll be added the mini-ndn folder, currently this program is on [execution scripts/masterwork.cpp](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/execution%20scripts/masterwork.cpp)

It is possible to execute for example:

#### On a drone execute:
```
./master_work.cpp producer drone 1
```

#### On another any device execute:
```
./master_work.cpp consumer drone 1
```

It will be able to communicate between 2 NDN hosts using only the name "drone".


#### André's instructions

# Some of the packages needed: 
    g++ python-sphinx libboost-all-dev doxygen libsqlite3-dev libssl-dev valgrind libpcap-dev
    cmake libxerces-c3.1 libxerces-c-dev flex bison libpcre3-dev python-pip msgpack-python

# Some of the python packages needed:
    webob routes oslo.config msgpack eventlet oslo_config('cannot import abc') networkx==2.2

# Installation order:
    mini-ndn/ndn-cxx (version 0.6.2)
    mini-ndn/NFD (version 0.6.2) copy .conf files (see installation docs)
    mini-ndn/ChronoSync (vesion 0.5.1)
    mini-ndn/NLSR (version 0.4.3) copy .conf files (see installation docs)
    mini-ndn/ndn-tools (version 0.6.1)
    mini-ndn/mininet
    mini-ndn
    netbee
    ryu
    ubpf
    
    
## Notes

- Error 403 when adding route: authorization rejected
    ndnsec-keygen /`whoami` | ndnsec-install-cert -