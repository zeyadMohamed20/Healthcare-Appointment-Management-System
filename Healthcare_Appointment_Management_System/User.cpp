#include "User.h"

vector<User> User::usersDataBase;

User::User(string name, string email, string password, string PhoneNumber, string address, Role title)
	:name(name), email(email), password(password), PhoneNumber(PhoneNumber), address(address), title(title)
{
	usersDataBase.push_back(*this);
	userId = (int)usersDataBase.size() - 1;
}

// Function to check if the email and password match any of the users in the usersDataBase vector
bool User::login(string email, string password)
{
	// Loop through the usersDataBase vector to check if the email and password match any of the users
	for (int i = 0; i < usersDataBase.size(); i++)
	{
		if (usersDataBase[i].email == email && usersDataBase[i].password == password)
		{
			return true;
		}
	}
	return false;
}

string User::getName()
{
	return usersDataBase[this->userId].name;
}

int User::getId()
{
	return userId;
}
User::~User()
{
		// Destructor
}
