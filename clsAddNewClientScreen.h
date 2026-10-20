#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"


class clsAddNewClientScreen : protected clsScreen
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

	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pAddNewClient))
		{
			return;		// It Will Exit The Function.
		}

		_DrawHeaderScreen("\t  Add New Client Screen");

		string AccountNumber = "";

		cout << "\nEnter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::eSaveResults SaveResults;

		SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case clsBankClient::eSaveResults::svSucceeded:
		{
			cout << "\nAccount Added Successfully :)\n";
			_PrintClient(NewClient);
			break;
		}

		case clsBankClient::eSaveResults::svFailedEmptyObject:
		{
			cout << "\nError. Account Was Not Saved Because It's Empty.\n";
			break;
		}

		case  clsBankClient::eSaveResults::svFailedAccountNumberExists:
		{
			cout << "\nAccount Already Exists.\n";
			break;
		}



		}

	}

};