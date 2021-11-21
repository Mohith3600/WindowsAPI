#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	BOOL bCreatepipe = FALSE;
	char szBuffer[512] = "Anonymous Pipe";
	DWORD dwBufferSize = sizeof(szBuffer);
	HANDLE hRead = NULL;
	HANDLE hWrite = NULL;
	BOOL bWritefile = FALSE;
	BOOL bReadfile = FALSE;
	DWORD dwNoBytesWrite = 0;
	DWORD dwNoBytesRead = 0;

	//STEP 1 Create Anonymous Pipe 
	bCreatepipe = CreatePipe(
		&hRead,			//Read Pipe Handle 
		&hWrite,		//Write pipe Handle
		NULL,			//Pipe Attribute
		dwBufferSize	//size
	);

	if (FALSE == bCreatepipe)
	{
		cout << "Pipe Creation Failed" << endl;
		cout << "Error number is " << GetLastError() << endl;
	}
	else
	{
		cout << "Creation of the pipe is successful" << endl;
	}

	//STEP 2 Write File Operation 

	bWritefile = WriteFile(
		hWrite, // Write Handle 
		szBuffer, //buffer name 
		dwBufferSize, //Buffer size
		&dwNoBytesWrite,//no of bytes written to the buffer
		NULL //overlapped
	);
	if (FALSE == bWritefile)
	{
		cout << "Write File Failed " << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Write File is successful" << endl;
	}

	//STEP 3 Close the Handle 
	CloseHandle(hWrite);

	//STEP 4 Read Data from pipe
	bReadfile = ReadFile(
		hRead, // Read Handle 
		szBuffer, //buffer name 
		dwBufferSize, //Buffer size
		&dwNoBytesRead, // no of bytes to read from the buffer
		NULL
	);
	
	if (FALSE == ReadFile)
	{
		cout << "Read File function and the errror is " << GetLastError() << endl;
	}
	else
	{
		cout << "Reading from the file is successful" << endl;
	}
	//STEP 5 Read data from the pipe
	cout << "Pipe data is " << szBuffer << endl;

	//STEP 6 Close the Read Handle 
	CloseHandle(hRead);

	system("PAUSE");
	return 0;

}

