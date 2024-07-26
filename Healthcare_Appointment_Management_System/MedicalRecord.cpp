#include "MedicalRecord.h"
#include "Doctor.h"
#include "Patient.h"

MedicalRecord::MedicalRecord(Patient* patient, Doctor* doctor): patient(patient), doctor(doctor)
{
	this->recordId = (int)patient->viewMedicalHistory().size();
	patient->viewMedicalHistory().push_back(*this);
}

void MedicalRecord::addTreatment(string treatment)
{
	this->treatment.push_back(treatment);
}

vector<string> MedicalRecord::getTreatment()
{
	return this->treatment;
}

void MedicalRecord::updateDiagnosis(string diagnosis)
{
	this->diagnosis = diagnosis;
}

string MedicalRecord::getDiagnosis()
{
	return this->diagnosis;
}

void MedicalRecord::setDoctor(Doctor* newDoctor)
{
	this->doctor = newDoctor;
}

Doctor* MedicalRecord::getDoctor()
{
	return this->doctor;
}

void MedicalRecord::setPatient(Patient* newPatient)
{
	this->patient = newPatient;
}

Patient* MedicalRecord::getPatient()
{
	return this->patient;
}

int MedicalRecord::getRecordId()
{
	return this->recordId;
}
