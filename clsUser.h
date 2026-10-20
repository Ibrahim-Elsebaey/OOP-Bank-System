#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "Global.h"
#include "clsDate.h"
#include "clsUtil.h"


using namespace std;

class clsUser : public clsPerson
{
private:
	enum eMode
	{
		EmptyMode,
		UpdateMode,
		AddNewMode
	};

	eMode _Mode;
	string _Username;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;


	static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
	{
		vector <string> UserData;
		UserData = clsString::Split(Line, Separator);

		return
			clsUser(eMode::UpdateMode, UserData[0], UserData[1], UserData[2], UserData[3],
				UserData[4], clsUtil::DecryptWord(UserData[5]), stoi(UserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
	{
		string Line = "";

		Line += User.FirstName + Separator;
		Line += User.LastName + Separator;
		Line += User.Email + Separator;
		Line += User.Phone + Separator;
		Line += User.Username + Separator;
		Line += clsUtil::EncryptWord(User.Password) + Separator;
		Line += to_string(User.Permissions);

		return Line;
	}

	static vector <clsUser> _LoadUserDataFromFile()
	{
		vector <clsUser> UsersList;

		fstream File;

		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				UsersList.push_back(User);
			}

			File.close();
		}

		return UsersList;
	}

	static void _SaveUserDataToFile(vector <clsUser> UsersList)
	{
		fstream File;

		File.open("Users.txt", ios::out);

		string DataLine;
		if (File.is_open())
		{
			for (clsUser& User : UsersList)
			{
				if (User._MarkForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(User);
					File << DataLine << endl;
				}
			}
		}
	}

	void _Update()
	{
		vector <clsUser> UsersList;
		UsersList = _LoadUserDataFromFile();

		for (clsUser& User : UsersList)
		{
			if (User.Username == _Username)
			{
				User = *this;
				break;
			}
		}

		_SaveUserDataToFile(UsersList);
	}

	void _AddDataLineToFile(string Line)
	{
		fstream File;

		File.open("Users.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << Line << endl;
			File.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(eMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareLoginRecord(string Separator = "#//#")
	{
		string DataLine = "";

		DataLine += clsDate::GetSystemDateTimeString() + Separator;
		DataLine += Username + Separator;
		DataLine += clsUtil::EncryptWord(Password) + Separator;
		DataLine += to_string(Permissions);


		return DataLine;
	}
	
	struct sLoginRegisterRecord;
	static sLoginRegisterRecord _ConvertLineToLoginRecord(string Line, string Separator = "#//#")
	{
		sLoginRegisterRecord LoginRecord;

		vector <string> LoginsHistory = clsString::Split(Line, Separator);

		LoginRecord.Date = LoginsHistory[0];
		LoginRecord.Username = LoginsHistory[1];
		LoginRecord.Password = LoginsHistory[2];
		LoginRecord.Permissions = stoi(LoginsHistory[3]);

		return LoginRecord;
	}



public:
	clsUser(eMode Mode, string FirstName, string LastName, string Email, string Phone,
		string Username, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}

	struct sLoginRegisterRecord
	{
		string Date;
		string Username;
		string Password;
		int Permissions;
	};



	bool MarkedForDelete()
	{
		return _MarkForDelete;
	}


	void setUsername(string Username)
	{
		_Username = Username;
	}
	string getUsername()
	{
		return _Username;
	}

	__declspec(property(get = getUsername, put = setUsername)) string Username;

	void setPassword(string Password)
	{
		_Password = Password;
	}
	string getPassword()
	{
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string Password;


	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int getPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions)) int Permissions;


	bool IsEmpty()
	{
		return (_Mode == eMode::EmptyMode);
	}

	static clsUser Find(string Username)
	{
		fstream File;

		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.Username == Username)
				{
					File.close();
					return User;
				}
			}

			File.close();
			return _GetEmptyUserObject();
		}
	}

	static clsUser Find(string Username, string Password)
	{
		fstream File;

		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.Username == Username && User.Password == Password)
				{
					File.close();
					return User;
				}
			}

			File.close();
			return _GetEmptyUserObject();
		}
	}

	static bool IsUserExist(string Username)
	{
		clsUser User = clsUser::Find(Username);

		return !(User.IsEmpty());

	}

	enum eSaveResult
	{
		svFailedEmptyObject,
		svSucceeded,
		svFailedUserExists
	};


	eSaveResult Save()
	{
		switch (_Mode)
		{
		case eMode::EmptyMode:
		{
			if (IsEmpty())
				return eSaveResult::svFailedEmptyObject;
		}

		case eMode::UpdateMode:
		{
			_Update();
			return eSaveResult::svSucceeded;
		}

		case eMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_Username))
			{
				return eSaveResult::svFailedUserExists;
			}
			else
			{
				_AddNew();
				_Mode = eMode::UpdateMode;
				return eSaveResult::svSucceeded;
			}

		}

		}
	}

	bool Delete()
	{
		vector <clsUser> UsersList;
		UsersList = _LoadUserDataFromFile();

		for (clsUser& User : UsersList)
		{
			if (User.Username == _Username)
			{
				User._MarkForDelete = true;
				break;
			}
		}

		_SaveUserDataToFile(UsersList);
		*this = _GetEmptyUserObject();

		return 1;
	}

	static clsUser GetAddNewUserObject(string Username)
	{
		return clsUser(eMode::AddNewMode, "", "", "", "", Username, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	enum ePermissions
	{
		pAll = -1,
		pListClients = 1,
		pAddNewClient = 2,
		pDeleteClient = 4,
		pUpdateClient = 8,
		pFindClient = 16,
		pTranactions = 32,
		pManageUsers = 64,
		pLoginHistory = 128,
		eCurrency = 256
	};

	bool CheckAccessPermission(ePermissions Permission)
	{
		if (this->Permissions == ePermissions::pAll)		// this Is UserObject
		{
			return true;
		}

		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
			return false;

	}

	void RegisterLogin()
	{
		string UserLine = _PrepareLoginRecord();

		fstream File;

		File.open("LoginHistory.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << UserLine << endl;
			File.close();
		}


	}

	static vector <sLoginRegisterRecord> GetLoginHistoryList()
	{
		vector <sLoginRegisterRecord> LoginsHistory;

		fstream File;

		File.open("LoginHistory.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			sLoginRegisterRecord LoginRecord;

			while (getline(File, Line))
			{
				LoginRecord = _ConvertLineToLoginRecord(Line);

				LoginsHistory.push_back(LoginRecord);
			}
			File.close();
		}

		return LoginsHistory;

	}




};

