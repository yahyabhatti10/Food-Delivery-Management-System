#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>

#include"Functions.h"
#include"Admin.h"
#include"Login System.h"
#include"Food System.h"
#include"OrderCart.h"
#include"Restaurant.h"
#include"Customer.h"
#include"Rider.h"

using namespace std;

int main()
{
	Admin a1;
	Restaurant r1;
	Customer c1;
	Rider d1;
	FoodSystem f1;
	r1.setFoodSystem();
	f1.setFoodSystem();
	
	// ADMIN LOGIN DETAILS
	a1.setLoginID(786);
	a1.setPassword("admin786");
	a1.setUser("Admin");

	// RESTAURANT LOGIN DETAILS
	r1.setLoginID(123);
	r1.setPassword("rest123");
	r1.setUser("Restaurant");

	// CUSTOMER LOGIN DETAILS
	c1.setLoginID(456);
	c1.setPassword("customer456");
	c1.setUser("Customer");

	// RIDER LOGIN DETAILS
	d1.setLoginID(852);
	d1.setPassword("rider852");
	c1.setUser("Rider");

	int loginID;
	string password;
	int userCommand;
	int choice;


	while (true)
	{
		cout << "\t- W E L C O M E    T O    F O O D    D E L I V E R Y    M A N A G E M E N T    S Y S T E M -\n";
		cout << "\n1. Sign In\n2. Exit\n";
		cout << "\nEnter the Desired Option : ";
		cin >> userCommand;
		system("CLS");

		// ***** LOGIN *****
		if (userCommand == 1)
		{
			cout << "\nEnter the Login ID : ";
			cin >> loginID;
			cin.ignore();
			cout << "Enter the Password : ";
			getline(cin, password);

			// ****************************************************   A D M I N   **********************************************************
			if (loginID == a1.getLoginID() && password == a1.getPassword())
			{
				cout << "\nAdmin Logged In successfully." << endl;
				system("CLS");
			}
			// ****************************************************   R E S T A U R A N T   **********************************************************
			else if (loginID == r1.getLoginID() && password == r1.getPassword())
			{
				cout << "\nRestaurant Logged In successfully." << endl;
				system("CLS");
				cout << "\n\t- W E L C O M E    T O    R E S T A U R A N T    S Y S T E M -" << endl;
			restaurantChoice:
				while (true)
				{
					cout << "\n1. Update Menu\n2. Display Menu\n3. Logout\n";
					cout << "\nEnter the Desired Option : ";
					cin >> choice;
					if (choice == 1)
					{
						r1.updateMenu();

					}
					else if (choice == 2)
					{
						r1.displayMenu();
					}
					else if (choice == 3)
					{
						cout << "\nRestaurant Logged Out successfully." << endl;
						system("CLS");
						break;
					}
					else
					{
						cout << "\n!!! I N V A L I D   I N P U T !!! Please Enter the Correct Input\n";
						goto restaurantChoice;
					}
				}
			}
			// ****************************************************   C U S T O M E R   **********************************************************
			else if (loginID == c1.getLoginID() && password == c1.getPassword())
			{
				cout << "\nCustomer Logged In successfully." << endl;
				system("CLS");
				cout << "\n\t- W E L C O M E    T O    C U S T O M E R    S E R V I C E S -" << endl;
				c1.setName();
				c1.setAddress();
			customerChoice:
				while (true)
				{
					cout << "\n1. Update Order\n2. Logout\n";
					cout << "\nEnter the Desired Option : ";
					cin >> choice;
					if (choice == 1)
					{
						c1.updateOrder(f1);
					}
					else if (choice == 2)
					{
						cout << "\nCustomer Logged Out successfully." << endl;
						system("CLS");
						break;
					}
					else
					{
						cout << "\n!!! I N V A L I D   I N P U T !!! Please Enter the Correct Input\n";
						goto customerChoice;
					}
				}

			}
			// ****************************************************   R I D E R   **********************************************************
			else if (loginID == d1.getLoginID() && password == d1.getPassword())
			{
				cout << "\nRider Logged In successfully." << endl;
				system("CLS");
				cout << "\n\t- W E L C O M E    T O    R I D E R    S Y S T E M -" << endl;

			riderChoice:
				while (true)
				{
					cout << "\n1. Deliver\n2. Logout\n";
					cout << "\nEnter the Desired Option : ";
					cin >> choice;
					if (choice == 1)
					{
						d1.riderSystem(c1, f1);
					}
					else if (choice == 2)
					{
						cout << "\nRider Logged Out successfully." << endl;
						system("CLS");
						break;
					}
					else
					{
						cout << "\n!!! I N V A L I D   I N P U T !!! Please Enter the Correct Input\n";
						goto riderChoice;
					}
				}

			}
			else
			{
				cout << "\n!!! I N V A L I D   L O G I N !!! Please Enter the Correct ID and Password.\n";
			}
		}
		// ***** EXIT *****
		else if (userCommand == 2)
		{
			break;
		}
		// ***** INVALID INPUT *****
		else
		{
			cout << "\n!!! I N V A L I D   I N P U T !!! Please Enter the Correct Input\n";
		}
	}

	return 0;
}

