#include "User.h"
#include "Valid.h"
#include <iostream>
#include <vector>
#include"FileManager.h"

using namespace std;

// Paramitarized constructor
User::User(const string& username, const string& password, const string& rule, const string& FName, const string& SEName, const string& num, const string& mail)
{
    if (!valid::validMail(mail)) {
        throw invalid_argument("Invalid email, please check the email format.");
    }
    else if (!valid::validNm(num)) {
        throw invalid_argument("Invalid phone number, please check that the phone has 11 digits.");
    }
    else if (!valid::validPass(password)) {
        throw invalid_argument("Invalid password, make sure your password has at least 8 characters, contains upper and lower letters, numbers, and special characters.");
    }
    else if (!valid::validUsername(username)) {
        throw invalid_argument("You cannot enter an empty username.");
    }
    else if (! FileManger::isUsernameUnique(username, "users.txt")) {
        throw invalid_argument("Username is already taken, please choose another one.");
    }

    // if all values are true
    Email = mail;
    Password = password;
    Username = username;
    Phone = num;
    Rule = rule;
    FirstName = FName;
    SecName = SEName;
}

// Getter functions
string User::getMail(const User& use) {
    return use.Email;
}

string User::getPas(const User& use) {
    return use.Password;
}

string User::getusern(const User& use) {
    return use.Username;
}

string User::getName(const User& use) {
    return use.FirstName + " " + use.SecName;
}

string User::getPhone(const User& use) {
    return use.Phone;
}

string User::getRule(const User& use) {
    return use.Rule;
}

// Edit functions
void User::EditePass(const string& pa)
{
    if (!valid::validPass(pa)) {
        throw invalid_argument("Invalid password, make sure your password has at least 8 characters, contains upper and lower letters, numbers, and special characters.");
    }
    Password = pa;
}

void User::EditeNum(const string& n)
{
    if (!valid::validNm(n)) {
        throw invalid_argument("Invalid phone number, please check that the phone has 11 digits.");
    }
    Phone = n;
}

void User::Editemail(const string& m)
{
    if (!valid::validMail(m)) {
        throw invalid_argument("Invalid email, please check the email format.");
    }
    Email = m;
}

void User::Editerule(const string& ru)
{
    Rule = ru;
}

void User::EditeUser(const string& user)
{
    if (!valid::validUsername(user)) {
        throw invalid_argument("You cannot enter an empty username.");
    }
    else if (! FileManger::isUsernameUnique(user, "users.txt")) {
        throw invalid_argument("Username is already taken, please choose another one.");
    }
    Username = user;
}

// Overloading for printing
ostream& operator<<(ostream& os, const User& user) {
    os << "Username: " << user.Username << ","
        << "Name: " << user.FirstName << " " << user.SecName << ","
        << "Email: " << user.Email << ","
        << "Phone: " << user.Phone << ","
        << "Rule: " << user.Rule << ",";
    return os;
}

// Overloading for setting values
istream& operator>>(istream& is, User& user) {
    bool validInput = false;

    // For username
    while (!validInput) {
        cout << "Enter username: ";
        is >> user.Username;
        if (!valid::validUsername(user.Username)) {
            cout << "Invalid username! Please try again (non-empty, no spaces).\n";
        }
        else {
            validInput = true;
        }
    }

    validInput = false;
    // For password
    while (!validInput) {
        cout << "Enter password: ";
        is >> user.Password;
        if (!valid::validPass(user.Password)) {
            cout << "Invalid password! Make sure your password has at least 8 characters, contains upper and lower letters, numbers, and special characters. Try again.\n";
        }
        else {
            validInput = true;
        }
    }

    validInput = false;
    // For rule
    while (!validInput) {
        cout << "Enter rule (admin, user, etc.): ";
        is >> user.Rule;
        validInput = true;
    }

    // For first name
    validInput = false;
    while (!validInput) {
        cout << "Enter your first name: ";
        is >> user.FirstName;
        validInput = true;
    }

    // For second name
    validInput = false;
    while (!validInput) {
        cout << "Enter your second name: ";
        is >> user.SecName;
        validInput = true;
    }

    // For phone number
    validInput = false;
    while (!validInput) {
        cout << "Enter phone number: ";
        is >> user.Phone;
        if (!valid::validNm(user.Phone)) {
            cout << "Invalid phone number! Please ensure it has 11 digits. Try again.\n";
        }
        else {
            validInput = true;
        }
    }

    // For email
    validInput = false;
    while (!validInput) {
        cout << "Enter email: ";
        is >> user.Email;
        if (!valid::validMail(user.Email)) {
            cout << "Invalid email format! Please check and try again.\n";
        }
        else {
            validInput = true;
        }
    }

    return is;
}