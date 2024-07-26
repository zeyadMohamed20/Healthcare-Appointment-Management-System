#pragma once

#include <vector>

#include "User.h"
#include "MedicalRecord.h"
#include "ExternalDataTypes.h"
#include "Appointment.h"
#include "DateTime.h"

using namespace std;

class Doctor; // Forward declaration
class PatientProfile; // Forward declaration

class Patient : public User, public Appointment
{
private:
	int patientId;
	PatientProfile* profile;
	vector<MedicalRecord> medicalHistory;

public:
	Patient(string name, string email, string password, string PhoneNumber, string address, Role title);
	void manageProfile(PatientProfile* profile);
	PatientProfile* viewProfile();
	vector<MedicalRecord> viewMedicalHistory();
	vector<Doctor> searchDoctor(Specialty field);
	void bookAppointment(User* user, DateTime dateTime) override;
	void cancelAppointment(User* user, DateTime dateTime) override;
	void scheduleAppointment(User* user, DateTime newDateTime) override;
};

