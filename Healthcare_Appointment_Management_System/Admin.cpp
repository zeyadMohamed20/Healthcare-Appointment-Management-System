#include "Admin.h"

vector<User> Admin::viewAllUsers()
{
    return User::usersDataBase;
}

void Admin::deleteUser(User user)
{
    User::usersDataBase.erase(User::usersDataBase.begin() + user.userId);
}

void Admin::createUser(User user)
{
    User::usersDataBase.push_back(user);
}

void Admin::updateUser(User user)
{
	User::usersDataBase[user.userId] = user;
}
