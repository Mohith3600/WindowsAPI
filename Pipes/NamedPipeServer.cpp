#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
cout << "\t\t....NAMED PIPE SERVER...." << endl;
//Named Pipe Local Variable
HANDLE hCreateNamedPipe = INVALID_HANDLE_VALUE;
char   szInputBuffer[1023] = {0};
char   szOutputBuffer[1023]={0};
DWORD  dwszInputBuffer = sizeof(szInputBuffer);
DWORD  dwszOutputBuffer = sizeof(szOutputBuffer);
//ConnectNamedpipe Local Variable
BOOL bConnectNamedPipe= FALSE;
//WriteFile Local Variable
BOOL  bWritefile=FALSE;
char  szWriteFileBuffer[1023] = "Hello From NamedPipe Server!!";
DWORD dwWriteBufferSize = sizeof(szWriteFileBuffer);
DWORD dwNoBytesWrite=0;

//FlushBuffer
BOOL bFlushFIleBuffer = FALSE;
//ReadFile Local Variable
BOOL  bReadfile=FALSE;
char  szReadFileBuffer[1023] = {0};
DWORD dwReadBufferSize = sizeof(szWriteFileBuffer);
DWORD dwNoBytesRead=0;


//STEP-1 Create the Named Pipe 
hCreateNamedPipe = CreateNamedPipe(
    L"\\\\.\\pipe\\MYNAMEDPIPE",//Pipe Name
    PIPE_ACCESS_DUPLEX,//Open Mode
    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
    PIPE_UNLIMITED_INSTANCES,//Max Instances
    dwszOutputBuffer,//Output Buffer
    dwszInputBuffer,//Input Buffer
    0, //Default Time Out
    NULL); //Security Attributes
if (hCreateNamedPipe == INVALID_HANDLE_VALUE)
{
   cout << "NamedPipe Creation Failed "<<endl;

   cout<<"Error No - " << GetLastError() << endl;
}
cout << "NamedPipe Creation Success" << endl;
//STEP-2 Connect the Named Pipe

bConnectNamedPipe = ConnectNamedPipe(hCreateNamedPipe, NULL);
if (bConnectNamedPipe == FALSE)
{
   cout << "Connection Failed & Error No - " << GetLastError() << endl;
}
cout << "Connection Success" << endl;
//STEP-3 Writefile Operation
  bWritefile = WriteFile(
         hCreateNamedPipe,//Named Pipe Handle
         szWriteFileBuffer,//Write Buffer
         dwWriteBufferSize,//Write Buffer Size
         &dwNoBytesWrite,//No. of bytes to written
         NULL);//Overlapped Parameter

if (bWritefile == FALSE)
{
   cout << "WriteFile Failed = " << GetLastError() << endl;
}
cout << "WriteFile Success" << endl;


//STEP-4 Flush the File Buffer - 
bFlushFIleBuffer = FlushFileBuffers(hCreateNamedPipe);
if (bFlushFIleBuffer == FALSE)
{
cout << "FLushfileBuffer Failed & Error No - " << GetLastError() << endl;
}
cout << "FLushfileBuffer Success" << endl;
//STEP-5 ReadFile Operation
bReadfile = ReadFile(
             hCreateNamedPipe,//Named Pipe Handle
             szReadFileBuffer,//Read Buffer
            dwReadBufferSize,//Read Buffer Size
            &dwNoBytesRead,//No.of bytes Read from
            NULL);//Overlapped Parameters
if (bReadfile == FALSE)
{
   cout << "ReadFile Failed = " << GetLastError() << endl;
}
cout << "ReadFile Success" << endl;

cout << " DATA READING FROM CLIENT -> " << szReadFileBuffer << endl;

// STEP-6 Disconnect the Named Pipe 
DisconnectNamedPipe(hCreateNamedPipe);//Named Pipe Handle
// STEP-7 CloseHandle 
CloseHandle(hCreateNamedPipe);

system("PAUSE");
return 0;
}
