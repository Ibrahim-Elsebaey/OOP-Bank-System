#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"


class clsCurrency
{
private:
	enum eMode
	{
		eEmptyMode,
		eUpdateMode
	};

	eMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector <string> CurrencyObject = clsString::Split(Line, Separator);

		return clsCurrency(eMode::eUpdateMode, CurrencyObject[0], CurrencyObject[1],
			CurrencyObject[2], stof(CurrencyObject[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency CurrencyObject, string Separator = "#//#")
	{
		string Line = "";

		Line += CurrencyObject.Country() + Separator;
		Line += CurrencyObject.CurrencyCode() + Separator;
		Line += CurrencyObject.CurrencyName() + Separator;
		Line += to_string(CurrencyObject.Rate()) + Separator;

		return Line;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> CurrencyList;

		fstream File;

		File.open("Currency.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrency CurrencyObject = _ConvertLineToCurrencyObject(Line);
				CurrencyList.push_back(CurrencyObject);
			}

			File.close();
		}

		return CurrencyList;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> CurrencyList)
	{
		fstream File;

		File.open("Currency.txt", ios::out);

		string DataLine;
		if (File.is_open())
		{
			for (clsCurrency C : CurrencyList)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				File << DataLine << endl;
			}
		}
	}

	void _Update()
	{
		vector <clsCurrency> CurrencyList;
		CurrencyList = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : CurrencyList)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(CurrencyList);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(eMode::eEmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(eMode Mode, string Country, string CurrencyCode,
		string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return(_Mode == eMode::eEmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();

	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllSentence(CurrencyCode);

		vector <clsCurrency> CurrencyList;
		CurrencyList = _LoadCurrencyDataFromFile();

		for (clsCurrency C : CurrencyList)
		{
			if (C.CurrencyCode() == CurrencyCode)
			{
				return C;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllSentence(Country);

		vector <clsCurrency> CurrencyList;
		CurrencyList = _LoadCurrencyDataFromFile();

		for (clsCurrency C : CurrencyList)
		{
			if (C.Country() == Country)
			{
				return C;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C = clsCurrency::FindByCode(CurrencyCode);

		return (!C.IsEmpty());
	}

	static vector <clsCurrency> GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)		// Non-Static To Use An Object.
	{
		return Amount / Rate();
	}

	float ConvertToAnotherCurrency(float Amount, clsCurrency Currency2)
	{
		float ResultInUSD = ConvertToUSD(Amount);
		
		if (Currency2.CurrencyCode() == "USD")
		{
			return ResultInUSD;
		}

		float Result = ResultInUSD * Currency2.Rate();

		return Result;
	}



};