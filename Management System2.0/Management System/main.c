#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "security.h"       // Header for security functions
#include "appointment.h"    // Header for appointment functions
#include "patient.h"        // Header for patient functions
#include "reporting.h"      // Header for reporting functions

#define MAX_APPOINTMENTS 100    // Maximum number of appointments
#define MAX_PATIENTS 100        // Maximum number of patients

// Function declarations
void display_menu();
void appointments_menu(Appointment *appointments, int *appointment_count);
void patient_menu(Patient *patients, int *patient_count);
void handle_reporting_menu(Appointment *appointments, int appointment_count, Patient *patients, int patient_count);
void exit_application();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];  // Array to hold appointment data
    Patient patients[MAX_PATIENTS];              // Array to hold patient data
    int appointment_count = 0;                   // Counter for current number of appointments
    int patient_count = 0;                       // Counter for current number of patients

    // User login for access control
    login();

    int choice;

    // Main loop for the application
    while (1) {
        display_menu();                          // Show main menu
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                appointments_menu(appointments, &appointment_count);   // Manage appointments
                break;
            case 2:
                patient_menu(patients, &patient_count);               // Manage patients
                break;
            case 3:
                handle_reporting_menu(appointments, appointment_count, patients, patient_count);  // View reports
                break;
            case 4:
                exit_application();                                   // Exit application
                break;
            default:
                printf("Invalid option. Try again and choose from the options below.\n");
        }
    }
    return 0;
}

// Displays the main menu options to the user
void display_menu() {
    printf("\n***** MEDICLINIC MANAGEMENT SYSTEM *****\n");
    printf("1. Manage Appointments\n");
    printf("2. Manage Patients\n");
    printf("3. Reports\n");
    printf("4. EXIT\n");
}

// Appointment management menu
void appointments_menu(Appointment *appointments, int *appointment_count) {
    int choice;
    printf("\n*** APPOINTMENTS ***\n");
    printf("1. Add Appointment\n");
    printf("2. Remove Appointment\n");
    printf("3. Update Appointment\n");
    printf("4. EXIT TO MAIN MENU\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    // Appointment options
    switch (choice) {
        case 1:
            add_appointment(appointments, appointment_count);   // Add a new appointment
            break;
        case 2:
            remove_appointment(appointments, appointment_count);  // Remove an appointment
            break;
        case 3:
            update_appointment(appointments, *appointment_count);  // Update an existing appointment
            break;
        case 4:
            return;    // Exit to main menu
        default:
            printf("Invalid Choice. NOW RETURNING TO MAIN MENU\n");
    }
}

// Patient management menu
void patient_menu(Patient *patients, int *patient_count) {
    int choice;

    printf("\n*** PATIENTS ***\n");
    printf("1. Add Patient\n");
    printf("2. Remove Patient\n");
    printf("3. Update Patient\n");
    printf("4. EXIT TO MAIN MENU\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    // Patient options
    switch (choice) {
        case 1:
            add_patient(patients, patient_count);    // Add a new patient
            break;
        case 2:
            remove_patient(patients, patient_count);  // Remove a patient
            break;
        case 3:
            update_patient(patients, *patient_count); // Update an existing patient's details
            break;
        case 4:
            return;    // Exit to main menu
        default:
            printf("Invalid Choice. NOW RETURNING TO MAIN MENU\n");
    }
}

// Reporting menu to view different types of reports
void handle_reporting_menu(Appointment *appointments, int appointment_count, Patient *patients, int patient_count) {
    int choice;
    char date[20];

    printf("\n--- Reporting ---\n");
    printf("1. View Daily Appointments\n");
    printf("2. Appointment Status Analysis\n");
    printf("3. Patient Activity Report\n");
    printf("4. Back to Main Menu\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    // Handling reporting options
    switch (choice) {
        case 1:
            printf("Enter the date (YYYY-MM-DD) to view appointments: ");
            scanf("%s", date);
            daily_appointments(appointments, appointment_count, date);  // Show appointments for a specific day
            break;
        case 2:
            appointment_status(appointments, appointment_count);       // Analyze appointment statuses
            break;
        case 3:
            patient_activity(patients, patient_count);                 // Show patient activity report
            break;
        case 4:
            return;    // Exit to main menu
        default:
            printf("Invalid choice. Returning to Main Menu.\n");
    }
}

// Exits the application with a message
void exit_application() {
    printf("EXITING APPLICATION!!!! GOODBYE!\n");
    exit(0);
}
