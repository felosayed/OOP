#include <iostream>
#include <string>
#include "User.h"
#include "Doctor.h"
#include "Patient.h"
#include "Receptionist.h"
#include "DentalClinic.h"
#include "FileManager.h"

using namespace std;

void displayMainMenu() {
    cout << "1. Login\n";
    cout << "2. Signup\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void displayDoctorMenu() {
    cout << "Doctor Menu:\n";
    cout << "1. View Available Days\n";
    cout << "2. Set Available Days\n";
    cout << "3. View Available Hours\n";
    cout << "4. Set Available Hours\n";
    cout << "5. View Issued Prescriptions\n";
    cout << "6. Create Prescription\n";
    cout << "7. Logout\n";
    cout << "Enter your choice: ";
}

void displayPatientMenu() {
    cout << "Patient Menu:\n";
    cout << "1. View Personal Information\n";
    cout << "2. Update Personal Information\n";
    cout << "3. View Appointments\n";
    cout << "4. Logout\n";
    cout << "Enter your choice: ";
}

void displayReceptionistMenu() {
    cout << "Receptionist Menu:\n";
    cout << "1. View Assigned Tasks\n";
    cout << "2. Update Assigned Tasks\n";
    cout << "3. Logout\n";
    cout << "Enter your choice: ";
}

void displayClinicMenu() {
    cout << "Clinic Menu:\n";
    cout << "1. Add Doctor\n";
    cout << "2. Add Patient\n";
    cout << "3. Add Receptionist\n";
    cout << "4. Display Doctors\n";
    cout << "5. Display Patients\n";
    cout << "6. Display Receptionists\n";
    cout << "7. Logout\n";
    cout << "Enter your choice: ";
}

int main() {
    DentalClinic clinic;
    vector<User> users;
    vector<Appointment> appointments;

    // Load data from files
    FileManger::loadUsers(users, "users.txt");
    FileManger::loadAppointments(appointments, "appointments.txt");

    int choice;
    string username, password, rule;

    while (true) {
        displayMainMenu();
        cin >> choice;

        if (choice == 1) { // Login
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (clinic.login(username, password, users)) {
                rule = clinic.getUserRole(username); //  this function retrieves the user role
                while (true) {
                    if (rule == "Doctor") {
                        displayDoctorMenu();
                        cin >> choice;
                        if (choice == 1) {
                            // View Available Days
                            Doctor doc = clinic.getDoctor(username); // Assuming a function to get Doctor by username
                            Doctor::PrintAvilableDay(doc);
                        }
                        else if (choice == 2) {
                            // Set Available Days
                            Doctor doc = clinic.getDoctor(username);
                            doc.SetAvilableDay();
                        }
                        else if (choice == 3) {
                            // View Available Hours
                            Doctor doc = clinic.getDoctor(username);
                            doc.printAvilableHoursforweek();
                        }
                        else if (choice == 4) {
                            // Set Available Hours
                            Doctor doc = clinic.getDoctor(username);
                            doc.SetAvilableHours();
                        }
                        else if (choice == 5) {
                            // View Issued Prescriptions
                            Doctor doc = clinic.getDoctor(username);
                            doc.displayIssuedPrescriptions();
                        }
                        else if (choice == 6) {
                            // Create Prescription
                            string patientName, date, medicineList, notes;
                            cout << "Enter patient name: ";
                            cin.ignore();
                            getline(cin, patientName);
                            cout << "Enter date (YYYY-MM-DD): ";
                            getline(cin, date);
                            cout << "Enter medicine list: ";
                            getline(cin, medicineList);
                            cout << "Enter notes: ";
                            getline(cin, notes);
                            Prescription prescription(patientName, username, date, medicineList, notes);
                            Doctor doc = clinic.getDoctor(username);
                            doc.createPrescription(prescription);
                        }
                        else if (choice == 7) {
                            // Logout
                            break;
                        }
                        else {
                            cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    else if (rule == "Receptionist") {
                        displayReceptionistMenu();
                        cin >> choice;
                        if (choice == 1) {
                            // View Assigned Tasks
                            Receptionist rec = clinic.getReceptionist(username); // Assuming a function to get Receptionist by username
                            vector<string> tasks = rec.getTasks();
                            cout << "Assigned Tasks:\n";
                            for (const auto& task : tasks) {
                                cout << task << "\n";
                            }
                        }
                        else if (choice == 2) {
                            // Update Assigned Tasks
                            Receptionist rec = clinic.getReceptionist(username);
                            vector<string> tasks;
                            string task;
                            cout << "Enter tasks (type 'done' to finish):\n";
                            while (true) {
                                cin.ignore();
                                getline(cin, task);
                                if (task == "done")
                                    break;

                                tasks.push_back(task);
                            }
                            rec.updateTasks(tasks);
                        }
                        else if (choice == 3) {
                            // Logout
                            break;
                        }
                        else {
                            cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    else if (rule == "Clinic") {
                        displayClinicMenu();
                        cin >> choice;
                        if (choice == 1) {
                            // Add Doctor
                            Doctor doc;
                            cin >> doc; // Assuming overloaded >> operator for Doctor
                            clinic.addDoctor(doc);
                        }
                        else if (choice == 2) {
                            // Add Patient
                            Patient pat;
                            cin >> pat; // Assuming overloaded >> operator for Patient
                            clinic.addPatient(pat);
                        }
                        else if (choice == 3) {
                            // Add Receptionist
                            Receptionist rec;
                            cin >> rec; // Assuming overloaded >> operator for Receptionist
                            clinic.addReceptionist(rec);
                        }
                        else if (choice == 4) {
                            // Display Doctors
                            clinic.displayDoctors();
                        }
                        else if (choice == 5) {
                            // Display Patients
                            clinic.displayPatients();
                        }
                        else if (choice == 6) {
                            // Display Receptionists
                            clinic.displayReceptionists();
                        }
                        else if (choice == 7) {
                            // Logout
                            break;
                        }
                        else {
                            cout << "Invalid choice. Please try again.\n";
                        }
                    }
                    else {
                        displayPatientMenu();
                        cin >> choice;
                        if (choice == 1) {
                            // View Personal Information
                            Patient pat = clinic.getPatient(username); // Assuming a function to get Patient by username
                            pat.displayInfo();
                        }
                        else if (choice == 2) {
                            // Update Personal Information
                            Patient pat = clinic.getPatient(username);
                            string email, phone;
                            string weight, height;
                            cout << "Enter new email: ";
                            cin >> email;
                            cout << "Enter new mobile number: ";
                            cin >> phone;
                            cout << "Enter new weight: ";
                            cin >> weight;
                            cout << "Enter new height: ";
                            cin >> height;
                            cout << "this funcinslity not avilable ffor now \n";
                           // pat.updateInfo(email, phone, weight, height);
                        }
                        else if (choice == 3) {
                            // View Appointments
                            for (const auto& appointment : appointments) {
                                if (appointment.getPatientName() == username) {
                                    appointment.displayAppointment();
                                }
                            }
                        }
                        else if (choice == 4) {
                            // Logout
                            break;
                        }
                        else {
                            cout << "Invalid choice. Please try again.\n";
                        }
                    }
                }
            }
            else {
                cout << "Invalid username or password.\n";
            }
        }
        else if (choice == 2) { // Signup
            cout << "Choose your role (Doctor/Receptionist/Clinic): ";
            cin >> rule;

            if (rule == "doctor" || rule == "receptionist" || rule == "clinic") {
                User newUser;
                cin >> newUser; //  overloaded >> operator for User
                newUser.Editerule(rule); // Set the role

                if (clinic.signup(newUser)) {
                    cout << rule << " signed up successfully.\n";
                }
                else {
                    cout << "Signup failed.\n";
                }
            }
            else {
                rule = "Patient"; // Any other role is considered as Patient
                User newUser;
                cin >> newUser; // Assuming overloaded >> operator for User
                newUser.Editerule(rule); // Set the role to Patient

                if (clinic.signup(newUser)) {
                    cout << "Patient signed up successfully.\n";
                }
                else {
                    cout << "Signup failed.\n";
                }
            }
        }
        else if (choice == 3) { // Exit
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    // Save data to files
    FileManger::saveUsers(users, "users.txt");
    FileManger::saveAppointments(appointments, "appointments.txt");

    return 0;
}