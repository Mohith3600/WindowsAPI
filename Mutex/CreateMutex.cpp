#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	HANDLE hMutex = 0;
	hMutex = CreateMutex(
		NULL,
		TRUE,
		L"MyMutex"
	);
	if (NULL == hMutex)
	{
		cout << "Mutex Creation Failed" << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Creation of the mutex is successful" << endl;
	}
}