#include <stdio.h>
#include <string.h>
#include "appointment.h"  // Header file for appointment structure and constants

// Function to generate a unique ID for each appointment
int generate_appointment_id(Appointment *appointments, int count) {
    // If no appointments exist, start ID from 1
    if (count == 0) return 1;
    // Otherwise, increment the ID from the last appointment's ID
    return appointments[count - 1].id + 1;
}

// Function to add a new appointment to the list
void add_appointment(Appointment *appointments, int *count) {
    int type;  // Variable to store the type of appointment (In-Person or Telemedicine)
    printf("\n--- Add Appointment ---\n");

    // Assign a unique ID to the new appointment
    appointments[*count].id = generate_appointment_id(appointments, *count);

    // Prompt user to enter details for the new appointment
    printf("Enter Patient Name: ");
    scanf("%s", appointments[*count].patient_name);  // Store patient name
    printf("Enter Appointment Date (YYYY-MM-DD): ");
    scanf("%s", appointments[*count].date);  // Store appointment date
    printf("Enter Appointment Time (HH:MM): ");
    scanf("%s", appointments[*count].time);  // Store appointment time

    // Prompt user to select the type of appointment
    printf("Enter Appointment Type (1 for In-Person, 2 for Telemedicine): ");
    scanf("%d", &type);
    if (type == 1) {
        appointments[*count].type = IN_PERSON;  // Set type to In-Person
    } else if (type == 2) {
        appointments[*count].type = TELEMEDICINE;  // Set type to Telemedicine
    } else {
        printf("Invalid type selected. Defaulting to In-Person.\n");
        appointments[*count].type = IN_PERSON;  // Default to In-Person if input is invalid
    }

    // Confirm appointment addition and increment the count
    printf("Appointment with ID %d added successfully.\n", appointments[*count].id);
    (*count)++;
}

// Function to remove an appointment by its ID
void remove_appointment(Appointment *appointments, int *count) {
    int id;  // Variable to store the appointment ID to remove
    printf("\n--- Remove Appointment ---\n");
    printf("Enter Appointment ID to remove: ");
    scanf("%d", &id);

    // Search for the appointment with the specified ID
    for (int i = 0; i < *count; i++) {
        if (appointments[i].id == id) {
            // Shift all subsequent appointments left to overwrite the removed appointment
            for (int j = i; j < *count - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            (*count)--;  // Decrease the count after removal
            printf("Appointment with ID %d removed.\n", id);
            return;
        }
    }
    // If appointment with specified ID is not found, notify the user
    printf("Appointment with ID %d not found.\n", id);
}

// Function to update an existing appointment's details by its ID
void update_appointment(Appointment *appointments, int count) {
    int id, type;  // Variables to store the appointment ID to update and the new type
    printf("\n--- Update Appointment ---\n");
    printf("Enter Appointment ID to update: ");
    scanf("%d", &id);

    // Search for the appointment with the specified ID
    for (int i = 0; i < count; i++) {
        if (appointments[i].id == id) {
            // Prompt user to enter new details for the selected appointment
            printf("Enter New Patient Name: ");
            scanf("%s", appointments[i].patient_name);
            printf("Enter New Date (YYYY-MM-DD): ");
            scanf("%s", appointments[i].date);
            printf("Enter New Time (HH:MM): ");
            scanf("%s", appointments[i].time);

            // Prompt user to select a new type for the appointment
            printf("Enter New Type (1 for In-Person, 2 for Telemedicine): ");
            scanf("%d", &type);
            if (type == 1) {
                appointments[i].type = IN_PERSON;  // Set type to In-Person
            } else if (type == 2) {
                appointments[i].type = TELEMEDICINE;  // Set type to Telemedicine
            }

            // Confirm appointment update
            printf("Appointment with ID %d updated successfully.\n", id);
            return;
        }
    }
    // If appointment with specified ID is not found, notify the user
    printf("Appointment with ID %d not found.\n", id);
}
