#include <iostream>

#include "Patient.h"
#include "Doctor.h"

using namespace std;

Patient::Patient(string name, string email, string password, string PhoneNumber, string address, Role title)
	:User(name, email, password, PhoneNumber, address, title)
{
}

void Patient::manageProfile(PatientProfile* profile)
{
		this->profile = profile;
}

PatientProfile* Patient::viewProfile()
{
	return this->profile;
}

vector<MedicalRecord> Patient::viewMedicalHistory()
{
	return this->medicalHistory;
}

vector<Doctor> Patient::searchDoctor(Specialty field)
{
	map<Specialty, vector<Doctor>> doctorsDataBase = Doctor::getDoctorsDataBase();
	return doctorsDataBase[field];
}

void Patient::bookAppointment(User* user, DateTime dateTime) 
{
	Doctor* doctor = dynamic_cast<Doctor*>(user);
	vector<DateTime> availableSlots = doctor->getAvailableSlots(dateTime);

	for (auto& slot : availableSlots)
	{
		if ((slot.getTimeInfo().tm_hour  == dateTime.getTimeInfo().tm_hour) &&
			(slot.getTimeInfo().tm_min == dateTime.getTimeInfo().tm_min))
		{
			doctor->addAppointment(dateTime);
			cout << "Booking appointment with Dr. " << doctor->getName() << " on ";
			dateTime.print();
			return;
		}
	}
	cout << "Not available slot, please choose another avilable slot\n";
}

void Patient::cancelAppointment(User* user, DateTime dateTime)
{
	Doctor* doctor = dynamic_cast<Doctor*>(user);
	doctor->removeAppointment(dateTime);
	cout << "Appointment with Dr. " << doctor->getName() << " on ";
	dateTime.print();
	cout << " has been canceled\n";
}

void Patient::scheduleAppointment(User* user, DateTime newDateTime)
{
	Doctor* doctor = dynamic_cast<Doctor*>(user);
	vector<DateTime> availableSlots = doctor->getAvailableSlots(newDateTime);

	for (auto& slot : availableSlots)
	{
		if ((slot.getTimeInfo().tm_hour == newDateTime.getTimeInfo().tm_hour) &&
			(slot.getTimeInfo().tm_min == newDateTime.getTimeInfo().tm_min))
		{
			doctor->addAppointment(newDateTime);
			cout << "Appointment with Dr. " << doctor->getName() << " has been rescheduled to ";
			newDateTime.print();
			return;
		}
	}
	cout << "Not available slot, please choose another avilable slot\n";
}
