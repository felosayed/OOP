#pragma once

#include "User.h"
#include "Doctor.h"
#include "Prescription.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Doctor : public User
{
private:
    string Specilazition;
    vector<string> avilableDays;
    vector<vector<pair<int, int>>> avilabeHours;
    vector<Prescription> Createdprescriptions;

    vector<string> Doctors;

public:
    Doctor() {};

    Doctor(const string& Username, const string& Password, const string& Rule, const string& fn, const string& sn, const string& num, const string& mail, const string specilazition);

    //==================================================
    string getSpcilazition() const;
    void EditeSpcilazition(const string NS);
    string getUsername() const;
    string getPaSS() const;
    string getNAMEDOC() const;

    //=========set avilable data ==============================================
    void SetAvilableDay();
    static vector<string> GetAvilableDay(Doctor& doc);
    static void PrintAvilableDay(Doctor& doc);
    void SetAvilableHours();
    static vector<vector<pair<int, int>>> GetAvilableHours(); // return the vector
    void printAvilableHoursforweek();
    void PrintAvilableHoursForDay(const string& day);
    static void displayAvilabilty(Doctor& d);  // print the appointment 
    //=========================================================================
    void createPrescription(const Prescription& prescription);
    vector<Prescription> getCreatedPrescriptions() const;
    void displayIssuedPrescriptions() const;
};
