#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"

using namespace std;


// Client List Screen (Screen Of The First Feature)

class clsClientListScreen : protected clsScreen
{
private:
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pListClients))
		{
			return;		// It Will Exit The Function.
		}

		vector <clsBankClient> ClientsList = clsBankClient::GetClientsList();

		string Title = "\t Client List Screen";
		string Subtitle = "\t    (" + to_string(ClientsList.size()) + ") Client(s).";

		_DrawHeaderScreen(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (ClientsList.size() == 0)
			cout << "\n\t\t\t\tNo Clients Available In The System.";
		else
		{
			for (clsBankClient Client : ClientsList)
			{
				_PrintClientRecord(Client);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

