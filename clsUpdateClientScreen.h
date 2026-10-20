#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsPerson.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Pincode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFltNumber();
	}

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

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pUpdateClient))
		{
			return;		// It Will Exit The Function.
		}

		_DrawHeaderScreen("\tUpdate Client Screen");

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

		cout << "\nUpdate Client Info: ";
		cout << "\n______________________";

		_ReadClientInfo(Client1);		// Will Change The Object Info.

		clsBankClient::eSaveResults SaveResults;

		SaveResults = Client1.Save();

		switch (SaveResults)
		{
		case clsBankClient::eSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :)\n";
			_PrintClient(Client1);
			break;
		}

		case clsBankClient::eSaveResults::svFailedEmptyObject:
		{
			cout << "\nError. Account Was Not Saved Because It's Empty.\n";
			break;
		}

		}
	}


};

