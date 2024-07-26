#include <algorithm>

#include "Doctor.h"
#include "MedicalRecord.h"

map<Specialty, vector<Doctor>> Doctor::doctorsDataBase;

Doctor::Doctor(string name, string email, string password, string PhoneNumber, string address, Role title, Specialty field):User(name, email, password, PhoneNumber, address, title), field(field)
{
	doctorsDataBase[field].push_back(*this);
	doctorId = (int)doctorsDataBase[field].size() - 1;
}

void Doctor::addAppointment(DateTime& dateTime) 
{
    schedule.push_back(dateTime);
}

void Doctor::removeAppointment(DateTime& dateTime) 
{
    auto it = std::remove_if(schedule.begin(), schedule.end(),
        [&dateTime](const DateTime& dt) {
            return dt == dateTime;
        });
    if (it != schedule.end()) 
    {
        schedule.erase(it, schedule.end());
        cout << "Appointment removed successfully.\n";
    }
    else 
    {
        cout << "Appointment not found.\n";
    }
}

void Doctor::setSpecialty(Specialty field)
{
	this->field = field;
}

Specialty Doctor::getSpecialty()
{
	return this->field;
}

void Doctor::updateMedicalRecord(MedicalRecord record)
{
    record.getPatient()->viewMedicalHistory()[record.getRecordId()] = record;
}

PatientProfile* Doctor::viewPatientDetails(Patient patient)
{
	return patient.viewProfile();
}

vector<DateTime> Doctor::getAvailableSlots(DateTime& date) 
{
    vector<DateTime> availableSlots;

    // Define the working hours (e.g., 9 AM to 5 PM)
    for (int hour = 9; hour < 17; ++hour) 
    {
        for (int minute = 0; minute < 60; minute += 30) 
        {
            DateTime slot(date.getTimeInfo().tm_year + 1900, date.getTimeInfo().tm_mon + 1, date.getTimeInfo().tm_mday, hour, minute, 0);
            availableSlots.push_back(slot);
        }
    }

    // Remove the slots that are already booked
    for (auto& bookedSlot : schedule) 
    {
        if ((bookedSlot.getTimeInfo().tm_year + 1900 == date.getTimeInfo().tm_year + 1900) &&
            (bookedSlot.getTimeInfo().tm_mon + 1 == date.getTimeInfo().tm_mon + 1) &&
            (bookedSlot.getTimeInfo().tm_mday == date.getTimeInfo().tm_mday))
        {
            auto it = remove(availableSlots.begin(), availableSlots.end(), bookedSlot);
            availableSlots.erase(it, availableSlots.end());
        }
    }

    return availableSlots;
}

map<Specialty, vector<Doctor>> Doctor::getDoctorsDataBase()
{
    return doctorsDataBase;
}

void Doctor::bookAppointment(User* user, DateTime dateTime)
{
    Patient* patient = dynamic_cast<Patient*>(user);

    cout << "Booking appointment with Mr/Mrs " << patient->getName() << " on ";
    dateTime.print();
}

void Doctor::cancelAppointment(User* doctor, DateTime dateTime)
{
    cout << "Appointment with Dr. " << doctor->getName() << " on ";
    dateTime.print();
	cout << " has been canceled\n";
}

void Doctor::scheduleAppointment(User* user, DateTime newDateTime)
{
	Patient* patient = dynamic_cast<Patient*>(user);

	cout << "Scheduling appointment with Mr/Mrs " << patient->getName() << " on ";
	newDateTime.print();
}
