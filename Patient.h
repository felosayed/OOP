#pragma once

#include"User.h"
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Patient :public User {

private:
    string PatientHistory;
    string Gendre, BloodType;
    int     Age = 0;
    string Weight, Height;

public:
    Patient() {};

    Patient(const string user, const string pas, const string rule, const string fn, const string sn, const string numm, const string mail, const int age, const string weight, const string height, const string gendre, const string bloodtype, const string history);

    //===================================================
    string getPatientHistory() const;
    int getAge() const;
    string getGender() const;
    string getBloodType() const;
    string getWeight() const;
    string getHeight() const;
    string getName() const;
    string gatphone() const;
    string GetUsernamePat() const;
    string GETPP()const;
    string GETPN() const;


    // ======================================================
    void setPatientHistory(const string& patientHistory);
    void setAge(int age);
    void setGender(const string& gender);
    void setBloodType(const string& bloodType);
    void setWeight(string weight);
    void setHeight(string height);
    //========================================================
    void displayInfo() const ;
    void updateInfo(const string& newEmail, const string& newMobileNumber, double newWeight, double newHeight);
    //========================================================
    friend ostream& operator<<(ostream& os, const Patient& patient);
    friend istream& operator>>(istream& is, Patient& patient);
    //=========================================================


};