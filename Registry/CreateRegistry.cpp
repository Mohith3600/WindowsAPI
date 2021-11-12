#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	HKEY hKey;
	LSTATUS LStatus;
	DWORD dwData = 1234;
	
	//Step 1 Registry Create Key Function 
	LStatus = RegCreateKeyEx(
		HKEY_LOCAL_MACHINE,
		L"Software\\Test\\Product\\TestId", //Path for Subkey
		0, // Reserved 
		NULL, //Class of Key
		REG_OPTION_NON_VOLATILE, //Registry Options 
		KEY_ALL_ACCESS | KEY_WOW64_64KEY, //Access Right
		NULL, //Default Security attribute
		&hKey,//Pointer Variable which receives Registry Creations 
		NULL//Disposition Information NULL
		);

	//Step 2 Check if registry key is successful created 
	if (LStatus != ERROR_SUCCESS)
	{
		cout << "Registry creation Failed" << endl;
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Creation of the Registry is successful" << endl;
	}

	//Step 3 Registry Set Value Function 
	LStatus = RegSetValueEx(
		hKey, //Handle For Open Key 
		L"Value", //Registry Value Name 
		0, //Reserved 
		REG_DWORD, //Data type of Registry Key 
		(LPBYTE)&dwData, //Registry Data 
		sizeof(dwData)); //Size of the Registry data 

	//Step 4 Check the condition 
	if (LStatus != ERROR_SUCCESS)
	{
		cout << "Adding of the value to registry is failed " << endl;
		cout << "Error is " << endl;
	}
	else
	{
		cout << "Adding the value is successful" << endl;
	}

	//Step 5 - Use the Registry close key function 
	RegCloseKey(hKey);
	system("PAUSE");
	return 0;

}