#ifndef REPORTING_H
#define REPORTING_H

#include "appointment.h"
#include "patient.h"

void daily_appointments(Appointment *appointments, int appointment_count, const char *date);
void appointment_status(Appointment *appointments, int appointment_count);
void patient_activity(Patient *patients, int patient_count);

#endif // REPORTING_H


