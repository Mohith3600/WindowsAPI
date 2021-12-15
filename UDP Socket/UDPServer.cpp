#include <Windows.h>
#include <iostream>
#include <winsock.h>
using namespace std;
int main()
{
	// Local Variable definitions

	cout << "\t\t------- UDP Server---" << endl;
	cout << endl;

	WSADATA   WinSockData;
	int       iWsaStartup;
	int       iWsaCleanup;

	SOCKET    UDPSocketServer;
	struct    sockaddr_in UDPClient;

	char      Buffer[512];
	int       iBufferLen = strlen(Buffer) + 1;

	int       iBind;
	int       iReceiveFrom;

	int       iUDPClientLen = sizeof(UDPClient);
	int       iCloseSocket;

	// STEP-1 Initialization of Winsock
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);

	if (iWsaStartup != 0)
	{
		cout << "WSAStartUp Fun Failed" << endl;
	}
	cout << "WSAStartUp Success" << endl;

	//STEP-2 Fill the UDPClient(SOCKET ADDRESS) Structure
	UDPClient.sin_family = AF_INET;
	UDPClient.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPClient.sin_port = htons(8001);

	// STEP-3 Socket Creation
	UDPSocketServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (UDPSocketServer == INVALID_SOCKET)
	{
		cout << "Socket Creation Failed " << endl;
		cout << "Error No-> " << WSAGetLastError() << endl;
	}
	cout << "Socket Creation Success" << endl;
	// STEP-4 bind the server
	iBind = bind(
		UDPSocketServer,
		(SOCKADDR*)&UDPClient,
		sizeof(UDPClient));
	if (iBind == SOCKET_ERROR)
	{
		cout << "Binding Failed " << endl;
		cout << "Error No-> " << WSAGetLastError() << endl;
	}
	cout << "Binding Success" << endl;
	//STEP-5 RecvFrom Fun from receive data from client
	iReceiveFrom = recvfrom(
		UDPSocketServer,
		Buffer,
		iBufferLen,
		MSG_PEEK,
		(SOCKADDR*)&UDPClient,
		&iUDPClientLen);

	if (iReceiveFrom == SOCKET_ERROR)
	{
		cout << "Receiving failed " << endl;
		cout << "Error No-> " << WSAGetLastError() << endl;
	}
	cout << "Receiving Success" << endl;
	cout << "Receive Data -> " << Buffer << endl;

	//STEP-6 CloseSocket Function
	iCloseSocket = closesocket(UDPSocketServer);

	if (iCloseSocket == SOCKET_ERROR)
	{
		cout << "Socket Closing failed " << endl;
		cout << "Error No-> " << WSAGetLastError() << endl;
	}
	cout << "Socket CLosing Success" << endl;

	//STEP-7 WSACLeanUp Fun for Terminating the use of DLL
	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
	{
		cout << "WSA CleanUp failed " << endl;
		cout << "Error No-> " << WSAGetLastError() << endl;
	}
	cout << "WSA CleanUp Success" << endl;

	system("PAUSE");
	return 0;
}