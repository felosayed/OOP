#pragma once
#include<iostream>
#include<string>


using namespace std;


class Appointment
{
private:
	string DocotorName, PatientName;
	string Date, Time;
	string Reason;

public:
	Appointment() {};
	Appointment(string DCNAME, string PATNAEM, string date, string time, string reason);


	//==========================================================================================================
	void setPatientName(const string& name);
	void setDoctorName(const string& name);
	void setDate(const string& appointmentDate);
	void setTime(const string& appointmentTime);
	void setReason(const string& appointmentReason);

	//=============================================================================================================
	string getPatientName() const;
	string getDoctorName() const;
	string getDate() const;
	string getTime() const;
	string getReason() const;


	//==============================================================================================================
	void displayAppointment() const; 

	//===========================================================================================================
	friend ostream& operator<<(ostream& out, const Appointment& appointment);
	friend istream& operator>>(istream& in, Appointment& appointment);



};