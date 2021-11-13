#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE hProcess;
	HANDLE hThread;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwProcessID;
	DWORD dwThreadID;
	BOOL bProcess;

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	//STEP 1 - Create Process Function 
	bProcess = CreateProcess(
		L"C:\\Program Files\\BraveSoftware\\Brave-Browser\\Application\\brave.exe",
		NULL, // Command Line
		NULL, //Not Inheritable Process Handle 
		NULL, //Not Inheritable Thread Handle 
		FALSE, //Handle Inheritance
		0, //No Creation Flag 
		NULL, // Parent's Environment Block 
		NULL, // Parent's Process Directory 
		&si, //STARTUPINFO Structure 
		&pi); //PROCESS_INFORMATION structure

	//STEP 2 Check Process has created or not 
	if (bProcess == FALSE)
	{
		cout << "Creation of the process Failed" << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Creation of the process is successful" << endl;
	}
	//STEP 3 Print Process ID and Thread ID 
	cout << "Process id is " << pi.dwProcessId << endl;
	cout << "Thread id is " << pi.dwThreadId << endl;
	cout << "Process id" << GetProcessId(pi.hProcess) << endl;
	cout << "Thread id " << GetThreadId(pi.hThread) << endl;

	//STEP 4 Wait until child process Exit 
	WaitForSingleObject(pi.hProcess, INFINITE);

	//STEP 5 Close the open Handle for Process and its Primary Thread 
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	system("PAUSE");
	return 0;
}