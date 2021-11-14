#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE hOpenMutex = 0;
	hOpenMutex = OpenMutex
	(
		MUTEX_ALL_ACCESS,
		TRUE,
		L"Mutexone"
	);
	if (NULL == hOpenMutex)
	{
		cout << "OpenMutex Function Failed " << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "OpenMutex function is successful" << endl;
	}
	system("PAUSE");
	return 0;
}