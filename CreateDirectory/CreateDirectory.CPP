#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
    BOOL bDir;
    bDir = CreateDirectory(LPCWSTR "E:\\SampleDirectory",NULL);
    if (bDir == FALSE)
    {
        cout<<"Creation of the Directory is failed and error number is "<<GetLastError()<<endl;
    }
    else
    {
        cout<<"Creation of the Directory is successful"<<endl;
    }
    system("PAUSE");
    return 0;
}
