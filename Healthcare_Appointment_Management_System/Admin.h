#pragma once
#include "User.h"

class Admin :public User
{
private:
	int adminId;

public:
	vector<User>viewAllUsers();
	void deleteUser(User user);
	void createUser(User user);
	void updateUser(User user);
};

