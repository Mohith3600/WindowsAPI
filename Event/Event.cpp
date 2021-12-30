#include<Windows.h>
#include<iostream>
using namespace std;

HANDLE hEvent;

DWORD WINAPI ThreadFun1(LPVOID lpParam) //Thread 1 Function
{
	WaitForSingleObject(hEvent, INFINITE); //Wait for an object to be signaled
	cout << "Thread - 1 Running" << endl;
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID lpParam) //Thread 2 Function
{
	WaitForSingleObject(hEvent, INFINITE);
	cout << "Thread -2 RUnning" << endl;
	SetEvent(hEvent); //Set Event to be signaled stated
	return 0;
}

int main()
{
	HANDLE hThread1, hThread2;
	DWORD ThreadId1, ThreadId2;

	hEvent = CreateEvent(
		NULL,
		FALSE,
		FALSE,
		L"MyEvent"
	);
	if (NULL == hEvent)
	{
		cout << "Creation of the Event is failed " << endl;
		cout << "Error number is " << GetLastError() << endl;
	}
	cout << "Creation of the event is success" << endl;

	hThread1 = CreateThread(
		NULL,
		0,
		ThreadFun1,
		NULL,
		0,
		&ThreadId1
	);
	if (hThread1 == NULL)
	{
		cout << "Thread 2 creation failed" << GetLastError() << endl;
	}
	hThread2 = CreateThread(
		NULL,
		0,
		ThreadFun2,
		NULL,
		0,
		&ThreadId2
	);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hEvent);
	system("PAUSE");
}