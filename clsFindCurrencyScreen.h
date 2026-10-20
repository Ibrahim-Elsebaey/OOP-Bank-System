#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n______________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n______________________";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\Currency Found :)\n";
			_PrintCurrency(Currency);
		}

		else
			cout << "\nCurrency Was Not Found :(\n";

	}


public:
	static void ShowFindCurrencyScreen()
	{
		_DrawHeaderScreen("\t Find Currency Screen");

		int num = 0;
		cout << "\nFind By: [1] Code Or [2] Country ? ";
		num = clsInputValidate::ReadIntNumber();
				
		if (num == 1)
		{
			string Code = "";
			cout << "Enter Currency Code: ";
			Code = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(Code);
			_ShowResults(Currency);
		}

		if (num == 2)
		{
			string Country = "";
			cout << "Enter Country Name: ";
			Country = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}


};

