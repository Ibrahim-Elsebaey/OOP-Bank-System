#pragma once
#include <iostream>
#include <vector>
using namespace std;



class clsString
{
private:

	string _Value = "";


public:
	clsString()	// To Not Get An Error If I Didn't Pass Parameters Or I Have A Value Already
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void setValue(string Value)
	{
		_Value = Value;
	}

	string getValue()
	{
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	// Length

	static short Length(string Sentence)
	{
		return Sentence.length();
	}
	short Length()
	{
		return _Value.length();
	}


	// Count Words
	static short CountWords(string Sentence)	// To Access Without An Object From Anywhere.
	{
		short pos = 0, counter = 0;
		string Delim = " ";
		string Word = "";
		while ((pos = Sentence.find(Delim)) != string::npos)
		{
			Word = Sentence.substr(0, pos);
			if (Word != "")
			{
				counter++;
			}
			Sentence.erase(0, pos + Delim.length());
		}

		if (Sentence != "")
			counter++;

		return counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}


	// Lower First Letter
	static string LowercaseFirstLetter(string Sentence)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < Sentence.length(); i++)
		{
			// If Letter Isn't Empty And The Previous One Is.
			if (Sentence[i] != ' ' && IsFirstLetter)
			{
				Sentence[i] = tolower(Sentence[i]);
			}

			IsFirstLetter = (Sentence[i] == ' ') ? true : false;
		}

		return Sentence;
	}
	string LowercaseFirstLetter()
	{
		return LowercaseFirstLetter(_Value);
	}


	// Upper All Sentence
	static string UpperAllSentence(string Sentence)
	{
		for (int i = 0; i < Sentence.length(); i++)
		{
			Sentence[i] = toupper(Sentence[i]);
		}

		return Sentence;
	}
	string UpperAllSentence()
	{
		return UpperAllSentence(_Value);
	}


	// Lower All Sentence
	static string LowerAllSentence(string Sentence)
	{
		for (int i = 0; i < Sentence.length(); i++)
		{
			Sentence[i] = tolower(Sentence[i]);
		}

		return Sentence;
	}
	string LowerAllSentence()
	{
		return LowerAllSentence(_Value);
	}


	// Count Capital Letters
	static short CountCapitalLetters(string Sentence)
	{
		short Count = 0;

		for (int i = 0; i < Sentence.length(); i++)
		{
			if (isupper(Sentence[i]))
				Count++;
		}

		return Count;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}


	// Count Small Letters
	static short CountSmallLetters(string Sentence)
	{
		short Count = 0;

		for (int i = 0; i < Sentence.length(); i++)
		{
			if (islower(Sentence[i]))
				Count++;
		}

		return Count;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}


	// Trim 
	static string TrimLeft(string Sentence)
	{
		string Delim = " ";

		for (int i = 0; i < Sentence.length(); i++)
		{
			if (Sentence[i] != ' ')
				return Sentence.substr(i, Sentence.length());
		}
	}
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	static string TrimRight(string Sentence)
	{
		string Delim = " ";

		for (int i = Sentence.length() - 1; i >= 0; i--)
		{
			if (Sentence[i] != ' ')
			{
				return Sentence.substr(0, i + 1);	// To Get The Last Letter.
			}
		}
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}

	static string Trim(string Sentence)
	{
		return TrimLeft(TrimRight(Sentence));
	}
	string Trim()
	{
		return Trim(_Value);
	}


	// Is The Letter Vower
	static bool IsVowel(char Character)
	{
		Character = tolower(Character);

		return (Character == 'a' || Character == 'e' || Character == 'i' || Character == 'o' || Character == 'u');
	}


	// Count Vowels
	static short CountVowels(string Sentence)
	{
		short counter = 0;
		for (int i = 0; i < Sentence.length(); i++)
		{
			if (IsVowel(Sentence[i]))
				counter++;
		}

		return counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}


	// Split String
	static vector <string> Split(string Sentence, string Delim)
	{
		short pos = 0;
		string Word = "";

		vector <string> vString;

		while ((pos = Sentence.find(Delim)) != string::npos)
		{
			Word = Sentence.substr(0, pos);

			if (Word != "")
				vString.push_back(Word);

			Sentence.erase(0, pos + Delim.length());
		}

		if (Sentence != "")
			vString.push_back(Sentence);

		return vString;
	}

	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}















};

