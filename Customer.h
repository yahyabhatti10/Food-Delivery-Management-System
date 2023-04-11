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
using namespace std;
#ifndef Customer_H
#define Customer_H
class Customer : public OrderCart, public Admin
{
protected:
	string name;
	string address;
public:
	friend class Rider;
	Customer() // No-Argument Constructor Defined
	{
		name = "";
		address = "";
	}
	void setLoginDetails(int loginID, string password, string user)
	{
		LoginSystem::setLoginID(loginID);
		LoginSystem::setPassword(password);
		LoginSystem::setUser(user);
	}
	void setName()
	{
		cout << "\nEnter the Name : ";
		cin.ignore();
		getline(cin, name);
	}
	void setAddress()
	{
		cout << "Enter the Address : ";
		cin.ignore();
		getline(cin, address);
	}
	string getName()
	{
		return name;
	}
	string getAddress()
	{
		return address;
	}
	void updateOrder(FoodSystem& f)
	{
		int updateCommand;
		int choice;
		string itemCommand;
		cout << "\n\t\t- UPDATE ORDER -\n";
	updateOrder:
		f.displayMenu();
		cout << "\n1. Place New Order\n2. Add New Item\n3. Delete Current Item\n4. Cancel Order\n\nEnter the Choice : ";
		cin >> choice;
		if (choice <= 0 || choice > 4)
		{
			cout << "\n\nInvalid Input !!!. Please Enter the Correct Option.\n";
			goto updateOrder;
		}
		else if (choice == 1)
		{
			order(f);
		}
		else if (choice == 2)
		{
			order(f);
		}
		else if (choice == 3)
		{
			cout << "\nName of Item : ";
			cin.ignore();
			getline(cin, itemCommand);
			for (int i = 0; i < 20; i++)
			{
				if (items[i] == itemCommand)
				{
					deleteElement<string>(items, itemCommand);
					totalBill = totalBill - (f.dishesPrice[i] * itemsQuantity[i]);
					cout << "\Current Item deleted successfully." << endl;
					displayOrder(f);
					break;
				}
			}
		}
		else if (choice == 4)
		{
			for (int i = 0; i < 20; i++)
			{
				items[i] = "";
				itemsQuantity[i] = 0;
				cout << "Your Order has been cancelled.\n";
				break;
			}
			totalBill = 0.0;
		}
		cout << "\n\nDo you want to update more ? \n1. Yes\n2. No";
		cout << "\nEnter the Choice : ";
		cin >> updateCommand;
		if (updateCommand == 1)
		{
			goto updateOrder;
		}
		else if (updateCommand == 2)
		{
			cout << "\nExiting from Update Order.\n";
		}
	}
};
#endif
