#pragma once

#include <string>
#include <vector>

using namespace std;

class Doctor; // Forward declaration
class Patient; // Forward declaration

class MedicalRecord
{
private:
	int recordId;
	Patient* patient;
	Doctor* doctor;
	string diagnosis;
	vector<string>treatment;

public:
	MedicalRecord(Patient* patient, Doctor* doctor);
	void addTreatment(string treatment);
	vector<string >getTreatment();
	void updateDiagnosis(string diagnosis);
	string getDiagnosis();
	void setDoctor(Doctor* newDoctor);
	Doctor* getDoctor();
	void setPatient(Patient* newPatient);
	Patient* getPatient();
	int getRecordId();
};