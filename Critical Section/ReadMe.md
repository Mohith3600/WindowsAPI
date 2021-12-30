# Critical Section 
Critical section is used to overcome the problems which occur in the race condtion.
Critical section is a region of code where code need to be executed atomically or indivisible operation.
Critical Section is used for Synchronization 
It provides a lock similar to Mutex 
Process is only responsible for allocation the memory used by Critical Section 

Example:

do {
	Entry_section()
	Critical_Section
	Exit_section()
}
//Rest of the code 
}while (TRUE)

# Difference between CRITICAL_SECTION & MUTEX
# Critical Section

1)C.S object does not shared by process
2)C.S is used by only the thread of a single process
3)It does not communicate with Kernel 
4)It is slightly faster than Event, Mutex and Semaphore 

# Mutex 

1)Mutex Object is shared by Processes 
2)It is used by more than one Process
3)It may communicate to Kernel 
4)It is slower and may lead to deadlock 

# CRITICAL_SECTION API's

1.InitializeCriticalSection  
It will initialize the critical section 
initialize a critical section object 

2.InitializeCriticalSectionAndSpinCount
This is busy and wait 
If the resource is not available it will be continously in the wait for the resource 
If the resource is available it will acquire the locks

3.EnterCriticalSection 
Provide how to enter the critical section
Waits for ownership of the specified critical section object. The function returns when the calling thread is granted ownership


4.TryEnterCriticalSection 
If the resource is not available it wil try to attempt into the critical section

5.LeaveCriticalSection
Exiting the critical section
Releasing the critical section object 

6.SetCriticalSectionSpinCount
Sets the spin count for the specified critical section. Spinning means that when a thread tries to acquire a critical section that is locked, the thread enters a loop, checks to see if the lock is released, and if the lock is not released, the thread goes to sleep.

7.DeleteCriticalSection
Delete the critical section object 
Releases all resources used by an unowned critical section object
