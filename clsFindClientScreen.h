#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsFindClientScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n______________________";
		cout << "\nFirst Name  : " << Client.FirstName;
		cout << "\nLast Name   : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc Number  : " << Client.AccountNumber();
		cout << "\nPin Code    : " << Client.PinCode;
		cout << "\nAcc Balance : " << Client.AccountBalance;
		cout << "\n______________________";
	}

public:

	static void ShowFindClientScreen()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pFindClient))
		{
			return;		// It Will Exit The Function.
		}

		_DrawHeaderScreen("\tFind Client Screen");

		string AccountNumber = "";
		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found, Choose Another One? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
	}

};

