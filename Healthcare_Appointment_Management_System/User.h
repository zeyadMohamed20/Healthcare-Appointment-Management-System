#pragma once

#include<string>
#include<vector>

#include "ExternalDataTypes.h"

using namespace std;

class User
{
protected:
		static vector<User>usersDataBase;
		int userId;
		string name;
		string email;
		string password;
		string PhoneNumber;
		string address;
		Role title;
public:
	User(string name, string email, string password, string PhoneNumber, string address, Role title);
	virtual ~User();  // Virtual destructor for polymorphic behavior

	bool login(string email, string password);
	string getName();
	int getId();
};