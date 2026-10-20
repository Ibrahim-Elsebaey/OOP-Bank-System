#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:
	static void _PrintUserRecord(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(10) << left << User.Username;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
	}

public:
	

	static void ShowClientsList()
	{
		vector <clsUser> UsersList = clsUser::GetUsersList();

		string Title = "\t Users List Screen";
		string Subtitle = "\t    (" + to_string(UsersList.size()) + ") User(s).";

		_DrawHeaderScreen(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(10) << "Username";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (UsersList.size() == 0)
			cout << "\n\t\t\t\tNo Users Available In The System.";
		else
		{
			for (clsUser User : UsersList)
			{
				_PrintUserRecord(User);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

