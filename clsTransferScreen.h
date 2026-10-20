#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n______________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc Number  : " << Client.AccountNumber();
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


	static void ShowTransferScreen()
	{


		_DrawHeaderScreen("\tTransfer Screen");

		clsBankClient FromClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(FromClient);

		clsBankClient ToClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(ToClient);

		int Amount = 0;
		cout << "\nEnter Amount You Want To Transfer: ";
		cin >> Amount;

		char A = 'n';
		cout << "Are You Sure You Want To Pefrorm This Operation? ";
		cin >> A;

		if (A == 'y' || A == 'Y')
		{
			if (FromClient.Transfer(Amount, ToClient, CurrentUser.Username))
			{
				cout << "\nAmount Transfered Successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed\n";
			}

		}

		_PrintClient(FromClient);
		_PrintClient(ToClient);

	}

};

