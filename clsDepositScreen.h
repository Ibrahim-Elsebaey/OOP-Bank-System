#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"


class clsDepositScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nEnter Account Number: ";
		cin >> AccountNumber;

		return AccountNumber;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawHeaderScreen("\t   Deposit Screen");

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Not Found, Enter Another One: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nEnter Deposit Amount: ";
		float Amount = clsInputValidate::ReadFltNumber();

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Perform This Operation? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is " << Client.AccountBalance;

		}
		else
		{
			cout << "\nOperation Was Canceled.\n";
		}

	}


};

