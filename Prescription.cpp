#include "Prescription.h"
#include<iostream>
#include<string>



using namespace std;



Prescription::Prescription(const string& patientName, const string& doctorName, const string& date, const string& medicineList, const string& notes):PatientName(patientName),DoctorName(doctorName),Date(date),MidecineList(medicineList),Notes(notes)
{
}

string Prescription::getPatientName() const
{
	return PatientName;
}

string Prescription::getDoctorName() const
{
	return DoctorName;
}

string Prescription::getDate() const
{
	return Date;
}

string Prescription::getMedicineList() const
{
	return MidecineList;
}

string Prescription::getNotes() const
{
	return Notes;
}

void Prescription::setPatientName(const string& patientName)
{
	PatientName = patientName;
}

void Prescription::setDoctorName(const string& doctorName)
{
	DoctorName = doctorName;
}

void Prescription::setDate(const string& date)
{
	Date = date;
}

void Prescription::setMedicineList(const string& medicineList)
{
	MidecineList = medicineList;
}

void Prescription::setNotes(const string& notes)
{
	Notes = notes;
}

void Prescription::displayPrescription(Prescription P1)
{
	cout << "Prescription Details:" << "\n";
	cout << "Patient Name: " << P1.PatientName << "\n";
	cout << "Doctor Name: " << P1.DoctorName << "\n";
	cout << "Date: " << P1.Date << "\n";
	cout << "Medicines: " << P1.MidecineList << "\n";
	cout << "Notes: " << P1.Notes << "\n";
}



ostream& operator<<(ostream& os, const Prescription& prescription)
{
	os << "Patient Name: " << prescription.PatientName << ","
	   << "Doctor Name: " << prescription.DoctorName << ","
	   << "Date: " << prescription.Date << ","
	   << "Medicine List: " << prescription.MidecineList<< ","
	   << "Notes: " << prescription.Notes<<"\n";
	return os;
}

istream& operator>>(istream& is, Prescription& prescription)
{
	// We didnot use cin cuz we need to take all sentence user will write not just a single word and that what getline do 
	cout << "Enter Patient Name: ";
	getline(is, prescription.PatientName);
	cout << "Enter Doctor Name: ";
	getline(is, prescription.DoctorName);
	cout << "Enter Date: ";
	getline(is, prescription.Date);
	cout << "Enter Medicine List: ";
	getline(is, prescription.MidecineList);
	cout << "Enter Notes: ";
	getline(is, prescription.Notes);
	return is;
}
