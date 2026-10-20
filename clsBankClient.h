#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"

// This Is The Class That Contains The Features (Without UI)
// Every Layer Has A Class

	//  This Is The Logic Layer

class clsBankClient : public clsPerson
{

private:
	enum eMode {EmptyMode, UpdateMode, AddNewMode};
	eMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;


	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Separator);

		return clsBankClient(eMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], clsUtil::DecryptWord(vClientData[5]), stof(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(eMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone+ Separator;
		Line += Client.AccountNumber() + Separator;
		Line += clsUtil::EncryptWord(Client.PinCode) + Separator;
		Line += to_string(Client.AccountBalance);
		
		return Line;
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> ClientsList;

		fstream MyFile;

		MyFile.open("Bank-Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				ClientsList.push_back(Client);
			}

			MyFile.close();
		}

		return ClientsList;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> ClientsList)
	{
		fstream MyFile;

		MyFile.open("Bank-Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient& C : ClientsList)
			{
				if (C.MarkForDelete() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
		}
	}

	// Focus On This Function And Look At It Many Times.
	void _Update()
	{
		vector <clsBankClient> _ClientsList;
		_ClientsList = _LoadClientsDataFromFile();

		for (clsBankClient& C : _ClientsList)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;		// The Client From The File = The Current Object (Updated)
				break;
			}
		}

		_SaveClientsDataToFile(_ClientsList);
	}	  
	
	void _AddDataLineToFile(string Line)
	{
		fstream File;

		File.open("Bank-Clients.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << Line << endl;
			File.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _ConvertTransferRecordToLine(int Amount, clsBankClient ToClient,
		string Username, string Separator = "#//#")
	{
		string TransferLine = "";

		TransferLine += clsDate::GetSystemDateTimeString() + Separator;
		TransferLine += AccountNumber() + Separator;	// *this.AccountNumber()
		TransferLine += ToClient.AccountNumber() + Separator;
		TransferLine += to_string(Amount) + Separator;
		TransferLine += to_string(AccountBalance) + Separator;
		TransferLine += to_string(ToClient.AccountBalance) + Separator;
		TransferLine += Username;

		return TransferLine;
	}


	void _SaveTransferLineToFile(int Amount, clsBankClient ToClient, string Username)
	{
		string TransferLine = _ConvertTransferRecordToLine(Amount, ToClient, Username);

		fstream File;

		File.open("TransferHistory.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << TransferLine << endl;
			File.close();
		}
	}

	struct sTransferRecord;
	static sTransferRecord _ConvertTransferLineToRecord(string Line, string Sep = "#//#")
	{
		vector <string> vTransferData = clsString::Split(Line, Sep);

		sTransferRecord TransferRecord;

		TransferRecord.Date = vTransferData[0];
		TransferRecord.SourceAccount = vTransferData[1];
		TransferRecord.DestinationAccount = vTransferData[2];
		TransferRecord.Amount = stoi(vTransferData[3]);
		TransferRecord.srcAccountBalance = stoi(vTransferData[4]);
		TransferRecord.deAccountBalance= stoi(vTransferData[5]);
		TransferRecord.Username = vTransferData[6];


		return TransferRecord;
	}

	static vector <sTransferRecord> _LoadTransferRecordsFromFile()
	{
		vector <sTransferRecord> TransferHistory;

		fstream File;

		File.open("TransferHistory.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				sTransferRecord TransferRecord = _ConvertTransferLineToRecord(Line);
				TransferHistory.push_back(TransferRecord);
			}

			File.close();
		}


		return TransferHistory;
	}



public:

	clsBankClient(eMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == eMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string getPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;


	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float getAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}


	//void Print()		// No UI Code Related To Object Class
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n______________________";
	//	cout << "\nFirst Name  : " << FirstName;
	//	cout << "\nLast Name   : " << LastName;
	//	cout << "\nFull Name   : " << FullName();
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc Number  : " << _AccountNumber;
	//	cout << "\nPin Code    : " << _PinCode;
	//	cout << "\nAcc Balance : " << _AccountBalance;
	//	cout << "\n______________________";
	//}

	static clsBankClient Find(string AccountNumber)
	{
		fstream File;

		File.open("Bank-Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					File.close();
					return Client;
				}
			}
			File.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream File;

		File.open("Bank-Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					File.close();
					return Client;
				}

				vClients.push_back(Client);
			}
			File.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return !(Client.IsEmpty());
	}

	/*
	Look How It Works In OOP 'Think From The CPP File:			(About Find)
		1 - We Need To Find A Client By His AccountNumber (Will Be Passed As A Parameter).
		2 - So, We Will Make Find() And It Returns A Client.
		3 - We'll Need To Read Every Single Line In The File.
		4 - We Need To Return This Line Into A Client.
		5 - This Line Needs To Get Splited.
	*/

	enum eSaveResults {svFailedEmptyObject, svSucceeded, svFailedAccountNumberExists};

	eSaveResults Save()
	{
		switch (_Mode)
		{
		case eMode::EmptyMode:
		{
			return eSaveResults::svFailedEmptyObject;
		}

		case eMode::UpdateMode:
		{
			_Update();
			return eSaveResults::svSucceeded;
		}

		case eMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return eSaveResults::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = eMode::UpdateMode;
				return eSaveResults::svSucceeded;
			}
		}
		
		}

	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(eMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _ClientsList;
		_ClientsList = _LoadClientsDataFromFile();

		for (clsBankClient& C : _ClientsList)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_ClientsList);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalance()
	{
		vector <clsBankClient> ClientsList = GetClientsList();
		float TotalBalance = 0;

		for (clsBankClient C : ClientsList)
		{
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(float Amount)
	{
		if (_AccountBalance < Amount)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		
	}

	bool Transfer(int Amount, clsBankClient& DestinationClient, string Username)
	{
		if (_AccountBalance < Amount)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_SaveTransferLineToFile(Amount, DestinationClient, Username);
		return true;
	}

	struct sTransferRecord
	{
		string Date;
		string SourceAccount;
		string DestinationAccount;
		int Amount;
		int srcAccountBalance;
		int deAccountBalance;
		string Username;
	};

	static vector <sTransferRecord> GetTransferHistory()
	{
		return _LoadTransferRecordsFromFile();
	}



};


