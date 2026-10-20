#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

class clsLoginHistoryScreen : protected clsScreen
{
private:
	static void _PrintLoginUserRecord(clsUser::sLoginRegisterRecord LoginUser)
	{
		cout << setw(15) << left << "" << "| " << setw(25) << left << LoginUser.Date;
		cout << "| " << setw(20) << left << LoginUser.Username;
		cout << "| " << setw(20) << left << LoginUser.Password;
		cout << "| " << setw(10) << left << LoginUser.Permissions;
	}


public:

	static void ShowLoginHistoryList()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pLoginHistory))
		{
			return;		// It Will Exit The Function.
		}

		vector <clsUser::sLoginRegisterRecord> LoginsList = clsUser::GetLoginHistoryList();

		string Title = "\t Login History";
		string Subtitle = "\t (" + to_string(LoginsList.size()) + ") Login(s).";

		_DrawHeaderScreen(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(15) << left << "" << "| " << left << setw(25) << "Date";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (LoginsList.size() == 0)
			cout << "\n\t\t\t\tNo Logins Occurred In The System.";
		else
		{
			for (clsUser::sLoginRegisterRecord Log : LoginsList)
			{
				_PrintLoginUserRecord(Log);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}



};

