#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE hSem = 0;
	
	//STEP 1 Create Semaphore function 
	hSem = CreateSemaphore(
		NULL,
		1,
		1,
		L"MySemaphore"
	);
	if (NULL == hSem)
	{
		cout << "Create Semaphore Failed" << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Creation of the semaphore is successful" << endl;
	}
	getchar();
	CloseHandle(hSem);
	system("PAUSE");
	return 0;
		
}