#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"
#include "clsUser.h"

using namespace std;

// This Is The Common Screen Between All Screens.

class clsScreen
{
protected:
	static void _DrawHeaderScreen(string Title, string Subtitle = "")
	{
		cout << "\t\t\t\t\t_______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (Subtitle != "")
		{
			cout << "\n\t\t\t\t\t" << Subtitle;
		}
		cout << "\n\t\t\t\t\t_______________________________________\n";


		clsDate Date = clsDate::GetSystemDate();
		string NowDate = clsDate::DateToString(Date);

		cout << "\n\t\t\t\t\tUser: " << CurrentUser.Username;
		cout << "\n\t\t\t\t\tDate: " << NowDate << "\n\n";

	}

	static bool CheckAccessRights(clsUser::ePermissions Permission)
	{

		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t_______________________________________";
			cout << "\n\n\t\t\t\t\t Access Denied! Contact Your Admin.";
			cout << "\n\t\t\t\t\t_______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}

	}


};

