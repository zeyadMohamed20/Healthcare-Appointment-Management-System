#include "PatientProfile.h"
#include "User.h"

PatientProfile::PatientProfile(PatientProfile_t & profile): Patient(profile.name, profile.email, profile.password, profile.PhoneNumber, profile.address),
	bloodType(profile.blood), gender(profile.gender), height(profile.height), weight(profile.weight), dateOfBirth(profile.dateOfBirth)
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
