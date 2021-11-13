#include<Windows.h>
#include<iostream>
using namespace std;
DWORD WINAPI ThreadFun(LPVOID lpParam)
{
	cout << "\nThread running" << endl;
	return 0;
}
int main()
{
	HANDLE hThread = NULL;
	DWORD ThreadId = 0;

	hThread = CreateThread(
		NULL, //Security Attribute 
		0, //Default Stack Size
		&ThreadFun, //ThreadStart Address
		NULL, //Parameter
		0, //Flags 
		&ThreadId
	);
	if (hThread == NULL)
	{
		cout << "Thread Creation Failed " << endl;
		cout << "Error is " << endl;
	}
	else
	{
		cout << "Creation of the Thread is successful" << endl;
	}

	cout << "Thread Id is " << ThreadId << endl;
	CloseHandle(hThread);

	system("PAUSE");
	return 0;
}