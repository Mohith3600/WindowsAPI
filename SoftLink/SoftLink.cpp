#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	BOOL bCreatLink;
	bCreatLink = (
		L"E:\\Sample\\LinkFolder", //Symbolic File 
		L"E:\\Sample1\\TestFolder" //Source File,
		SYMBOLIC_LINK_FLAG_DIRECTORY);

	if(FALSE == bCreatLink)
	{
		cout<<"Craetion of the soft link failed "<<endl;
		cout<<"Error is "<<GetLastError()<<endl;
	}
	else
	{
		cout<<"Creation of the soft link is success"<<endl;
	}
	system("PAUSE");
	return 0;
}