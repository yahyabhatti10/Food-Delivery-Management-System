#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;

#ifndef LoginSystem_H
#define LoginSystem_H

class LoginSystem
{
protected:
	int loginID;
	string password;
	string user;
public:
	LoginSystem() // No-Argument Constructor Defined.
	{
		loginID = 0;
		password = "";
		user = "";
	} // Constructor ends here.
	LoginSystem(int id, string p, string u) // Parameterized Constuctor.
	{
		loginID = id;
		password = p;
		user = u;
	} // Parameterized Constructor ends here.
	void setLoginID(int loginID)
	{
		this->loginID = loginID;
	}
	void setPassword(string password)
	{
		this->password = password;
	}
	void setUser(string user)
	{
		this->user = user;
	}
	string getPassword()
	{
		return password;
	}
	int getLoginID()
	{
		return loginID;
	}
	string getUser()
	{
		return user;
	}
};
#endif
