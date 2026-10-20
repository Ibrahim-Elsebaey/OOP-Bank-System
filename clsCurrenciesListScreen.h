#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;




class clsCurrenciesListScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(35) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}


public:

	static void ShowCurreniesList()
	{

		vector <clsCurrency> CurrenciesList = clsCurrency::GetCurrencyList();

		string Title = "\t Currencies List Screen";
		string Subtitle = "\t    (" + to_string(CurrenciesList.size()) + ") Client(s).";

		_DrawHeaderScreen(Title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(35) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (CurrenciesList.size() == 0)
			cout << "\n\t\t\t\tNo Currencies Available In The System.";
		else
		{
			for (clsCurrency Currency : CurrenciesList)
			{
				_PrintCurrencyRecord(Currency);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}










};

