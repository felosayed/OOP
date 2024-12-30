#pragma once


#include<iostream>
#include<string>


using namespace std;



class Prescription {

private: 
	string PatientName, DoctorName;
	string Date, MidecineList;
	string Notes;

public:
	Prescription() {};
	Prescription(const string& patientName, const string& doctorName, const string& date, const string& medicineList, const string& notes);
	 

   //===================================================================================================================
	string getPatientName() const;
	string getDoctorName() const;
	string getDate() const;
	string getMedicineList() const;
	string getNotes() const;


	//=================================================================================================================
	void setPatientName(const string& patientName);
	void setDoctorName(const string& doctorName);
	void setDate(const string& date);
	void setMedicineList(const string& medicineList);
	void setNotes(const string& notes);


	//================================================================================================================
	static void displayPrescription(Prescription P1) ;



	//====================================================================================================
	friend ostream& operator<<(ostream& os, const Prescription& prescription);
	friend istream& operator>>(istream& is, Prescription& prescription);



};