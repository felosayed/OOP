#include "Appointment.h"
#include<iostream>
#include<string>


using namespace std;

Appointment::Appointment(string DCNAME, string PATNAEM, string date, string time, string reason): DocotorName(DCNAME), PatientName(PATNAEM),Date(date),Time(time),Reason(reason) 
{
}

void Appointment::setPatientName(const string& name)
{
	PatientName = name;
}

void Appointment::setDoctorName(const string& name)
{
	DocotorName = name;
}

void Appointment::setDate(const string& C)
{
	Date =C ;
}

void Appointment::setTime(const string& appointmentTime)
{
	Time = appointmentTime;
}

void Appointment::setReason(const string& appointmentReason)
{
	Reason = appointmentReason;
}

string Appointment::getPatientName() const
{
	return PatientName;
}

string Appointment::getDoctorName() const
{
	return DocotorName;
}

string Appointment::getDate() const
{
	return Date;
}

string Appointment::getTime() const
{
	return Time;
}

string Appointment::getReason() const
{
	return Reason;
}

void Appointment::displayAppointment() const
{
	cout << "Appointment Details:\n";
	cout << "Patient Name: " << PatientName << "\n";
	cout << "Doctor Name: " << DocotorName << "\n";
	cout << "Date: " << Date << "\n";
	cout << "Time: " << Time << "\n";
	cout << "Reason: " << Reason << "\n";
}

ostream& operator<<(ostream& out, const Appointment& appointment)
{
	out << appointment.PatientName << ","
		<< appointment.DocotorName << ","
		<< appointment.Date << ","
		<< appointment.Time << ","
		<< appointment.Reason;
	return out;
}

istream& operator>>(istream& in, Appointment& appointment)
{
	cout << "Enter patient name: ";
	in.ignore();
	getline(in, appointment.PatientName);
	cout << "Enter doctor name: ";
	getline(in, appointment.DocotorName);
	cout << "Enter date (YYYY-MM-DD): ";
	getline(in, appointment.Date);
	cout << "Enter time (HH:MM): ";
	getline(in, appointment.Time);
	cout << "Enter reason for appointment: ";
	getline(in, appointment.Reason);
	return in;
}

