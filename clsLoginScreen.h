#pragma once
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFailed = false;
		short LoginFailedCount = 0;

		string Username, Password;

		do
		{
			if (LoginFailed)		// if true
			{
				LoginFailedCount++;

				cout << "\nInvalid Username/Password.\n";
				cout << "\nYou Have " << (3 - LoginFailedCount) << " Trial(s) To Login.\n\n";

			}

			if (LoginFailedCount == 3)
			{
				cout << "\nYou're Locked After 3 Failed Trials\n\n";
				return false;
			}


			cout << "Enter Username: ";
			cin >> Username;
			
			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();
		
		} while (LoginFailed);		//while true

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenu();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t  Login Screen");
		return _Login();

	}

};

