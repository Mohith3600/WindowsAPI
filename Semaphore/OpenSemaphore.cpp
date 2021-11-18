#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE hSem = 0;
	cout << "Open Semaphore" << endl;
	hSem = OpenSemaphore(
		SEMAPHORE_ALL_ACCESS,
		FALSE,
		L"MySemaphore"
	);
	if (NULL == hSem)
	{
		cout << "Open Semaphore creation Failed" << endl;
		cout << "Error number is " << GetLastError() << endl;
	}
	else
	{
		cout << "Open Semaphore Function is successful" << endl;
	}
	CloseHandle(hSem);
	system("PAUSE");
	return 0;

}