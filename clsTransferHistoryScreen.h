#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"

using namespace std;


class clsTransferHistoryScreen : protected clsScreen
{
private:
	static void _PrintTransferRecord(clsBankClient::sTransferRecord Record)
	{
		cout << setw(8) << left << "" << "| " << setw(20) << left << Record.Date;
		cout << "| " << setw(11) << left << Record.SourceAccount;
		cout << "| " << setw(11) << left << Record.DestinationAccount;
		cout << "| " << setw(11) << left << Record.Amount;
		cout << "| " << setw(11) << left << Record.srcAccountBalance;
		cout << "| " << setw(11) << left << Record.deAccountBalance;
		cout << "| " << setw(8) << left << Record.Username;
	}


public:

	static void ShowTransferHistoryScreen()
	{
		vector <clsBankClient::sTransferRecord> TransferHistory;
		TransferHistory = clsBankClient::GetTransferHistory();

		string Title = "\t Transfer History Screen";
		string Subtitle = "\t    (" + to_string(TransferHistory.size()) + ") Client(s).";

		_DrawHeaderScreen(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(8) << "Src Account";
		cout << "| " << left << setw(8) << "Des Account";
		cout << "| " << left << setw(11) << "Amount";
		cout << "| " << left << setw(10) << "Src Balance";
		cout << "| " << left << setw(10) << "Des Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (TransferHistory.size() == 0)
			cout << "\n\t\t\t\tNo Clients Available In The System.";
		else
		{
			for (clsBankClient::sTransferRecord Record : TransferHistory)
			{
				_PrintTransferRecord(Record);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
	

};

