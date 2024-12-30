#include"User.h"
#include<string>
#include<iostream>
#include<vector>
#include "Patient.h"

Patient::Patient(const string user, const string pas, const string rule, const string fn, const string sn, const string numm, const string mail , const int age, const string weight, const string height, const string gendre, const string bloodtype, const string history) :User(user, pas, rule, fn, sn, numm, mail), Age(age), Weight(weight), Height(height), Gendre(gendre), BloodType(bloodtype), PatientHistory(history)
{
}

string Patient::getPatientHistory() const
{
	return PatientHistory;
}

int Patient::getAge() const
{
	return Age;
}

string Patient::getGender() const
{
	return Gendre;
}

string Patient::getBloodType() const
{
	return BloodType;
}

string Patient::getWeight() const
{
	return Weight;
}

string Patient::getHeight() const
{
	return Height;
}

string Patient::getName() const
{
	
	return FirstName + " " + SecName;
}

string Patient::gatphone() const
{
	return Phone;
}

string Patient::GetUsernamePat() const
{
	return FirstName+ " "+SecName;
}

string Patient::GETPP() const
{
	return Password;
}

string Patient::GETPN() const
{
	return FirstName+" "+SecName;
}


void Patient::setPatientHistory(const string& patientHistory)
{
	PatientHistory = patientHistory;
}

void Patient::setAge(int age)
{
	Age = age;
}

void Patient::setGender(const string& gender)
{
	Gendre = gender;
}

void Patient::setBloodType(const string& bloodType)
{
	BloodType = bloodType;
}

void Patient::setWeight(string weight)
{
	Weight = weight;
}

void Patient::setHeight(string height)
{
	Height = height;
}

void Patient::displayInfo() const
{
	cout << "Patient Info:\n"
		<< "Name: " << FirstName << " " << SecName<< "\n"
		<< "Email: " << Email << "\n"
		<< "Mobile Number: " << Phone << "\n"
		<< "Age: " << Age << "\n"
		<< "Gender: " << Gendre << "\n"
		<< "Blood Type: " << BloodType << "\n"
		<< "Weight: " << Weight << " kg\n"
		<< "Height: " << Height << " cm\n";
}

void Patient::updateInfo(const string& newEmail, const string& newMobileNumber,double newWeight, double newHeight) {
	Email = newEmail;
	Phone = newMobileNumber;
	Weight = newWeight;
	Height = newHeight;
}

ostream& operator<<(ostream& os, const Patient& patient)
{
	os << static_cast<const User&>(patient); //  this will call thhe overload foe the base class = User and then we will add some func

	os << "Age: " << patient.Age << "\n"
		<< "Weight: " << patient.Weight << "\n"
		<< "Height: " << patient.Height << "\n"
		<< "Gender: " << patient.Gendre << "\n"
		<< "Blood Type: " << patient.BloodType << "\n"
		<< "Patient History: " << patient.PatientHistory << "\n";

	return os;
}

istream& operator>>(istream& is, Patient& patient)
{
	is >> static_cast<User&>(patient); 

	cout << "Enter Age: ";
	is >> patient.Age;

	cout << "Enter Weight: ";
	is >> patient.Weight;

	cout << "Enter Height: ";
	is >> patient.Height;

	// ther is a problem the next data we need to raed is not a one word it's gonna be a sentence or more so we will use getline 
	// i got some help by this way 
	cout << "Enter Gender: ";
	is.ignore(); 
	getline(is, patient.Gendre);

	cout << "Enter Blood Type: ";
	getline(is, patient.BloodType);

	cout << "Enter Patient History: ";
	getline(is, patient.PatientHistory);

	return is;
}

