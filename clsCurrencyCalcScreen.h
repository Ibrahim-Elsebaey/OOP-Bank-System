#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"


class clsCurrencyCalcScreen : protected clsScreen
{
private:
	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount To Exchange: ";
		Amount = clsInputValidate::ReadFltNumber();

		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
	
		string CurrencyCode = "";
		cout << Message << endl;


		cout << "\nEnter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Is Not Found, Choose Another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrency(clsCurrency Currency, string Title = "\nCurrency Card: ")
	{
		cout << Title << endl;
		cout << "\n______________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n______________________";
	}

	static void _PrintCalculationResults(float Amount, clsCurrency Currency1,
		clsCurrency Currency2)
	{
		_PrintCurrency(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << endl << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << "USD\n";
		
		if (Currency2.CurrencyCode() == "USD")
			return;

		cout << "\nConverting From USD To: \n";

		_PrintCurrency(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToAnotherCurrency(Amount, Currency2);

		cout << endl << Amount << " " << Currency1.CurrencyCode() << " = " <<
			AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}




public:
	static void ShowCalculationScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawHeaderScreen("\tCurrency Exchange Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nEnter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nEnter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo You Want To Perform Another Calculation y/n? ";
			cin >> Continue;
		}

	}










};

