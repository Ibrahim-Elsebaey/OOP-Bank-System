#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include "clsDate.h"


class clsUtil
{
public:

	enum enCharType { SmallLitter = 1, CapitalLitter, SpecialSign, Digit }; // Nothing starts with 0
	
	static void Rand()
	{
		rand();
	}

	static int RandomNumber(int From, int To)
	{
		int RandomNum = rand() % (To - From + 1) + From;

		return RandomNum;
	}

	static char GetRandomCharacter(enCharType TheValue)  // If I Made It Int Not Char, It Prints Numbers
	{
		switch (TheValue)
		{
		case enCharType::SmallLitter:  // I can put 1 instead of "enCharType::SmallLitter",but not technical
			return RandomNumber(97, 122);	// Put Char(Function).But Not Necessary Cuz Returned Value Is Char
			break;

		case enCharType::CapitalLitter:
			return RandomNumber(65, 90);
			break;

		case enCharType::SpecialSign:
			return RandomNumber(33, 47);
			break;

		case enCharType::Digit:
			return RandomNumber(48, 57);
			break;
		}

		return '\0';	// If An Invalid Type Is Passed, Return Null Character
	}

	static string GenerateOneKey(enCharType Type, short LengthofWord)
	{
		string Word = "";
		for (int i = 1; i <= LengthofWord; i++)
		{
			Word += GetRandomCharacter(Type);
		}
		return Word;
	}

	static string GenerateKeys()
	{
		string Keys = GenerateOneKey(enCharType::CapitalLitter, 4) + "-";
		Keys += GenerateOneKey(enCharType::CapitalLitter, 4) + "-";
		Keys += GenerateOneKey(enCharType::CapitalLitter, 4) + "-";
		Keys += GenerateOneKey(enCharType::CapitalLitter, 4);

		return Keys;
	}

	static void PrintArray23(int Array23[100], int NumberofElements)
	{
		cout << "Original Array: ";
		for (int i = 0; i < NumberofElements; i++)
		{
			cout << Array23[i] << "  ";
		}
		cout << endl;
	}

	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(bool& A, bool& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	
	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static void ShuffleArray(int Array31[100], int Number)
	{
		for (int i = 0; i < Number; i++)
		{	// صياعة
			Swap(Array31[RandomNumber(1, Number) - 1], Array31[RandomNumber(1, Number) - 1]);
		}
	}
	
	static void ShuffleArray(string Array31[100], int Number)
	{
		for (int i = 0; i < Number; i++)
		{	// صياعة
			Swap(Array31[RandomNumber(1, Number) - 1], Array31[RandomNumber(1, Number) - 1]);
		}
	}

	static short FindSearchNumberinArray(int Array[100], int NumberofElements, int SearchNumber)
	{
		for (int i = 0; i < NumberofElements; i++)
		{
			if (SearchNumber == Array[i])
				return i;
		}
		return -1;
	}

	static string EncryptWord(string Word, int EncryptionKey = 2)
	{
		for (int i = 0; i <= Word.length(); i++)
		{
			Word[i] = char(Word[i] + EncryptionKey);
		}
		return Word;
	}

	static string DecryptWord(string EncWord, int EncryptionKey = 2)
	{
		for (int i = 0; i <= EncWord.length(); i++)
		{
			EncWord[i] = char(EncWord[i] - EncryptionKey);
		}
		return EncWord;
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







};