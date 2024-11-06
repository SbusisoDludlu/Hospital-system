#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "security.h"  // Header file for security functions (e.g., login, logging errors)

// Administrator, doctor, and secretary credentials
const char *admin_username = "cebo";
const char *admin_password = "devices";
const char *doctor_username = "sisonke";
const char *doctor_password = "matyipu";
const char *secretary_username = "velisiwe";
const char *secretary_password = "mthethwa";

// Function to handle user login
void login() {
    char username[50];  // Buffer to store input username
    char password[50];  // Buffer to store input password

    printf("*** LOGIN ***\n");
    printf("Enter Username: ");
    scanf("%s", username);  // Read username from user input
    printf("Enter Password: ");
    scanf("%s", password);  // Read password from user input

    // Check if the provided credentials match any valid set
    int login_success = credentials(username, password);

    if (login_success) {
        printf("LOGIN SUCCESSFUL! WELCOME, %s\n", username);
    } else {
        printf("Invalid username or password. Terminating program.\n");
        log_error("Failed login attempt");  // Log the failed attempt
        exit(0);  // Exit the program if login fails
    }
}

// Function to validate credentials against predefined values
int credentials(const char *username, const char *password) {
    // Check if username and password match any predefined credentials
    if (strcmp(username, admin_username) == 0 && strcmp(password, admin_password) == 0) {
        return 1;  // Login successful for admin
    } else if (strcmp(username, doctor_username) == 0 && strcmp(password, doctor_password) == 0) {
        return 1;  // Login successful for doctor
    } else if (strcmp(username, secretary_username) == 0 && strcmp(password, secretary_password) == 0) {
        return 1;  // Login successful for secretary
    } else {
        return 0;  // Login failed
    }
}

// Function to log errors in a CSV file
void log_error(const char *error_message) {
    FILE *file = fopen("error_log.csv", "a");  // Open log file in append mode

    if (file) {
        // Get the current timestamp
        time_t now = time(NULL);
        char *timestamp = ctime(&now);
        timestamp[strlen(timestamp) - 1] = '\0';  // Remove newline character from timestamp

        // Write the error message and timestamp to the CSV file
        fprintf(file, "%s, %s\n", error_message, timestamp);
        fclose(file);  // Close the file after logging
    } else {
        printf("Error: Unable to open log file.\n");
    }
}

// Function to display the last log entry from the CSV file
void display_last_log() {
    FILE *file = fopen("error_log.csv", "r");  // Open log file in read mode
    char line[256];      // Buffer to read each line in the file
    char last_line[256]; // Buffer to hold the last line read

    if (file) {
        // Read each line until reaching the end of the file
        while (fgets(line, sizeof(line), file)) {
            strcpy(last_line, line);  // Keep reading until the last line
        }
        fclose(file);  // Close the file after reading

        // Display the last log entry if it exists
        if (strlen(last_line) > 0) {
            printf("\n--- Last Log Entry ---\n");
            printf("%s\n", last_line);
        } else {
            printf("No log entries found.\n");
        }
    } else {
        printf("Error: Unable to open log file.\n");
    }
}
