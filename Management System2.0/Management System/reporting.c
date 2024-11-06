#include <stdio.h>
#include <string.h>
#include "reporting.h"  // Header for reporting functions (e.g., daily appointments, appointment status)

// Function to display all appointments for a specific date
void daily_appointments(Appointment *appointments, int appointment_count, const char *date) {
    int found = 0;  // Flag to track if any appointments were found for the date
    printf("\n--- Daily Appointments for %s ---\n", date);

    // Iterate through all appointments
    for (int i = 0; i < appointment_count; i++) {
        // Check if appointment date matches the specified date
        if (strcmp(appointments[i].date, date) == 0) {
            // Display appointment details if the date matches
            printf("ID: %d, Patient: %s, Time: %s, Type: %s\n",
                   appointments[i].id,
                   appointments[i].patient_name,
                   appointments[i].time,
                   appointments[i].type == IN_PERSON ? "In-Person" : "Telemedicine");
            found = 1;  // Mark that an appointment was found
        }
    }

    // If no appointments were found for the specified date, notify the user
    if (!found) {
        printf("No appointments found for the specified date.\n");
    }
}

// Function to analyze and display the number of in-person vs. telemedicine appointments
void appointment_status(Appointment *appointments, int appointment_count) {
    int in_person_count = 0;       // Counter for in-person appointments
    int telemedicine_count = 0;    // Counter for telemedicine appointments

    // Loop through each appointment and count the type of appointment
    for (int i = 0; i < appointment_count; i++) {
        if (appointments[i].type == IN_PERSON) {
            in_person_count++;
        } else if (appointments[i].type == TELEMEDICINE) {
            telemedicine_count++;
        }
    }

    // Display the analysis of appointment types
    printf("\n--- Appointment Status Analysis ---\n");
    printf("Total Appointments: %d\n", appointment_count);
    printf("In-Person Appointments: %d\n", in_person_count);
    printf("Telemedicine Appointments: %d\n", telemedicine_count);

    // Calculate and display percentages of each appointment type if any appointments exist
    if (appointment_count > 0) {
        printf("Percentage of In-Person: %.2f%%\n", (in_person_count / (float)appointment_count) * 100);
        printf("Percentage of Telemedicine: %.2f%%\n", (telemedicine_count / (float)appointment_count) * 100);
    }
}

// Function to display each patient's information in the system
void patient_activity(Patient *patients, int patient_count) {
    printf("\n--- Patient Activity Report ---\n");

    // Check if any patient data is available
    if (patient_count == 0) {
        printf("No patient data available.\n");
        return;
    }

    // Loop through each patient and display their details
    for (int i = 0; i < patient_count; i++) {
        printf("Patient ID: %d, Name: %s, Age: %d, Contact: %s, Address: %s\n",
               patients[i].id,
               patients[i].name,
               patients[i].age,
               patients[i].contact_number,
               patients[i].address);
    }
    // Display the total number of patients in the system
    printf("Total Patients: %d\n", patient_count);
}
