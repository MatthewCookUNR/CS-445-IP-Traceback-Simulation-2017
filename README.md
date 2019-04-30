# Project Details
### Node Sampling 
An algorithm where each router has a probability of marking a packet with its address as it traverse through the network.
Routers can overwrite previously marked packets. The traceback to the attacker is distinguished by the relative number of packets marked at each router along the path.
### Edge Sampling
The algorithm improves upon the node sampling algorithm. If a packet is marked, the packet sets a "start" field to its address and sets a "distance" field to 0.
Each router that receives the marked packet will either probabilistically mark the packet again or increment the distance field. 
That way, once a marked packet is received, the victim knows its address and how many hops away it is. 
The traceback to the attacker can be found once the victim has received at least one marked packet from all of the routers along the path between them.
The algorithm requires less packets to achieve successful traceback and multiple, simultaneous attackers can be distinguished.

### Tested Variables
- Number of routers (10, 20, 30)
- Number of network branches (3, 4, 5)
- Probability of marking packets (0-1)
- Multiplicative factor of the attacker(s) (10, 100, 1000)
- Number of packets sent by attacker(s)
