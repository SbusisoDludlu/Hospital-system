#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;
    char name[50];
    int age;
    char contact_number[15];
    char address[100];
} Patient;

void add_patient(Patient *patients, int *count);
void remove_patient(Patient *patients, int *count);
void update_patient(Patient *patients, int count);

#endif // PATIENT_H

