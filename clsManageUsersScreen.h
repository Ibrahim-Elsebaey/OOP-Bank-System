#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUser.h"


using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
	enum eManageUsersMenu
	{
		eListUsers = 1,
		eAddNewUser = 2,
		eDeleteUser = 3,
		eUpdateUser = 4,
		eFindUser = 5,
		eMainMenu = 6
	};

    static short _ReadManageUsersOption()
    {
        cout << setw(37) << left << "" << "Choose What You Want To Do? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 And 6? ");

        return Choice;
    }

	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Screen Will Be Here...";
		clsUsersListScreen::ShowClientsList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Screen Will Be Here...";
		clsAddNewUserScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here...";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen Will Be Here...";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here...";
		clsFindUserScreen::ShowFindUserScreen();
		
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "\n\tPress Any Button To Go Back To Main Menu...";
		
		system("pause>0");
		ShowManageUsersScreen();

	}

	static void _PerformManageUsersOption(eManageUsersMenu Option)
	{
		switch (Option)
		{
		case eManageUsersMenu::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eManageUsersMenu::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
			
		case eManageUsersMenu::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eManageUsersMenu::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eManageUsersMenu::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}

		case eManageUsersMenu::eMainMenu :
		{

		}

		}
	}


public:

	static void ShowManageUsersScreen()
	{

		if (!CheckAccessRights(clsUser::ePermissions::pManageUsers))
		{
			return;		// It Will Exit The Function.
		}

		system("cls");
		_DrawHeaderScreen("\t    Manage Users Menu");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersOption(eManageUsersMenu(_ReadManageUsersOption()));
	}

};


