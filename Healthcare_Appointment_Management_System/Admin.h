#pragma once
#include "User.h"

class Admin :public User
{
private:
	int adminId;

public:
	Admin(string name, string email, string password, string PhoneNumber, string address, Role title);
	vector<User>viewAllUsers();
	void deleteUser(User user);
	void createUser(User user);
	void updateUser(User user);
};

