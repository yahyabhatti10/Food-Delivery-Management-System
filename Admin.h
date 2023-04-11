#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include"Login System.h"
using namespace std;

#ifndef Admin_H
#define Admin_H

class Admin : public LoginSystem
{
protected:
	string riderPermit;
	string restaurantPermit;
	string customerPermit;
public:
	Admin() // No-Argument Constructor Defined
	{
		riderPermit = "";
		restaurantPermit = "";
		customerPermit = "";
	}
	void setLoginDetails(int loginID, string password, string user)
	{
		LoginSystem::setLoginID(loginID);
		LoginSystem::setPassword(password);
		LoginSystem::setUser(user);
	}
	void setRiderPermit()
	{
		cout << "Rider wants your permission regarding this operation.\nType Yes/No\n\nEnter the Choice : ";
		cin.ignore();
		getline(cin, riderPermit);
	}
	void setRestaurantPermit()
	{
		cout << "Restaurant wants your permission regarding this operation.\nType Yes/No\n\nEnter the Choice : ";
		cin.ignore();
		getline(cin, restaurantPermit);
	}
	void setCustomerPermit()
	{
		cout << "Customer wants your permission regarding this operation.\nType Yes/No\n\nEnter the Choice : ";
		cin.ignore();
		getline(cin, customerPermit);
	}
};

#endif