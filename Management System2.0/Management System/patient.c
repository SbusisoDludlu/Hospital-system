#include <stdio.h>
#include <string.h>
#include "patient.h"  // Header file for patient structure and constants

// Function to generate a unique ID for each patient
int generate_patient_id(Patient *patients, int count) {
    // If no patients exist, start ID from 1
    if (count == 0) return 1;
    // Otherwise, increment the ID from the last patient's ID
    return patients[count - 1].id + 1;
}

// Function to add a new patient to the list
void add_patient(Patient *patients, int *count) {
    printf("\n--- Add Patient ---\n");

    // Assign a unique ID to the new patient
    patients[*count].id = generate_patient_id(patients, *count);

    // Prompt user to enter details for the new patient
    printf("Enter Patient Name: ");
    scanf("%s", patients[*count].name);  // Store patient name
    printf("Enter Patient Age: ");
    scanf("%d", &patients[*count].age);  // Store patient age
    printf("Enter Contact Number: ");
    scanf("%s", patients[*count].contact_number);  // Store contact number
    printf("Enter Address: ");
    scanf(" %[^\n]s", patients[*count].address);  // Store address (allows spaces)

    // Confirm patient addition and increment the count
    printf("Patient with ID %d added successfully.\n", patients[*count].id);
    (*count)++;
}

// Function to remove a patient by their ID
void remove_patient(Patient *patients, int *count) {
    int id;  // Variable to store the patient ID to remove
    printf("\n--- Remove Patient ---\n");
    printf("Enter Patient ID to remove: ");
    scanf("%d", &id);

    // Search for the patient with the specified ID
    for (int i = 0; i < *count; i++) {
        if (patients[i].id == id) {
            // Shift all subsequent patients left to overwrite the removed patient
            for (int j = i; j < *count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            (*count)--;  // Decrease the count after removal
            printf("Patient with ID %d removed.\n", id);
            return;
        }
    }
    // If patient with specified ID is not found, notify the user
    printf("Patient with ID %d not found.\n", id);
}

// Function to update an existing patient's details by their ID
void update_patient(Patient *patients, int count) {
    int id;  // Variable to store the patient ID to update
    printf("\n--- Update Patient ---\n");
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    // Search for the patient with the specified ID
    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            // Prompt user to enter new details for the selected patient
            printf("Enter New Patient Name: ");
            scanf("%s", patients[i].name);
            printf("Enter New Age: ");
            scanf("%d", &patients[i].age);
            printf("Enter New Contact Number: ");
            scanf("%s", patients[i].contact_number);
            printf("Enter New Address: ");
            scanf(" %[^\n]s", patients[i].address);

            // Confirm patient update
            printf("Patient with ID %d updated successfully.\n", id);
            return;
        }
    }
    // If patient with specified ID is not found, notify the user
    printf("Patient with ID %d not found.\n", id);
}
