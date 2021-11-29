#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	cout << "\t\t FILE MAPPING SERVER" << endl;
	HANDLE hFileMap;
	BOOL bResult;
	PCHAR lpBuffer = NULL;
	char Buffer[1024] = "Hello from File Server";
	size_t szBuffer = size(Buffer);

	
	//Step 1 CreateFileMapping Function 
	hFileMap = CreateFileMapping(
		INVALID_HANDLE_VALUE, //hFile 
		NULL, //FileMappingAttribute
		PAGE_READWRITE, //File Protect Mode 
		0, //Maximum Size Height 
		256, //Maximum Size Low 
		L"Local\\MyFileMap");//File Map Name 

	if (hFileMap == FALSE)
	{
		cout << "Creation of the FileMapping Failed" << endl;
		cout << "Error no" << GetLastError() << endl;
	}
	else
	{
		cout << "Creation of the filemapping is successful" << endl;
	}

	//Step 2 MapViewofFile Function 
	lpBuffer = (PCHAR)MapViewOfFile(
		hFileMap, //CreateFileMap HAndle 
		FILE_MAP_ALL_ACCESS,//Desired Access
		0,//FileOfSetHight
		0,//FileOfSetLow
		256
	);

	if (lpBuffer == NULL)
	{
		cout << "MapViewofFile Failed" << endl;
		cout << "The error is " << GetLastError() << endl;
	}
	else
	{
		cout << "MapViewofFile function is successful" << endl;
	}
	//STEP 3 Copy Memory Function 
	CopyMemory(lpBuffer, Buffer, szBuffer); 
	//Copies a block of memory from one location to another 
	//(Destination , *Source , Length)

	//Step 4 UnmapViewofFile 
	bResult = UnmapViewOfFile(lpBuffer);
	if (bResult == FALSE)
	{
		cout << "Unmap view of function failed" << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Unmap function is successful" << endl;
	}
	system("PAUSE");
	return 0;


}