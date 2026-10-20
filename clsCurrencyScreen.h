#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalcScreen.h"


using namespace std;


class clsCurrencyScreen : protected clsScreen
{
private:
	enum eCurrency
	{
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalc = 4,
		eMainMenu = 5
	};

	static short _ReadCurrencyMenuOption()
	{
		cout << setw(37) << left << "" << "Choose What You Want To Do? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 And 5? ");

		return Choice;
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout << "\nCurrencies List Will Be Here...";
		clsCurrenciesListScreen::ShowCurreniesList();

	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Will Be Here...";

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate Will Be Here...";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Will Be Here...";
		clsCurrencyCalcScreen::ShowCalculationScreen();
	}


	static void _ShowCurrencyMenuScreen()
	{
		cout << "\nShow Currency Menu Will Be Here...";
	}


	static void _GoBackToCurrencyMenu()
	{
		cout << setw(37) << left << "\n\tPress Any Button To Go Back To Main Menu...";

		system("pause>0");
		ShowCurrencyMenu();
	}


	static void _PerformCurrencyMenuOption(eCurrency Option)
	{
		switch (Option)
		{
		case eCurrency::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case eCurrency::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case eCurrency::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case eCurrency::eCurrencyCalc:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case eCurrency::eMainMenu:
		{
			
		}

		}

	}



public:

	static void ShowCurrencyMenu()
	{
		if (!CheckAccessRights(clsUser::ePermissions::eCurrency))
		{
			return;		// It Will Exit The Function.
		}

		system("cls");
		_DrawHeaderScreen("\t\Currency Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenuOption(eCurrency(_ReadCurrencyMenuOption()));
	}


















};

