#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsBankClient.h"


class clsTotalBalanceScreen : protected clsScreen
{
private:
	static void _PrintClientRecordBalance(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		vector <clsBankClient> ClientsList = clsBankClient::GetClientsList();

		string Title = "\t  Balances List Screen";
		string Subtitle = "\t    (" + to_string(ClientsList.size()) + ") Clients";

		_DrawHeaderScreen(Title, Subtitle);

		cout << setw(25) << left << "" <<  
			"\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" <<
			"\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (ClientsList.size() == 0)
		{
			cout << "\n\t\t\t\tNo Clients Available In The System.";
		}
		else
		{
			for (clsBankClient C : ClientsList)
			{
				_PrintClientRecordBalance(C);
				cout << endl;
			}
		}

		cout << setw(25) << left << "" <<
			"\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalance = clsBankClient::GetTotalBalance();

		cout << "\t\t\t\tTotal Balance = " << TotalBalance;
		cout << "\n\t\t\t\t(" << clsUtil::NumberToText(TotalBalance) << ")";


	}



};

