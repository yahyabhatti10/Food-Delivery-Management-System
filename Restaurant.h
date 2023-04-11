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
using namespace std;
#ifndef Restaurant_H
#define Restaurant_H
class Restaurant : public FoodSystem, public Admin
{
protected:
	int noOfOrders;
	double orderTime;
	string orderStatus;
public:
	friend class Admin;

	Restaurant() // No-Argument Constructor Defined
	{
		noOfOrders = 0;
		orderTime = 0.0;
		orderStatus = "";
	} // Constructor ends here.
	void setLoginDetails(int loginID, string password, string user)
	{
		LoginSystem::setLoginID(loginID);
		LoginSystem::setPassword(password);
		LoginSystem::setUser(user);
	}
	void setOrderTime(double t)
	{
		orderTime = t;
	}
	void setOrderStatus(string s)
	{
		orderStatus = s;
	}
	double getOrderTime()
	{
		return orderTime;
	}
	string getOrderStatus()
	{
		return orderStatus;
	}
	void updateMenu()
	{
		int operationCommand;
		int updateAgain;
		cout << "\n\t\t  - UPDATE MENU -" << endl;
	updateMenu:
		cout << "\n1. Add New Dish\n2. Add New Drink\n3. Delete Current Dish\n4. Delete Current Drink\n5. Update Current Dish\n6. Update Current Drink\n7. Exit" << endl;
	operationInput:
		cout << "\n\nEnter the Operation you want to perform : ";
		cin >> operationCommand;
		if (operationCommand < 1 || operationCommand>7) // Checking the input of OperationCommand is valid or not.
		{
			cout << "\nInvalid Input! Please enter the valid input." << endl;
			goto operationInput;
		}
		string itemCommand;
		int itemQuantityCommand;
		double itemPriceCommand;
		double itemReadyTimeCommand;
		//*******************ADD NEW DISH*******************
		if (operationCommand == 1)
		{
			cout << "\n\t\t - ADD NEW DISH -" << endl;
		addDish:
			cout << "\nName of Dish : ";
			cin.ignore();
			getline(cin, itemCommand);
			cout << "Quantity of Dish : ";
			cin >> itemQuantityCommand;
			cin.ignore();
			cout << "Price of Dish : ";
			cin >> itemPriceCommand;
			cin.ignore();
			cout << "Ready Time of Dish : ";
			cin >> itemReadyTimeCommand;
			cin.ignore();
			for (int i = 0; i < 20; i++)
			{
				if (dishes[i] == "" && dishesQuantity[i] == 0 && dishesPrice[i] == 0.0 && dishesReadyTime[i] == 0.0)
				{
					dishes[i] = itemCommand;
					dishesQuantity[i] = itemQuantityCommand;
					dishesPrice[i] = itemPriceCommand;
					dishesReadyTime[i] = itemReadyTimeCommand;
					cout << "\nNew Dish added successfully." << endl;
					break;
				}
			}
			cout << "\n\nDo you want to add more ? \n1. Yes\n2. No";
			cout << "\nEnter the Choice : ";
			cin >> updateAgain;
			if (updateAgain == 1)
			{
				goto addDish;
			}
			else if (updateAgain == 2)
			{
				goto updateMenu;
			}
		}
		//*******************ADD NEW DRINK*******************
		else if (operationCommand == 2)
		{
			cout << "\n\t\t - ADD NEW DRINK -" << endl;
		addDrink:
			cout << "\nName of Drink : ";
			cin.ignore();
			getline(cin, itemCommand);
			cout << "Quantity of Drink : ";
			cin >> itemQuantityCommand;
			cin.ignore();
			cout << "Price of Drink : ";
			cin >> itemPriceCommand;
			cin.ignore();
			for (int i = 0; i < 20; i++)
			{
				if (drinks[i] == "" && drinksQuantity[i] == 0 && drinksPrice[i] == 0.0)
				{
					drinks[i] = itemCommand;
					drinksQuantity[i] = itemQuantityCommand;
					drinksPrice[i] = itemPriceCommand;
					cout << "\nNew Drink added successfully." << endl;
					break;
				}
			}
			cout << "\n\nDo you want to add more ? \n1. Yes\n2. No";
			cout << "\nEnter the Choice : ";
			cin >> updateAgain;
			if (updateAgain == 1)
			{
				goto addDish;
			}
			else if (updateAgain == 2)
			{
				goto updateMenu;
			}
		}
		//*******************DELETE CURRENT DISH*******************
		else if (operationCommand == 3)
		{
			cout << "\n\t\t - DELETE CURRENT DISH -" << endl;
		deleteDish:
			cout << "\nName of Dish : ";
			cin.ignore();
			getline(cin, itemCommand);
			for (int i = 0; i < 20; i++)
			{
				if (dishes[i] == itemCommand)
				{
					deleteElement<string>(dishes, dishes[i]);
					deleteElement<int>(dishesQuantity, dishesQuantity[i]);
					deleteElement<double>(dishesPrice, dishesPrice[i]);
					deleteElement<double>(dishesReadyTime, dishesReadyTime[i]);
					cout << "\Current Dish deleted successfully." << endl;
					break;
				}
			}
			cout << "\n\nDo you want to delete more ? \n1. Yes\n2. No";
			cout << "\nEnter the Choice : ";
			cin >> updateAgain;
			if (updateAgain == 1)
			{
				goto deleteDish;
			}
			else if (updateAgain == 2)
			{
				goto updateMenu;
			}
		}
		//*******************DELETE CURRENT DRINK*******************
		else if (operationCommand == 4)
		{
			cout << "\n\t\t - DELETE CURRENT DRINK -" << endl;
		deleteDrink:
			cout << "\nName of Drink : ";
			cin.ignore();
			getline(cin, itemCommand);
			for (int i = 0; i < 20; i++)
			{
				if (drinks[i] == itemCommand)
				{
					deleteElement<string>(drinks, drinks[i]);
					deleteElement<int>(drinksQuantity, drinksQuantity[i]);
					deleteElement<double>(drinksPrice, drinksPrice[i]);
					cout << "\nCurrent Drink deleted successfully." << endl;
					break;
				}
			}
			cout << "\n\nDo you want to delete more ? \n1. Yes\n2. No";
			cout << "\nEnter the Choice : ";
			cin >> updateAgain;
			if (updateAgain == 1)
			{
				goto deleteDrink;
			}
			else if (updateAgain == 2)
			{
				goto updateMenu;
			}
		}
		//*******************UPDATE CURRENT DISH*******************
		else if (operationCommand == 5)
		{
			int updateDishChoice;
			cout << "\n\t\t- UPDATE CURRENT DISH -" << endl;
			cout << "\nName of Dish : ";
			cin.ignore();
			getline(cin, itemCommand);
			for (int i = 0; i < 20; i++)
			{
				if (dishes[i] == itemCommand)
				{
				updateDish:
					cout << "\n\t\t- Update Choice - ";
					cout << "\n\n1. Name of Dish";
					cout << "\n2. Quantity of Dish";
					cout << "\n3. Price of Dish";
					cout << "\n4. Ready Time of Dish";
					cout << "\n\nEnter the Choice : ";
					cin >> updateDishChoice;
					if (updateDishChoice == 1)
					{
						cout << "\nEnter the New Name : ";
						cin >> dishes[i];
					}
					else if (updateDishChoice == 2)
					{
						cout << "\nEnter the New Quantity : ";
						cin >> dishesQuantity[i];
					}
					else if (updateDishChoice == 3)
					{
						cout << "\nEnter the New Price : ";
						cin >> dishesPrice[i];
					}
					else if (updateDishChoice == 4)
					{
						cout << "\nEnter the New Ready Time : ";
						cin >> dishesReadyTime[i];
					}
					else
					{
						cout << "\nInvalid Input! Please enter the Valid Number as per given choices." << endl;
						goto updateDish;

					}
					cout << "\n\nDo you want to update more ? \n1. Yes\n2. No";
					cout << "\nEnter the Choice : ";
					cin >> updateAgain;
					if (updateAgain == 1)
					{
						goto updateDish;
					}
					else if (updateAgain == 2)
					{
						goto updateMenu;
					}

				}
			}
		}
		//*******************UPDATE CURRENT DISH*******************
		else if (operationCommand == 6)
		{
			int updateDrinkChoice;
			cout << "\n\t\t- UPDATE CURRENT DISH -" << endl;
			cout << "\nName of Dish : ";
			cin.ignore();
			getline(cin, itemCommand);
			for (int i = 0; i < 20; i++)
			{
				if (dishes[i] == itemCommand)
				{
				updateDrink:
					cout << "\n\t\t- Update Choice - ";
					cout << "\n\n1. Name of Dish";
					cout << "\n2. Quantity of Dish";
					cout << "\n3. Price of Dish";
					cout << "\n4. Ready Time of Dish";
					cout << "\n\nEnter the Choice : ";
					cin >> updateDrinkChoice;
					if (updateDrinkChoice == 1)
					{
						cout << "\nEnter the New Name : ";
						cin >> dishes[i];
					}
					else if (updateDrinkChoice == 2)
					{
						cout << "\nEnter the New Quantity : ";
						cin >> dishesQuantity[i];
					}
					else if (updateDrinkChoice == 3)
					{
						cout << "\nEnter the New Price : ";
						cin >> dishesPrice[i];
					}
					else if (updateDrinkChoice == 4)
					{
						cout << "\nEnter the New Ready Time : ";
						cin >> dishesReadyTime[i];
					}
					else
					{
						cout << "\nInvalid Input! Please enter the Valid Number as per given choices." << endl;
						goto updateDrink;
					}
					cout << "\n\nDo you want to update more ? \n1. Yes\n2. No";
					cout << "\nEnter the Choice : ";
					cin >> updateAgain;
					if (updateAgain == 1)
					{
						goto updateDrink;
					}
					else if (updateAgain == 2)
					{
						goto updateMenu;
					}
				}
			}
		}
		else if (operationCommand == 7)
		{
			cout << "\nExiting from Updating Menu." << endl;
		}
	}
};
#endif