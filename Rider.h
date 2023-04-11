#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include"Food System.h"
#include"Admin.h"
#include"Login System.h"
#include"Functions.h"
#include"OrderCart.h"
#include"Restaurant.h"
#include"Customer.h"
using namespace std;
#ifndef Rider_H
#define Rider_H
class Rider : public Admin
{
protected:
	string cashCollectionUpdate;
	string deliveryPermit;
public:
	friend class Customer;
	Rider() // No-Argument Constructor Defined
	{
		cashCollectionUpdate = "";
		deliveryPermit = "";
	}
	void setLoginDetails(int loginID, string password, string user)
	{
		LoginSystem::setLoginID(loginID);
		LoginSystem::setPassword(password);
		LoginSystem::setUser(user);
	}

	void setCashCollectionUpdate()
	{
		cout << "\n\t- Update the Status of Cash Collection - \n\nType Received/In Process\nEnter the Status : ";
		cin.ignore();
		getline(cin, cashCollectionUpdate);
	}
	void setDeliveryPermit()
	{
		cin.ignore();
		cout << "\nAn order came up that needs to be delivered.\nDo you want to deliver this Order ?\nType Yes/No...\n\nEnter the Choice : ";
		cin >> deliveryPermit;
	}

	void riderSystem(Customer& c, FoodSystem& f)
	{
		cout << "\n\t\t- Rider -\n";
	deliveryProcess:
		setDeliveryPermit();
		if (deliveryPermit == "Yes")
		{
			cashCollectionUpdate = "In Process";
			cout << "\n\t- Order Details -\n\n";
			cout << "Customer's Name : " << c.name << endl;
			cout << "Customer's Address : " << c.address << endl;
			c.displayOrder(f);
			cout << "\n\nGood Luck! Make sure you deliver safely :)\n";
			setCashCollectionUpdate();
			cin.ignore();
			if (cashCollectionUpdate == "Received")
			{
				cout << "\nGood Job :) Thank you for your service.\n";
			}
			else if (cashCollectionUpdate == "In Process")
			{
				cout << "\nHurry up! Make sure you deliver on time.\n";
			}
		}
		else if (deliveryPermit == "No")
		{
			cout << "\nOrder Delivery Rejected.\n";
		}
		else
		{
			cout << "~ Invalid Input! Please enter the Correct Option\n";
			goto deliveryProcess;
		}
	}
};
#endif