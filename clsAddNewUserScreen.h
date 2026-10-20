#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;


class clsAddNewUserScreen : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}

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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            Permissions += clsUser::ePermissions::pListClients;
        }


        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::ePermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::ePermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::ePermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::ePermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::ePermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::ePermissions::pManageUsers;
        }

		cout << "\nShow Login History? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::ePermissions::pLoginHistory;
		}

		cout << "\nCurrency Exchange? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::ePermissions::eCurrency;
		}


        return Permissions;

    }


public:
	static void ShowAddNewClientScreen()
	{
		_DrawHeaderScreen("\t  Add New User Screen");

		string Username = "";

		cout << "\nEnter Username: ";
		Username = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Is Already Used, Choose Another One: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(Username);

		_ReadUserInfo(NewUser);

		clsUser::eSaveResult SaveResults;

		SaveResults = NewUser.Save();

		switch (SaveResults)
		{
		case clsUser::eSaveResult::svSucceeded:
		{
			cout << "\nUser Added Successfully :)\n";
			_PrintUser(NewUser);
			break;
		}

		case clsUser::eSaveResult::svFailedEmptyObject:
		{
			cout << "\nError. User Was Not Saved Because It's Empty.\n";
			break;
		}

		case  clsUser::eSaveResult::svFailedUserExists:
		{
			cout << "\nAccount Already Exists.\n";
			break;
		}



		}

	}



};

