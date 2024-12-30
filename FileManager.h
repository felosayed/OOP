#pragma once

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"User.h"
#include "Doctor.h"
#include "Patient.h"
#include "Receptionist.h"
#include "Appointment.h"
#include "Prescription.h"

using namespace std;


class FileManger 
{
public:

	static bool isUsernameUnique(const string& username, const string& filename);

	//================================================================================

	static bool signup(const User& newUser, const string& userFile);
	static bool login(const string& username, const string& password, const string& userFile);

	//=================================================================================

	static void loadUsers(vector<User>& users, const string& userFile);
	static void saveUsers(const vector<User>& users, const string& userFile);

	//=================================================================================
    
	static void saveAppointments(const vector<Appointment>& appointments, const string& appointmentsFile);
	static void loadAppointments(vector<Appointment>& appointments, const string& appointmentsFile);

	//================================================================================

	static void savePrescriptions(const vector<Prescription>& prescriptions, const string& prescriptionsFile);
	static void loadPrescriptions(vector<Prescription>& prescriptions, const string& prescriptionsFile);

	//================================================================================

	//static void saveAvailability(const vector<Doctor>& doctors, const string& availabilityFile);
	//static void loadAvailability(vector<Doctor>& doctors, const string& availabilityFile);
     };


