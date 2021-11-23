#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	cout << "\t\t...MAIL SERVER ..." << endl;
	//Mail Server Variables 
	HANDLE hSlots = INVALID_HANDLE_VALUE;
	BOOL bReadfile = FALSE;
	DWORD dwNoBytesRead = 0;
	char szReadFileBuffer[1023] = { 0 };
	DWORD dwReadFileBufferSize = sizeof(szReadFileBuffer);

	//STEP 1 CreateMail Slot Function 
	hSlots = CreateMailslot(
		L"\\\\.\\mailslots\\MYMAILSLOTS",
		0, //0 can be used to large amount of data
		MAILSLOT_WAIT_FOREVER,
		NULL
	);

	if (hSlots == INVALID_HANDLE_VALUE)
	{
		cout << "Mail Slot Creation Function Failed" << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Mail Slot creation is successful" << endl;
	}

	//STEP 2 ReadFile Function 
	bReadfile = ReadFile(
		hSlots,
		szReadFileBuffer,
		dwReadFileBufferSize,
		&dwNoBytesRead,
		NULL);
	if (bReadfile == FALSE)
	{
		cout << "Read File function failed" << endl;
		cout << "error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Read File function is successful" << endl;
	}
	
	//STEP 3 Close Handle 
	CloseHandle(hSlots);

	system("PAUSE");
	return 0;
#include <Windows.h>
#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
	cout << "\t\t....MAILSLOTS CLIENT...." << endl;
	// CreateFile Local Variable 
	HANDLE hCreatefile = INVALID_HANDLE_VALUE;

	//WriteFile Local Variable 
	BOOL bWritefile = FALSE;
	DWORD dwNoBytesWrite = 0;
	char szWriteFileBuffer[1023] = { 0 };
	DWORD dwWriteFileBufferSize = sizeof(szWriteFileBuffer);

	//STEP-1 CreateFile for MailSlots Client

	hCreatefile = CreateFile(
		L"\\\\.\\mailslot\\MYMAILSLOTS",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (INVALID_HANDLE_VALUE == hCreatefile)
	{
		cout << "File Creation Failed" << endl;
		cout << "Error No. = " << GetLastError() << endl;
	}
	cout << "File Creation Success" << endl;

	//STEP-2 Input from User
	cout << "Write Your Message" << endl;
	gets(szWriteFileBuffer);
	//STEP-3 Writefile Operation

	bWritefile = WriteFile(
		hCreatefile,
		szWriteFileBuffer,
		dwWriteFileBufferSize,
		&dwNoBytesWrite,
		NULL);
	if (bWritefile == FALSE)
	{
		cout << "WriteFile Failed" << endl;
		cout << "Error No. = " << GetLastError() << endl;
	}
	cout << "WriteFile Success" << endl;
	//STEP-4 CloseHandle
	CloseHandle(hCreatefile);
	system("PAUSE");
	return 0;
}