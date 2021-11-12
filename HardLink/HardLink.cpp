#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	BOOL bFile;
	bFile = CreateHardLink(L"E:\\Winapi\\testfile2.txt",
		L"E:\\Winapi\\hardlink.txt",
		NULL);
	if (bFile==FALSE)
	{
		cout<<"Creation of the hard link failed"<<endl;
		cout<<"Error is "<<GetLastError()<<endl;
	}
	else
	{
		cout<<"Creation of the hard link file is successful"<<endl;
	}
	system("PAUSE");
	return 0;
}