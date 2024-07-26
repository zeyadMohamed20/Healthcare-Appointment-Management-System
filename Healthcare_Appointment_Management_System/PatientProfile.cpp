#include "PatientProfile.h"
#include "User.h"

PatientProfile::PatientProfile(string name, string email, string password, string PhoneNumber, string address,
	Role title,BloodType blood, string gender, double height, double weight, DateTime dateOfBirth):Patient(name,email,password,PhoneNumber,address,title),
	bloodType(blood),gender(gender),height(height),weight(weight),dateOfBirth(dateOfBirth)
{
}

void PatientProfile::setBloodType(BloodType bloodType)
{
	this->bloodType = bloodType;
}

BloodType PatientProfile::getBloodType()
{
	return this->bloodType;
}

void PatientProfile::setGender(string gender)
{
	this->gender = gender;
}

string PatientProfile::getGender()
{
	return this->gender;
}

void PatientProfile::setHeight(double height)
{
	this->height = height;
}

double PatientProfile::getHeight()
{
	return this->height;
}

void PatientProfile::setWeight(double weight)
{
	this->weight = weight;
}

double PatientProfile::getWeight()
{
	return this->weight;
}

void PatientProfile::setDateOfBirth(DateTime dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

DateTime PatientProfile::getDateOfBirth()
{
	return this->dateOfBirth;
}
