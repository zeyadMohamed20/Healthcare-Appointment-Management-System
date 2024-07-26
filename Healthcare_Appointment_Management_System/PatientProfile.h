#pragma once

#include <string>

#include "ExternalDataTypes.h"
#include "DateTime.h"
#include "Patient.h"

using namespace std;

typedef struct
{
	string name;
	string email;
	string password;
	string PhoneNumber;
	string address;
	BloodType blood;
	string gender;
	double height;
	double weight;
	DateTime dateOfBirth;
} PatientProfile_t;

class PatientProfile: public Patient
{
private:
	BloodType bloodType;
	string gender;
	double height;
	double weight;
	DateTime dateOfBirth;

public:
	PatientProfile(PatientProfile_t & profile);
	void setBloodType(BloodType bloodType);
	BloodType getBloodType();
	void setGender(string gender);
	string getGender();
	void setHeight(double height);
	double getHeight();
	void setWeight(double weight);
	double getWeight();
	void setDateOfBirth(DateTime dateOfBirth);
	DateTime getDateOfBirth();
};

