#pragma once

#include <iostream>
#include <string>

#include "clsDate.h"

class clsInputValidate
{
public:
	static bool IsNumberBetween(int Num, int Start, int End)
	{
		if (Num >= Start && Num <= End)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Num, double Start, double End)
	{
		if (Num >= Start && Num <= End)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(float Num, float Start, float End)
	{
		if (Num >= Start && Num <= End)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate Start, clsDate End)
	{
		if (
			(clsDate::IsDate1AfterDate2(Date, Start) || clsDate::IsDatesEqual(Date, Start))
			&&
			(clsDate::IsDate1BeforeDate2(Date, End) || clsDate::IsDatesEqual(Date, End))
			)
		{
			return true;
		}
	}
	

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, EnterAgain\n")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;

		}

		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, EnterAgain\n")
	{
		short Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;

		}

		return Number;
	}


	static int ReadFltNumber(string ErrorMessage = "Invalid Number, EnterAgain\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;

		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, EnterAgain\n")
	{
		double Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;

		}

		return Number;
	}


	static int ReadIntNumberBetween(int Start, int End, string ErrorMessage = "Number Isn't Within Range, EnterAgain\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, Start, End))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static float ReadFltNumberBetween(float Start, float End, string ErrorMessage = "Number Isn't Within Range, EnterAgain\n")
	{
		float Number = ReadFltNumber();

		while (!IsNumberBetween(Number, Start, End))
		{
			cout << ErrorMessage;
			Number = ReadFltNumber();
		}

		return Number;
	}


	static double ReadDblNumberBetween(double Start, double End, string ErrorMessage = "Number Isn't Within Range, EnterAgain\n")
	{
		double Number = ReadIntNumber();

		while (!IsNumberBetween(Number, Start, End))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static short ReadShortNumberBetween(int Start, int End, string ErrorMessage = "Number Isn't Within Range, EnterAgain\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, Start, End))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}

		return Number;
	}




	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S = "";

		getline(cin >> ws, S);
		return S;;
	}

};