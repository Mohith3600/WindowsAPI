# CreateProcess 
Program and Process \ 
A program in execution is called Process \
One or more threads run in Context of Proces \
Program consits of code. When the program is compiled it generates binary file or exe file.\
When we run the  executable file it will be process \
Process is a data structure which store an information about process and its memory \

Process can run in two different ways \
1.Background process \
Runs in Background , no user interaction is required \
Background processes are also called as Demon process \
They mainly interact with the system  \
The main advantage of running a process in the Background is that you can run other commands you do not have to wait until the current process ends to start another \ 

2.Foreground process \
It requires user interaction \
Foreground process mainly interacts with the Users \
The user must wait for one Foreground process to complete before running another one \

Process Memory \
Process memory is divided into 4 parts \
Heap - Used for dynamic memory allocation \
Stack - Used for local variable, function return address \
Data - Used for global and static variable. Which initialize before the main program execution \
Text - Made up of compiled program code and holds the Program activity using program counter \

Process Characteristics 
There are following Characteristics of Process: \
1.Process Identifier(PID) – A Unique Identifier for each process, it is  assigned by OS. \
2.Process State – what is the current state of process i.e. running, waiting  etc. \
3.Parent Process ID (PPID) . \
4.CPU Scheduling Information- Process Priority and next process scheduled  information. \
5.Memory Management Information. \
6.Account Information. \
7.CPU Register and Program Counter. \
8. I/O Status – Basically Contains the information about which device is allocated to process, file table etc. \

Process Control Block
It is a data structure which hold the information about process. \
Including PID , PPID, Process State , Process Scheduling, Memory Management and all characteristics of process
