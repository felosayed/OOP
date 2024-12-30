#include"Receptionist.h"
#include<iostream>
#include<vector>
#include<string>



using namespace std;

Receptionist::Receptionist(string username, string password, string rule, string firstName, string secondeName, string email, string mobileNumber, string shift):User(username,password,rule,firstName,secondeName,email,mobileNumber) ,Shift(shift)
{
}


string Receptionist::GETRENAME() const
{
	return FirstName + " " + SecName;
}

string Receptionist::GETREUSERNAME() const
{
	return Username;
}

string Receptionist::GETREPASS() const
{
	return Password;
}

void Receptionist::displayReceptionistInfo() const
{
	cout << "Receptionist Information:\n"; 
	cout << "Name :" << FirstName<<" "<<SecName << "\n";
	cout << "Email: " << Email << "\n";
	cout << "Mobile Number: " << Phone << "\n";
	cout << "Shift: " << Shift << "\n";
	cout << "Assigned Tasks:\n"; 
	for (int i = 0; i < AssignedTasks.size(); i++)
	{
		cout << "task number " << i + 1 << "is : " << AssignedTasks[i] << "\n";
	}
}

void Receptionist::updateTasks(const vector<string>& tasks)
{
	AssignedTasks = tasks;
	cout << "Tasks updated successfully.\n";
}

string Receptionist::getShift() const
{
	return  Shift;  
}

void Receptionist::setShift(const string& newShift)
{
	Shift = newShift;
	cout << "shift changed to :" << Shift <<"\n";
}

vector<string> Receptionist::getTasks() const
{
	return AssignedTasks;
}



ostream& operator<<(ostream& os, const Receptionist& receptionist)
{
	os << static_cast<const User&>(receptionist);

	os<< receptionist.Shift << "\n";
	return os;
}

istream& operator>>(istream& is, Receptionist& receptionist)
{
	is >> static_cast<User&>(receptionist); // this will call the preveous code in the base class

	cout << "Enter shift: ";
	is >> receptionist.Shift;
	return is;
}



