#include "DentalClinic.h"
#include"Prescription.h"
#include <fstream>
#include <iostream>
#include <sstream>

void DentalClinic::addDoctor(const Doctor& doctor)
{
    doctors.push_back(doctor);
    std::cout << "Doctor added successfully.\n";
}

void DentalClinic::addPatient(const Patient& patient)
{
    patients.push_back(patient);
    std::cout << "Patient added successfully.\n";
}

void DentalClinic::addReceptionist(const Receptionist& receptionist)
{
    receptionists.push_back(receptionist);
    std::cout << "Receptionist added successfully.\n";
}

void DentalClinic::displayDoctors() const
{
    if (doctors.empty()) {
        std::cout << "No doctors available.\n";
        return;
    }
    std::cout << "List of Doctors:\n";
    for (size_t i = 0; i < doctors.size(); i++) {
        std::cout << i + 1 << ". " << doctors[i].getName(doctors[i])
            << " - Specialization: " << doctors[i].getSpcilazition() << "\n";
    }
}

void DentalClinic::displayPatients() const
{
    if (patients.empty()) {
        std::cout << "No patients available.\n";
        return;
    }
    std::cout << "List of Patients:\n";
    for (size_t i = 0; i < patients.size(); i++) {
        std::cout << i + 1 << ". " << patients[i].getName() << "\n"
            << " - Mobile: " << patients[i].gatphone() << "\n";
    }
}

void DentalClinic::displayReceptionists() const
{
    if (receptionists.empty()) {
        std::cout << "No receptionists available.\n";
        return;
    }
    std::cout << "List of Receptionists:\n";
    for (size_t i = 0; i < receptionists.size(); i++) {
        std::cout << i + 1 << ". " << receptionists[i].GETRENAME() << "\n";
    }
}

void DentalClinic::CreatPrescription(const std::string& doctorName, const std::string& patientName, const std::string& date, const std::string& medicineList, const std::string& notes) const
{
    Prescription prescription(patientName, doctorName, date, medicineList, notes);
    std::cout << "Prescription created by Dr. " << doctorName << " for " << patientName << ".\n";
}

bool DentalClinic::login(const std::string& username, const std::string& password) const
{
    for (size_t i = 0; i < doctors.size(); i++) {
        if (doctors[i].getUsername() == username && doctors[i].getPaSS() == password) {
            std::cout << "Doctor login successful! Welcome, Dr. " << doctors[i].getNAMEDOC() << ".\n";
            return true;
        }
    }
    for (size_t i = 0; i < patients.size(); i++) {
        if (patients[i].GetUsernamePat() == username && patients[i].GETPP() == password) {
            std::cout << "Patient login successful! Welcome, " << patients[i].GETPN() << ".\n";
            return true;
        }
    }
    for (size_t i = 0; i < receptionists.size(); i++) {
        if (receptionists[i].GETREUSERNAME() == username && receptionists[i].GETREPASS() == password) {
            std::cout << "Receptionist login successful! Welcome, " << receptionists[i].GETRENAME() << ".\n";
            return true;
        }
    }
    std::cout << "Invalid username or password.\n";
    return false;
}

bool DentalClinic::signup(const User& newUser)
{
    if (newUser.getRule(newUser) == "Doctor") {
        for (size_t i = 0; i < doctors.size(); i++) {
            if (doctors[i].getUsername() == newUser.getusern(newUser)) {
                std::cout << "Username already exists for a doctor. Please choose another.\n";
                return false;
            }
        }
        doctors.push_back(static_cast<const Doctor&>(newUser));
        std::cout << "Doctor signup successful.\n";
    }
    else if (newUser.getRule(newUser) == "Patient") {
        for (size_t i = 0; i < patients.size(); i++) {
            if (patients[i].GetUsernamePat() == newUser.getusern(newUser)) {
                std::cout << "Username already exists for a patient. Please choose another.\n";
                return false;
            }
        }
        patients.push_back(static_cast<const Patient&>(newUser));
        std::cout << "Patient signup successful.\n";
    }
    else if (newUser.getRule(newUser) == "Receptionist") {
        for (size_t i = 0; i < receptionists.size(); i++) {
            if (receptionists[i].GETREUSERNAME() == newUser.getusern(newUser)) {
                std::cout << "Username already exists for a receptionist. Please choose another.\n";
                return false;
            }
        }
        receptionists.push_back(static_cast<const Receptionist&>(newUser));
        std::cout << "Receptionist signup successful.\n";
    }
    else {
        std::cout << "Invalid user role.\n";
        return false;
    }
    return true;
}

void DentalClinic::saveData(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error saving data.\n";
        return;
    }
    // Save doctors
    for (size_t i = 0; i < doctors.size(); i++) {
        file << "Doctor," << doctors[i].getUsername() << "," << doctors[i].getPaSS() << ","
            << doctors[i].getNAMEDOC() << ","
            << doctors[i].getSpcilazition() << "\n";
    }
    // Save patients
    for (size_t i = 0; i < patients.size(); i++) {
        file << "Patient," << patients[i].GetUsernamePat() << "," << patients[i].GETPP() << ","
            << patients[i].getName() << ","
            << patients[i].gatphone() << "\n";
    }
    // Save receptionists
    for (size_t i = 0; i < receptionists.size(); i++) {
        file << "Receptionist," << receptionists[i].GETREUSERNAME() << "," << receptionists[i].GETREPASS() << ","
            << receptionists[i].GETRENAME() << "\n";
    }
    std::cout << "Data saved successfully.\n";
}

void DentalClinic::loadData(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error loading data.\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string role, username, password, firstName, lastName, extraField;
        std::getline(ss, role, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, extraField, ',');
        if (role == "Doctor") {
            doctors.emplace_back(username, password, "", "", firstName, lastName, extraField);
        }
        else if (role == "Patient") {
            patients.emplace_back(username, password, "", "", firstName, lastName, extraField);
        }
        else if (role == "Receptionist") {
            receptionists.emplace_back(username, password, "", "", firstName, lastName);
        }
    }
    std::cout << "Data loaded successfully.\n";
}