LStatus = RegDeleteValueA(
		HKEY_LOCAL_MACHINE,
		regvalue
	);
	if (LStatus != ERROR_SUCCESS)
	{
		cout << "Delete of the registry is failed";
		cout << "Error is " << GetLastError() << endl;
	}
	else
	{
		cout << "Deleteion of hte Directory is successful";
	}