# NamedPipe
1.Named Pipe can be used as one-way or two-way communications
2.Named pipe can be used over the network 
3.Named Pipes can be used to provide communications between processes on the same computer or different computer over network 
4.Named Pipes provides Multiple Pipes clients use same pipe at a same time 
5.Named Pipe provides bidirectional data flow between multiple processes
6.Named Pipe provide control over security and ownership

# Named Pipe Working 
Server Side Always Starts the communication.
i.Server Always Create pipe using CraeteNamedPipe Function.
ii.Server Accept the connection using ConnectNamedPipe Function and Client connect using CreateFile or CallNamedPipe Function.
iii.Server writes data to client or read from Client using ReadFile and WriteFile Function.
iv.Client writes data to Server or read from Server using ReadFile and WriteFile Function.
v.After writng the data, need to flush the buffer using FlushFileBuffer Function.when Client or Server side reads the data.
vi.After Performing reading and writing operation, Server disconnect the Pipe using DisconnectNamedPipe function.