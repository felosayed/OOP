#include "Doctor.h"
#include <utility>
#include "Prescription.h"
#include <iostream>
#include <string>


using namespace std;


Doctor::Doctor(const string& Username, const string& Password, const string& Rule, const string& fn, const string& sn, const string& num, const string& mail, const string specilazition)
    : User(Username, Password, Rule, fn, sn, num, mail), Specilazition(specilazition)
{
}

string Doctor::getSpcilazition() const
{
    return Specilazition;
}

void Doctor::EditeSpcilazition(const string NS)
{
    Specilazition = NS;
}

string Doctor::getUsername() const
{
    return Username;
}

string Doctor::getPaSS() const
{
    return Password;
}

string Doctor::getNAMEDOC() const
{
    return FirstName + " " + SecName;
}

void Doctor::SetAvilableDay()
{
    int numDays;
    cout << "Enter the number of available days: ";
    std::cin >> numDays;
    while (numDays > 7)
    {
        cout << "dumb user or someone trying to test me but i won a point ya man . plz entr a correct number theereis only 7 days ya3m \n";
        std::cin >> numDays;
    }

    for (int i = 0; i < numDays; ++i) {
        string day;
        cout << "Enter day " << i + 1 << ": ";
        std::cin >> day;
        transform(day.begin(), day.end(), day.begin(), ::toupper);

        while (day != "SATURDAY" && day != "SUNDAY" && day != "MONDAY" && day != "TUESDAY" && day != "WEDNESDAY" && day != "THURSDAY" && day != "FRIDAY")
        {
            cout << "look there's two options the first that u suck at english so plz entre the name right or google it to get the right name sec that u trying to test me and i bet u again \n";
            std::cin >> day;
        }
        avilableDays.push_back(day);
        avilabeHours.emplace_back();
    }
}

vector<string> Doctor::GetAvilableDay(Doctor& doc)
{
    return doc.avilableDays;
}

void Doctor::PrintAvilableDay(Doctor& doc)
{
    if (doc.avilableDays.empty()) {
        cout << "No available days or hours set.\n";
        return;
    }
    for (size_t i = 0; i < doc.avilableDays.size(); ++i) {
        cout << doc.avilableDays[i] << "\t ";
    }
    cout << endl;
}

void Doctor::SetAvilableHours()
{
    string day;
    cout << "Enter the day to set available hours: ";
    std::cin >> day;
    transform(day.begin(), day.end(), day.begin(), ::toupper);
    while (day != "SATURDAY" && day != "SUNDAY" && day != "MONDAY" && day != "TUESDAY" && day != "WEDNESDAY" && day != "THURSDAY" && day != "FRIDAY")
    {
        cout << "look there's two options the first that u suck at english so plz entre the name right or google it to get the right name sec that u trying to test me and i bet u again \n";
        std::cin >> day;
    }

    auto it = find(avilableDays.begin(), avilableDays.end(), day);
    if (it == avilableDays.end()) {
        cout << "Day not found. Please add the day first.\n";
        return;
    }
    int index = distance(avilableDays.begin(), it);
    int numPeriods;
    cout << "Enter the number of periods for " << day << ": ";
    std::cin >> numPeriods;
    while (numPeriods > 48)
    {
        cout << "you agan ???? ?? ?????? ??? ???? \n";
        cout << "lets supose that you will work the hole day wich is 24 hour and u a superman will finish te patient in 30min u will not be able to take more than 48";
        std::cin >> numPeriods;
    }
    for (int i = 0; i < numPeriods; ++i) {
        int start, end;
        cout << "Enter start and end time for period " << i + 1 << " ( 9, 11): ";
        std::cin >> start >> end;
        if (start > 24 || end > 24)
        {
            cout << "not avilable time day only have 24 hour";
            --i;
            continue;
        }
        if (start >= end) {
            cout << "Invalid period. Start time must be less than end time.\n";
            --i;
            continue;
        }
        avilabeHours[index].push_back(pair<int, int>(start, end));
    }
}

void Doctor::printAvilableHoursforweek()
{
    for (size_t i = 0; i < avilabeHours.size(); ++i) {
        cout << avilableDays[i] << " available hours:\n";
        for (const auto& hour : avilabeHours[i]) {
            cout << "  From " << hour.first << " to " << hour.second << "\n";
        }
    }
}

void Doctor::PrintAvilableHoursForDay(const string& day)
{
    for (size_t i = 0; i < avilableDays.size(); ++i) {
        if (avilableDays[i] == day) {
            cout << day << " available hours:\n";
            for (const auto& hour : avilabeHours[i]) {
                cout << "  From " << hour.first << " to " << hour.second << "\n";
            }
            return;
        }
    }
    std::cout << "Invalid day name.\n";
}

void Doctor::createPrescription(const Prescription& prescription)
{
    Createdprescriptions.push_back(prescription);
}

vector<Prescription> Doctor::getCreatedPrescriptions() const
{
    return Createdprescriptions;
}

void Doctor::displayIssuedPrescriptions() const
{
    if (Createdprescriptions.empty()) {
        cout << "No prescriptions issued by this doctor.\n";
        return;
    }
    for (size_t i = 0; i < Createdprescriptions.size(); ++i) {
        cout << "Prescription " << i + 1 << ":\n";
        Prescription PP = Createdprescriptions[i];
        Prescription::displayPrescription(PP);
    }
}
