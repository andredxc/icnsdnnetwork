# ICN SDN Network

This repository has the objective of executing experiments that are capable to validate the integration of an ICN (Information-centric Network) along with a SDN (Software-defined Network). 

To setup and execute the experiments it is needed to install all the components present in this repository (netbee, ryu, minindn along with mininet and uBPF). All the steps to install them are present inside their own folders in the READ.md.

After all the dependencies are installed it is possible to execute a few ready experiments.

## Working explanation

### 1. Switches
The switches have to be programmable so they can process forwarding by name, and not by location. Using this version of the ofsoftswitch integrated with eBPF it is possible to receive C programs which specify how a packet is processed and forwarded. Those programs in this work are received incoming from the controller. Currently there is a program working appropriately which is defined on [ryu/bin/match_param_icn.c](https://github.com/gabrielmleal/icnsdnnetwork/blob/master/ryu/bin/match_param_icn.c), and it defines that every UDP packet that matches with an [NDN packet format](https://named-data.net/doc/NDN-packet-spec/current/) with a name that has some specific forwarding rule defined by the controller should be forwarded accordingly.


ICN are networks that maps the content based on their name, not their location, however this 

## Setup

