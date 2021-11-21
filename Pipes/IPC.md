# Interprocess Communication 
Whenever A system or application or process want to communicate with other system or process or application then they are communicating with the help of Inter-process communication(IPC).

Inter-Process Communication(IPC)
IPC is a mechanism that allows to communicate between processes
So,working with multiple processes, needs and IPC method which allows to exchange the data and various information between processes.

There are two types of IPC models 
	1.Message Passing 
	2.Share Memory 

1.Message Passing 
In this method, Processes communicate via link.
Message will be used 
First they establish a link then process id and data for communicating.
Simply a send and receiver

2.Shared Memory 
Process communicate with a region of shared memory.
First they create a shared region of memory in address space 
If other process wishes to communicate using shared space then they must connect it with their address space.

These are following IPC mechanism in Windows 
a.Pipes
b.File Mapping 
c.Mailslots 
d.Windows Sockets 
e.Clipboard 
f.COM 
g.RPC 
h.Dynamic Data Exchange(DDE)
i.Data copy 