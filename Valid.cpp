#include "Valid.h"


using namespace std;

bool valid::validMail(const string& mail)
{
    const regex pattern(R"((\w+)(\.[\w]+)*@([\w-]+\.)+[a-zA-Z]{2,})");

    return regex_match(mail, pattern);
}

bool valid::validPass(const string& pass)
{
    if (pass.length() < 8)
        return false; 
    bool hasU = false, hasL = false, hasS = false, hasI = false;
    for (int i = 0; i < pass.length(); i++)
    {
        if (isupper(pass[i]))
            hasU = true;
        if (islower(pass[i]))
            hasL = true;
        if (isdigit(pass[i]))
            hasI = true;
        if (ispunct(pass[i]))
            hasS = true;
        
    }
    return hasU && hasL && hasI && hasS;
}

bool valid::validNm(const string& num)
{
    return num.length()==11 && regex_match(num,regex("\\d{11}"));
}

bool valid::validUsername(const string& username)
{
    return !username.empty();
}


