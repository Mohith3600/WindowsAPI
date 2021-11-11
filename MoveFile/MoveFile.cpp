#include<windows.h>
#include<iostream>
using namespace std;
int main()
{
	BOOL bfile;
	bilfe = MoveFile(L"E:\\Winapi\\Old.txt",L"E:\\Winapi\\NewFile.txt");
	if(bfile == FALSE)
	{
	cout<<"Moving of the file failed and the error is "<<GetLastError()<<endl;
	}
	else
	{
	cout<<"Moving of the file is successful"<<endl;
	}
	system("PAUSE");
}