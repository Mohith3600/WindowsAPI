#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE hFile ; //Handle is used to refer the file 
	hfile = CreateFile(
		L"E:\\WinApi\\TestFile2.txt", //Path of the file and it's directory 
		GENERIC_READ | GENERIC_WRITE, //Desired access
		FILE_SHARE_READ, //File share mode 
		NULL , //Security attribute 
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);

	if(INVALID_HANDLE_VALUE == hFile)
	{
		cout<<"Creation of the file failed and the error is " <<GetLastError()<<endl;
	}
	else
	{
		cout<<"Creation of the File is successful "<<endl;
	}
	CloseHandle(hFile);
	system("PAUSE");
	return 0;
}