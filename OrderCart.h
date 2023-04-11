#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include "Food System.h"
using namespace std;
#ifndef OrderCart_H
#define OrderCart_H
class OrderCart
{
protected:
	string items[20];
	int itemsQuantity[20];
	double totalBill;
public:
	friend class Admin;
	OrderCart() // No-Argument Constructor Defined
	{
		for (int i = 0; i < 20; i++)
		{
			items[i] = "";
			itemsQuantity[i] = 0;
		}
		totalBill = 0.0;
	}
	double calculateBill(FoodSystem& f)
	{
		double billAmount = 0.0;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (items[i] == f.dishes[j])
				{
					billAmount += (itemsQuantity[i] * f.dishesPrice[j]);
				}
				else if (items[i] == f.drinks[j])
				{
					billAmount += (itemsQuantity[i] * f.drinksPrice[j]);
				}
			}
		}
		return billAmount;
	}
	double calculateDeliveryTime(FoodSystem& f)
	{
		double deliveryTime = 0.0;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (items[i] == f.dishes[j])
				{
					if (f.dishesReadyTime[j] > deliveryTime)
					{
						deliveryTime = f.dishesReadyTime[j];
					}
				}
			}
		}
		deliveryTime += 15.0;
		return deliveryTime;
	}
	void displayOrder(FoodSystem& f)
	{
		cout << "\n\t          - Your Order -" << endl;
		cout << "\n\t-ITEMS-\t\t\t   -QUANTITY-\n\n";
		for (int i = 0; i < 20; i++)
		{
			if (items[i] != "")
			{
				cout << i + 1 << ". \t " << items[i] << "\t\t\t\t" << itemsQuantity[i] << endl;
			}
		}
		cout << "\n\nTotal Bill : " << totalBill << endl;
		cout << "Expected Delivery Time : " << calculateDeliveryTime(f) << " minutes" << endl;
		cout << "\nYour order will be delivered to you in shortly. Thank you for ordering. Have a nice day :)" << endl;
	}
	void order(FoodSystem& f)
	{
		int itemIndex = 0;
		bool check;
		int orderMore;
		cout << "\n\t\t     - Order -\n";
		for (int i = 0; i < 20; i++)
		{
			if (items[i] == "")
			{
			itemNameInput:
				cout << "\nEnter the Item Name : ";
				cin.ignore();
				getline(cin, items[i]);
				check = itemCheck<string>(f.dishes, items[i]);
				if (check == true)
				{
					goto itemQuantityInput;
				}
				check = itemCheck<string>(f.drinks, items[i]);
				if (check == false)
				{
					cout << "\n~ Could not find the Item. Make sure you are writing it's name correctly." << endl;
					goto itemNameInput;
				}
			itemQuantityInput:
				cout << "Enter the Item Quantity : ";
				cin >> itemsQuantity[i];
				itemIndex = findItemIndex<string>(f.dishes, items[i]);
				if (itemIndex == -1)
				{
					itemIndex = findItemIndex<string>(f.drinks, items[i]);
				}
				if (itemsQuantity[i] > f.dishesQuantity[itemIndex])
				{
					cout << "\n~ Limited Stock Available. Make sure you are entering the quantity meansetting of Stock available." << endl;
					goto itemQuantityInput;
				}
			orderMore:
				cout << "\nDo you want to Order something else ? \n1. Yes\n2. No\nEnter the Choice : ";
				cin >> orderMore;
				if (orderMore == 1)
				{
					continue;
				}
				else if (orderMore == 2)
				{
					break;
				}
				else
				{
					cout << "\nInvalid Input ! Please enter the Correct Option." << endl;
					goto orderMore;
				}
			}
		}
		cout << "\nOrder placed Successfully." << endl;
		totalBill = calculateBill(f);
		displayOrder(f);
	}
};
#endif