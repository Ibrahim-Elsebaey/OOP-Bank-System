#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawHeaderScreen("\t   Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Not Found, Enter Another One: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nEnter Withdraw Amount: ";
		float Amount = clsInputValidate::ReadFltNumber();

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Perform This Operation? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrawed Successfully.\n";
				cout << "\nNew Balance Is " << Client.AccountBalance;
			}
			else
			{
				cout << "\nSorry, Withdrawed Amount Is Bigger That Your Balance.\n";
				cout << "\nAmount To Withdraw = " << Amount; 
				cout << "\nYour Balance = " << Client.AccountBalance;
			}

			

		}
		else
		{
			cout << "\nOperation Was Canceled.\n";
		}

	}

};

