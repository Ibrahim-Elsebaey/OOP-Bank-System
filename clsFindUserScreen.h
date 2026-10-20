#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n______________________";
		cout << "\nFirst Name  : " << User.FirstName;
		cout << "\nLast Name   : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUsername    : " << User.Username;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n______________________";
	}


public:
	static void ShowFindUserScreen()
	{
		_DrawHeaderScreen("\t Find User Screen");

		string Username = "";

		cout << "\nEnter Username: ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Is Not Found, Choose Another One: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);

		if (!User.IsEmpty())
			cout << "\nUser Found :)\n";
		else
			cout << "\nUser Was Not Found :(\n";

		_PrintUser(User);

	}


};

