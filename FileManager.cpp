#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool FileManger::isUsernameUnique(const string& username, const string& filename)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(username) != std::string::npos) {
            return false;
        }
    }
    return true;
}

bool FileManger::signup(const User& newUser, const string& userFile)
{
    ifstream inFile(userFile);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string storedUsername;
        getline(ss, storedUsername, ',');

        if (storedUsername == newUser.getusern(newUser)) {
            cout << "Username already exists. Please choose another.\n";
            return false;
        }
    }

    inFile.close();

    ofstream outFile(userFile, ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return false;
    }
    outFile << newUser.getusern(newUser) << "," << newUser.getPas(newUser) << "," << newUser.getRule(newUser) << ","
        << newUser.getName(newUser) << ","
        << newUser.getMail(newUser) << "," << newUser.getPhone(newUser) << "\n";
    outFile.close();

    cout << "Signup successful for user: " << newUser.getName(newUser) << "\n";
    return true;
}

bool FileManger::login(const string& username, const string& password, const string& userFile)
{
    ifstream inFile(userFile);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string storedUsername, storedPassword;
        getline(ss, storedUsername, ',');
        getline(ss, storedPassword, ',');

        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful. Welcome, " << username << "!\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}

void FileManger::loadUsers(vector<User>& users, const string& userFile)
{
    ifstream inFile(userFile);
    if (!inFile) {
        cout << "Error opening file for reading.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string username, password, rule, firstName, lastName, email, mobileNumber;

        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, rule, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, email, ',');
        getline(ss, mobileNumber, ',');

        User user(username, password, rule, firstName, lastName, email, mobileNumber);
        users.push_back(user);
    }
    inFile.close();
}

void FileManger::saveUsers(const vector<User>& users, const string& userFile)
{

    ofstream outFile(userFile);
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }
    if (users.empty())
    {
        cout << "empty list";
        return;
    }
    // i used range based loop to avide error C6031
    for (const auto& user : users) {
        outFile << user.getusern(user) << "," << user.getPas(user) << "," << user.getRule(user) << ","
            << user.getName(user) << "," << user.getMail(user) << "," << user.getPhone(user) << "\n";
    }
    outFile.close();
}

void FileManger::saveAppointments(const vector<Appointment>& appointments, const string& appointmentsFile)
{
    ofstream outFile(appointmentsFile);
    if (!outFile) {
        cout << "Error opening appointments file for writing.\n";
        return;
    }
    for (const auto& appointment : appointments) {
        outFile << appointment.getDoctorName() << "," << appointment.getPatientName() << ","
            << appointment.getDate() << "," << appointment.getTime() << "," << appointment.getReason() << "\n";
    }
    outFile.close();
}

void FileManger::loadAppointments(vector<Appointment>& appointments, const string& appointmentsFile)
{
    ifstream inFile(appointmentsFile);
    if (!inFile) {
        cerr << "Error opening appointments file for reading.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string doctorName, patientName, date, time, reason;

        getline(ss, doctorName, ',');
        getline(ss, patientName, ',');
        getline(ss, date, ',');
        getline(ss, time, ',');
        getline(ss, reason, ',');

        Appointment appointment(doctorName, patientName, date, time, reason);
        appointments.push_back(appointment);
    }
    inFile.close();
}