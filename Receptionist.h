
#pragma once



#include"User.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Receptionist : public User
{
private: 
	string Shift; // Shifts for the Receptionist 
	vector<string> AssignedTasks; // Tasks required from the recipitionist like acdimic requier 

public:
	Receptionist() {};
	Receptionist(string username, string password,string rule , string firstName, string secondeName ,string email, string mobileNumber, string shift);

	//===============================================================================
	string GETRENAME()const;
	string GETREUSERNAME() const;
	string GETREPASS() const;

	//===============================================================================

	void displayReceptionistInfo() const;
	void updateTasks(const vector<string>& tasks);
	//===============================================================================
	// void manageAppointments();

	//===============================================================================
	friend ostream& operator<<(ostream& out, const Receptionist& receptionist);
	friend istream& operator>>(istream& is, Receptionist& receptionist);

	//===============================================================================
	string getShift() const;
	void setShift(const string& newShift);
	vector<string> getTasks() const ;





};