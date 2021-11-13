 # Threads 
Thread is a sequnetial flow of control within a process \ 
Thread is an independent entity which runs within a process \
A Process can contain multiple threads 

Thread Types 
There are two types of threads 
1.User thread
Created by the User
Context Switch Time is less 
If one thread is blocked the entire operation will be blocked 

2.Kernel Thread 
Created by OS
Implementation of Kernel Thread is complicated 
Context Switch time is more than User's thread 
If one kernel Thread is blocked then another thread can continue their execution 

Thread Models 
	1.One to One Model 
	2.Many to One Model 
	3.Many to Many Model 

1.One to One Model 
In this model each User thread mapped to a Kernel Thread.

Advantages:
If one thread is in blocking state then another thread can continue their execution. It does not block all threads.
Splitting of Process across over multiple CPUs.

Disadvantages:
The main disadvantage of this model is that for each user level thread, it requires corresponding kernel level thread and that makes it costly.
It slows down the system.
For Managing the thread is more overhead.

2.Many to One Model 
In this Model, each user level threads are mapped to single kernel thread.
Advantage
Thread management handles by User space. It makes more efficient.

Disadvantage
If one thread is in blocking state then blocks to operate all threads.
Process cannot split over CPU. Because It’s operated on Single CPU.

3.Many to Many model 
Any number of user level threads mapped to equal or a smaller number of Kernel level threads.
It is the best combination of One to one and many to one threading model.
User have no restriction to create threads.
Blocking operation does not block entire process.
Process can split into multiple processor depend on available CPUs.
