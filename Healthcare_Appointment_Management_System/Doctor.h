#pragma once
#include <vector>
#include <map>

#include "User.h"
#include "Appointment.h"
#include "Patient.h"
#include "PatientProfile.h"
#include "DateTime.h"
#include "ExternalDataTypes.h"

using namespace std;

class Doctor :public User, public Appointment
{
private:
	int doctorId;
	Specialty field;
	vector<DateTime> schedule;
	static map<Specialty, vector<Doctor>> doctorsDataBase;

public:
	Doctor(string name, string email, string password, string PhoneNumber, string address, Role title, Specialty field);
	void addAppointment(DateTime& schedule);
	void removeAppointment(DateTime& schedule);
	void setSpecialty(Specialty field);
	Specialty getSpecialty();
	void updateMedicalRecord(MedicalRecord record);
	PatientProfile* viewPatientDetails(Patient patient);
	vector<DateTime> getAvailableSlots(DateTime& date);
	static map<Specialty, vector<Doctor>> getDoctorsDataBase();

	void bookAppointment(User* user, DateTime dateTime) override;
	void cancelAppointment(User* doctor, DateTime dateTime) override;
	void scheduleAppointment(User* user, DateTime newDateTime) override;
};

