#pragma once

enum class Specialty
{
	GeneralPractitioner,
	Cardiologist,
	Dermatologist,
	Neurologist,
	Dentist,
};

enum class Status
{
	Booked,
	Cancelled,
	Completed
};

enum class Role
{
	admin,
	patient,
	doctor
};


enum class BloodType 
{
	A_POSITIVE,
	A_NEGATIVE,
	B_POSITIVE,
	B_NEGATIVE,
	AB_POSITIVE,
	AB_NEGATIVE,
	O_POSITIVE,
	O_NEGATIVE
};