#pragma once
#include <iostream>
#include "Valid.h"
#include <string>

using namespace std;

class User {
protected:
    string Username;
    string Password;
    string Rule;
    string FirstName, SecName;
    string Phone, Email;
public:
    User() {};
    User(const string& username, const string& password, const string& rule, const string& FName, const string& SEName, const string& num, const string& mail);

    //=========================================================================
    static string getMail(const User& use);
    static string getPas(const User& use);
    static string getusern(const User& use);
    static string getName(const User& use);
    static string getPhone(const User& use);
    static string getRule(const User& use);

    //=======================================================================

    void EditePass(const string& pa);
    void EditeNum(const string& n);
    void Editemail(const string& m);
    void Editerule(const string& ru);
    void EditeUser(const string& user);

    //=========================================================================
    friend ostream& operator<<(ostream& os, const User& user);
    friend istream& operator>>(istream& is, User& user);
};