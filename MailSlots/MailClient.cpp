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