#include<Windows.h>
#include<iostream>
int main()
{
	HANDLE hFile ; //Handle Variable 
	BOOL bFile ;   //Returns true or false of the handle variable 
	char chBuffer[] = "Sample to write and read the file" //Text written into the file 
	DWORD dwNoBytesToWrite = strlen(chBuffer); //Size of the written data 
	LPDWORD lpNoBytesWritten = 0; //Set Write Pointer to 0
	DWORD dwNoBytesToRead =strlen(chBuffer) ; //size of the file to read 
	LPDWORD lpNoBytesRead  = 0 ; //Set Read Pointer to 0

	//STEP 1 - CreateFile Function 
	hFile = CreateFile(
		L"E:\\Sample\\Sample.txt" , //File Path and Name 
		GENERIC_READ | GENERIC_WRITE , //File Permission 
		FILE_SHARE_READ | FILE_SHARE_WRITE , //File Sharing mode 
		NULL , //Security Attribute 
		CREATE_NEW | OPEN_EXISTING , //If the file exists it will be opened or created 
		FILE_ATTRIBUTE_NORMAL , //Flag for File 
		NULL , //Default File Template
		);

	//STEP 2 - Check the creation of the file 
	if (INVALID_HANDLE_VALUE == hFile)
	{
		cout <<"Creation of the file failed "<<endl;
		cout<<"Error number " <<GetLastError()<<endl;
	}
	else
	{
		cout<<"creation of the file is successful"<<endl;
	}
	//STEP 3 - Write File function 
	bFile = WriteFile(
		hFile, 
		chBuffer,
		dwNoBytesToWrite,
		lpNoBytesWritten,
		NULL);
	if(FALSE == bFile)
	{
		cout<<"Write Function failed "<<endl;
		cout<<"Error number is "<<GetLastError()<<endl;
	}
	else{
		cout<<"Write Function is successful"<<endl;
	}

	//STEP 4 - Read File Function 
	bFile = ReadFile(
		hFile,
		chBuffer,
		dwNoBytesToRead,
		lpNoBytesRead,
		NULL);
	if (FALSE == bFile)
	{
		cout<<"Read File Function failed"<<endl;
		cout<<"Error number is "<<GetLastError()<<endl; 
	}
	else
	{
		cout<<"Read File function is successful"<<endl;
	}
	//STEP 5 - Read data from the buffer 
	cout<<"Data from the buffer is "<<chBuffer << endl;

	//STEP 6 - CLose the File handle 
	CloseHandle(hFile);

	system("PAUSE");
	return 0;
}