#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "clsString.h"

class clsDate
{

private:
	int _Day = 1;
	int _Month = 1;
	int _Year = 1900;


public:
	// We Made The All Structures clsDate


	// Constructs
	clsDate()
	{ 
		time_t now = time(0);
		tm tm;
		localtime_s(&tm, &now);

		_Year = tm.tm_year + 1900;
		_Month = tm.tm_mon + 1;
		_Day = tm.tm_mday;

	}

	clsDate(string Date)
	{
		vector <string> vDate;

		vDate = clsString::Split(Date, "/");
	
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(int TotalDays, int Year)
	{
		clsDate Date = GetDateByTotalDays(TotalDays, Year);
	
		_Day = Date.Day;		// We Did It By The Dots Thanks To __declspec
		_Month = Date.Month;
		_Year = Date.Year;
	}

	clsDate(int Day, int Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	
	// set And get
	void setDay(int Day)
	{
		_Day = Day;
	}

	int getDay()
	{
		return _Day;
	}

	__declspec(property(get = getDay, put = setDay)) int Day;	// Be Careful With get And put


	void setMonth(int Month)
	{
		_Month = Month;
	}

	int getMonth()
	{
		return _Month;
	}

	__declspec(property(get = getMonth, put = setMonth)) int Month;


	void setYear(int Year)
	{
		_Year = Year;
	}

	int getYear()
	{
		return _Year;
	}

	__declspec(property(get = getYear, put = setYear)) int Year;


	// Method Members
	
	void Print()
	{
		cout << DateToString() << endl;
	}
	
	static clsDate GetSystemDate()
	{
		time_t now = time(0);
		tm tm;
		localtime_s(&tm, &now);

		int Day, Month, Year;

		Year = tm.tm_year + 1900;
		Month = tm.tm_mon + 1;
		Day = tm.tm_mday;

		return clsDate(Day, Month, Year);
	}
	
	static string GetSystemDateTimeString()
	{
		time_t now = time(0);
		tm tm;
		localtime_s(&tm, &now);

		int Second, Minute, Hour, Day, Month, Year;

		Year = tm.tm_year + 1900;
		Month = tm.tm_mon + 1;
		Day = tm.tm_mday;
		Hour = tm.tm_hour;
		Minute = tm.tm_min;
		Second = tm.tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year)
			+ " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
	}


	static string DateToString(clsDate Date, string Separator = "/")
	{
		string StringDate = "";

		StringDate += to_string(Date.Day) + Separator;
		StringDate += to_string(Date.Month) + Separator;
		StringDate += to_string(Date.Year);

		return StringDate;
	}

	string DateToString()
	{
		return DateToString(*this);	// The Current Object
	}


	static bool IsLeapYear(int Year)
	{
		if (Year % 400 == 0)
		{
			return true;
		}

		if (Year % 4 == 0)
		{
			return true;
		}

		if (Year % 100 == 0)
		{
			return false;
		}

		else
		{
			return false;
		}
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}


	static bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Day <= Date.DaysInMonth(Date.Year, Date.Month))
		{
			return true;
		}

		return false;
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}


	int DaysInMonth(int Year, int Month)
	{
		if (Month == 2)
		{
			if (IsLeapYear(Year))
				return 29;
			else
				return 28;
		}

		int Arr31Days[12] = { 0, 1, 3, 5, 7, 8, 10, 12 };

		for (int i = 1; i <= 12; i++)
		{
			if (Month == Arr31Days[i])
			{
				return 31;
			}
		}

		return 30;
	}


	clsDate GetDateByTotalDays(int TotalDays, int Year)
	{
		clsDate Date;
		int MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = DaysInMonth(Date.Year, Date.Month);

			if (TotalDays > MonthDays)
			{
				TotalDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = TotalDays;
				break;
			}
		}

		return Date;
	}


	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "Zero";
		}

		// Enjoy The Magic Of Recursion.

		if (Number >= 1 && Number <= 19)
		{
			string Arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
			"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
			"Eighteen", "Nineteen" };

			return Arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string Arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
				"Eighty", "Ninety" };

			return Arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 999)
		{
			string Arr[] = { "", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred",
				"Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred" };

			return Arr[Number / 100] + " " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 9999999)
		{
			return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
		}

		else
		{
			return Number + "Is More That 9,999,999";
		}
	}



	static int CalculateTheDayName(int Year, int Month, int Day)
	{
		int a = (14 - Month) / 12;

		int y = Year - a;
		int m = Month + (12 * a) - 2;

		int Result = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return Result;

	}

	string GetMonthName(int Month)
	{
		string Arr12Months[13] = { "", "Jan", "Feb", "Mars", "Apr", "May", "Jun", "Jul",
									"Aug", "Sep", "Oct", "Nov", "Dec" };

		return Arr12Months[Month];
	}

	static string GetTheDayName(int Year, int Month, int Day)
	{
		string ArrDaysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return ArrDaysName[CalculateTheDayName(Year, Month, Day)];
	}


	static void PrintMonthCalendar(int Year, int Month)
	{
		clsDate Date;
		// Current = Number Of The Day	(Sun = 0, Mon = 1)	0 to 6
		int Current = Date.CalculateTheDayName(Year, Month, 1);

		// NumberOfDays = How Many Days In This Month	(3 = 31, 4 = 30)
		int NumberOfDays = Date.DaysInMonth(Year, Month);

		// Print The Month Name
		printf("\n ______________ %s _______________\n\n", Date.GetMonthName(Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < Current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}


		printf("\n __________________________________\n");
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Year, _Month);
	}


	static void PrintAllYearCalendar(int Year)
	{
		printf("____________________________\n\n");
		printf("\tCalender - %i\n", Year);
		printf("____________________________\n\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
		}
	}

	void PrintAllYearCalendar()
	{
		PrintAllYearCalendar(_Year);
	}


	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return
			(Date1.Year < Date2.Year) ? true :
			((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
				(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1.Year > Date2.Year)
		{
			return true;
		}
		else if (Date1.Year == Date2.Year && Date1.Month > Date2.Month)
		{
			return true;
		}
		else if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day > Date2.Day)
		{
			return true;
		}

		return false;
	}

	static bool IsDatesEqual(clsDate Date1, clsDate Date2)
	{
		if (Date1.Year == Date2.Year)
		{
			if (Date1.Month == Date2.Month)
			{
				if (Date1.Day == Date2.Day)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
		{
			return false;
		}
	}


	// Just Like That.
};

