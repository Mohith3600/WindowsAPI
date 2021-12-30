#include<Windows.h>
#include<iostream>
using namespace std;

//Global variable 
int gcount = 1;
//Critical section global variable cs
CRITICAL_SECTION cs;

//Thread Function 
DWORD WINAPI ThreadFunEven(LPVOID lpParam)
{
	while (gcount < 10)
	{
		EnterCriticalSection(&cs);
		if (gcount % 2 == 0)
		{
			cout << "Even number" << gcount++ << endl;
		}
		LeaveCriticalSection(&cs);
	}
	return 0;
}

DWORD WINAPI ThreadFunOdd(LPVOID lpParam)
{
	while (gcount < 10)
	{
		EnterCriticalSection(&cs);
		if (gcount % 2 == 1)
		{
			cout << "Odd number" << gcount++ << endl;
		}
		LeaveCriticalSection(&cs);
	}
	return 0;
}

int main()
{
	cout << "\t\t---CRITICAL SECTION---------" << endl;
	HANDLE hThread1, hThread2;

	//Initialize the critical section object 
	InitializeCriticalSection(&cs);

	//Create Thread Function Even 
	hThread1 = CreateThread(
		NULL,
		0,
		ThreadFunEven,
		NULL,
		0,
		NULL
	);

	hThread2 = CreateThread(
		NULL,
		0,
		ThreadFunOdd,
		NULL,
		0,
		NULL
	);
	
	//Wait for the signaled object 
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	//Close the Handle of the thread 
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	//Deleting the critical section object 
	DeleteCriticalSection(&cs);

	system("PAUSE");
	return 0;
}