
#pragma once

#include<string>
#include<regex>

using namespace std;


class valid {
public:
	// validate func for all priject 
	static bool validMail(const string& mail);
	static bool validPass(const string& pass);
	static bool validNm(const string& num);
	static bool validUsername(const string& username);

};
