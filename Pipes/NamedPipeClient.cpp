#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	cout << "\t\t....NAMED PIPE CLIENT...." << endl;
	// Local Variable 
	HANDLE hCreatefile = INVALID_HANDLE_VALUE;

	//Readfile Local Variable
	BOOL      bReadfile = FALSE;
	DWORD     dwNoBytesRead = 0;
	char      szReadFileBuffer[1023] = { 0 };
	DWORD     dwReadFileBufferSize = sizeof(szReadFileBuffer);

	//WriteFile Local Variable 
	BOOL      bWritefile = FALSE;
	DWORD     dwNoBytesWrite = 0;
	char      szWriteFileBuffer[1023] = "Hello From NamedPipe Client!";
	DWORD     dwWriteFileBufferSize = sizeof(szWriteFileBuffer);

	// STEP-1 CreateFile for PipeClient
	hCreatefile = CreateFile(
		L"\\\\.\\pipe\\MYNAMEDPIPE",//File Name(Pipe Name)
		GENERIC_READ | GENERIC_WRITE,//File Access Mode
		0, //File Shared Mode
		NULL, //Security Attributes
		OPEN_EXISTING, //File Desposition
		FILE_ATTRIBUTE_NORMAL,//Files Flags&Attributes
		NULL);//Templatefile

	if (INVALID_HANDLE_VALUE == hCreatefile)
	{
		cout << "File Creation Failed" << endl;
		cout << "Error No = " << GetLastError() << endl;
	}
	cout << "File Creation Success" << endl;

	//STEP-2 Data Reading from NamedPipe Server (ReadFile)
	bReadfile = ReadFile(
		hCreatefile,//File Handle
		szReadFileBuffer,//Read File Buffer
		dwReadFileBufferSize,//Read File Buffer Size
		&dwNoBytesRead,//No.of bytes Read from
		NULL);//Overlapped Parameters
	if (bReadfile == FALSE)
	{
		cout << "ReadFile Failed = " << GetLastError() << endl;
	}
	cout << "ReadFile Success" << endl;
	cout << " DATA READING FROM SERVER -> " << szReadFileBuffer << endl;

	//STEP-3 Data Wrting to NamedPipe Server(Writefile)

	bWritefile = WriteFile(
		hCreatefile,//File Handle
		szWriteFileBuffer,//Write Buffer
		dwWriteFileBufferSize,//Write Buffer Size
		&dwNoBytesWrite,//No. of bytes to written
		NULL);//Overlapped Parameters
	if (bWritefile == FALSE)
	{
		cout << "WriteFile Failed = " << GetLastError() << endl;
	}
	cout << "WriteFile Success" << endl;

	//STEP-4 Flush Files Buffers
	FlushFileBuffers(hCreatefile);
	//STEP-5 Close Handle
	CloseHandle(hCreatefile);
	system("PAUSE");
	return 0;
}