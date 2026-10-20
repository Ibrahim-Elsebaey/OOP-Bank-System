#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"


class clsDeleteUserScreen : protected clsScreen
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

	static void ShowDeleteUserScreen()
	{

		_DrawHeaderScreen("\t Delete User Screen");

		string Username = "";

		cout << "\nEnter Username: ";
		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Is Not Found, Choose Another One: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);

		_PrintUser(User);

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Delete This User? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully.";
				_PrintUser(User);
			}
			else
			{
				cout << "\nUser Was Not Deleted";
			}
		}
	}
};

