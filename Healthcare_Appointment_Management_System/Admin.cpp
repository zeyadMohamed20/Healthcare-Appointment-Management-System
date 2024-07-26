#include "Admin.h"

static int noOfAdmins = 0;

Admin::Admin(string name, string email, string password, string PhoneNumber, string address, Role title)
	:User(name, email, password, PhoneNumber, address, title)
{
    adminId = noOfAdmins;
    noOfAdmins++;
}

vector<User> Admin::viewAllUsers()
{
    return User::usersDataBase;
}

void Admin::deleteUser(User user)
{
    User::usersDataBase.erase(User::usersDataBase.begin() + (user.getId()));
}

void Admin::createUser(User user)
{
    User::usersDataBase.push_back(user);
}

void Admin::updateUser(User user)
{
	User::usersDataBase[(user.getId())] = user;
}
