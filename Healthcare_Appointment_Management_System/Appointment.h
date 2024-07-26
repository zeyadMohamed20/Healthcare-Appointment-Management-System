#pragma once

#include "User.h"
#include "DateTime.h"

class Appointment
{

public:
	virtual void bookAppointment(User* user, DateTime date) = 0;
	virtual void cancelAppointment(User* user, DateTime date) = 0;
	virtual void scheduleAppointment(User* user, DateTime date) = 0;
};

