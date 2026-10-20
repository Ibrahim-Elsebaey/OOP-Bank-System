#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginScreen.h"
#include "clsLoginHistoryScreen.h"
#include "clsCurrencyScreen.h"


using namespace std;

// Main Screen That Collects All Features In One Screen.

class clsMainScreen : protected clsScreen
{
private:
	enum eMainMenuOption
	{
		eListClients = 1,
		eAddNewClient = 2,
		eDeleteClient = 3,
		eUpdateClient = 4,
		eFindClient = 5,
		eShowTransactionsMenu = 6,
		eManageUsers = 7,
		eLoginHistory = 8,
		eCurrency = 9,
		eLogout = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose What You Want To Do? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number Between 1 And 9? ");

		return Choice;
	}


	static void _ShowAllClientsScreen()
	{
		//cout << "\nClients List Screen Will Be Here...\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "\nAdd New Client Screen Will Be Here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	
	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will Be Here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	
	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will Be Here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	
	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will Be Here...\n";
		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionScreen()
	{
		//cout << "\nTransactions Screen Will Be Here...\n";
		clsTransactionsScreen::ShowTransactionMenu();
	}
	
	static void _ShowManageUsersMenu()
	{
		//cout << "\nUsers List Screen Will Be Here...\n";
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginHistoryScreen()
	{
		//cout << "\nLogin History Will Be Here...";
		clsLoginHistoryScreen::ShowLoginHistoryList();
	}
	
	static void _ShowCurrencyScreen()
	{
		//cout << "--------------";
		clsCurrencyScreen::ShowCurrencyMenu();
	}

	static void _ShowLogoutScreen()
	{
		//cout << "\nLogout Screen Will Be Here...\n";
		
		CurrentUser = clsUser::Find("", ""); // It Will Finish The Program.
		//clsLoginScreen::ShowLoginScreen();	 // Error, Infinity Circle
	}


	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "\n\tPress Any Button To Go Back To Main Menu...";
	
		system("pause>0");
		ShowMainMenu();
	}

	static void _PerformMainMenuOption(eMainMenuOption Option)
	{
		switch (Option)
		{
		case eMainMenuOption::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		
		case eMainMenuOption::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case eMainMenuOption::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eMainMenuOption::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eMainMenuOption::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}

		case eMainMenuOption::eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionScreen();
			_GoBackToMainMenu();
			break;
		}
		
		case eMainMenuOption::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;
		}

		case eMainMenuOption::eLoginHistory:
		{
			system("cls");
			_ShowLoginHistoryScreen();
			_GoBackToMainMenu();
			break;
		}

		case eMainMenuOption::eCurrency:
		{
			system("cls");
			_ShowCurrencyScreen();
			_GoBackToMainMenu();
			break;
		}
		
		case eMainMenuOption::eLogout:
		{
			system("cls");
			_ShowLogoutScreen();
			break;
		}
		
		}

	}


public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawHeaderScreen("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login History.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOption(eMainMenuOption(_ReadMainMenuOption()));
	}





};

