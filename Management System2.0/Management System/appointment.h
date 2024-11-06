#ifndef APPOINTMENT_H
#define APPOINTMENT_H

typedef enum { IN_PERSON, TELEMEDICINE } AppointmentType;

typedef struct {
    int id;
    char patient_name[50];
    char date[20];   // Format: "YYYY-MM-DD"
    char time[10];   // Format: "HH:MM"
    AppointmentType type;
} Appointment;

void add_appointment(Appointment *appointments, int *count);
void remove_appointment(Appointment *appointments, int *count);
void update_appointment(Appointment *appointments, int count);

#endif // APPOINTMENT_H

