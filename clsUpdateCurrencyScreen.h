#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;


class clsUpdateCurrencyScreen : protected clsScreen
{
private:

	static float _ReadRate()
	{
		float NewRate = 0;
		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate::ReadFltNumber();

		return NewRate;
	}

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


public:

    static void ShowUpdateCurrencyScreen()
    {
        _DrawHeaderScreen("\tUpdate Currency Rate Screen");

        string CurrencyCode = "";

        cout << "\nEnter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Is Not Found, Choose Another One: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\nAre You Sure You Want To Update This Currency Rate? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nUpdate Currency Rate Info: ";
            cout << "\n______________________";

            Currency.UpdateRate(_ReadRate());
            cout << "\nCurrency Rate Updated Successfully.";
            _PrintCurrency(Currency);
        }

    }




};

