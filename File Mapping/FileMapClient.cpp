#include <Windows.h>
#include <iostream>
using namespace std;
int main( )
{
cout<<"\t\t..FILEMAPPING CLIENT or CHILD PROCESS.."<<endl;

// Local Variable Definition

HANDLE   hFileMap ;
BOOL     bResult ;
PCHAR    lpBuffer = NULL;

// STEP-1 OpenFileMapping
hFileMap = OpenFileMapping(
          FILE_MAP_ALL_ACCESS,//DesiredAccess
          FALSE,//Inherit Handle
          L"Local\\MyFileMap");//FileMap Object Name
if (hFileMap == NULL)
{
  cout<<"OpenFIleMap Failed"<<endl;
  cout<<"Error No-> "<<GetLastError()<<endl;
}
cout<<"OpenFIleMap Success"<<endl;

// STEP-2 MapViewOfFile
lpBuffer = (PCHAR)MapViewOfFile(
             hFileMap,//CreateFileMap Handle
             FILE_MAP_ALL_ACCESS,//DesiredAccess
             0,//FileOffsetHigh
             0,//FileOffsetLow
             256 );//Size
if( lpBuffer == NULL )
{
  cout<<"MapViewOfFile Failed "<<endl;
  cout<<"Error No - "<<GetLastError( )<<endl;
} 
cout<<"MapViewOfFile Success"<<endl;

//STEP-3 Reading the Data 

cout<<"DATA READING FROM SERVER or PARENT PROCESS"<<endl;
cout<<lpBuffer<<endl;

//STEP-4 UnmapViewOfFile
bResult = UnmapViewOfFile( lpBuffer );
if( bResult == NULL)
{
 cout<<"Unmapping Failed = "<<GetLastError( )<<endl;
} 
cout<<"Unmapping Success"<<endl;

//STEP-5 Close Handle
CloseHandle(hFileMap);

system("PAUSE");
return 0;
}