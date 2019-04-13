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
