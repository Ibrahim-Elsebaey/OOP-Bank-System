#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
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
	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pDeleteClient))
		{
			return;		// It Will Exit The Function.
		}

		_DrawHeaderScreen("\tDelete Client Screen");

		string AccountNumber = "";

		cout << "\nEnter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nAre You Sure You Want To Delete This Client y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfully.";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError. Client Was Not Deleted.";
			}
		}
	}

};

