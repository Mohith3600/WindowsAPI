# Socket 
Socket is one endpoint which is used for communicating between two nodes in a Network 

Socker is an interface of Client-Server Architecture 

# Socket Type 
Internet Sockets 
Unix Sockets 
X.25 Sockets etc

# Internet Socket
Internet sockets characterized by IP Address(4 bytes) and port number(2 bytes)
Its' a Transport layer protocol 

# TYPES 
1. STREAM SOCKETS(SOCK_STREAM)
a. Connection Oreinted 
b. Rely on TCP to provide two ways Communication 

2. DATAGRAM SOCKETS(SOCK_DGRAM)
a. Connection is Unreliable 
b. Rely on UDP 


# User Data Protocol 
1. Message Oriented 
2. Connection less i.e No connection to create and maintain 
3. Light weight(UDP header is 60% less than TCP Header)
4. Small Packet Size UDP Header-8 Byte 
5. There is no error detection 
6. If you lose you can't retrieve 
7. Corrupted Data may be discarded or lead to out of order.
