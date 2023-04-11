#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;
#ifndef FoodSystem_H
#define FoodSystem_H
class FoodSystem
{
public:
	string dishes[20];
	int dishesQuantity[20];
	double dishesPrice[20];
	double dishesReadyTime[20];
	string drinks[20];
	int drinksQuantity[20];
	double drinksPrice[20];
	FoodSystem() // No-Agrument Constructor Defined
	{
		for (int i = 0; i < 20; i++)
		{
			dishes[i] = "";
			dishesQuantity[i] = 0;
			dishesPrice[i] = 0.0;
			dishesReadyTime[i] = 0.0;
			drinks[i] = "";
			drinksQuantity[i] = 0;
			drinksPrice[i] = 0.0;
		}
	} // Constructor ends here.
	void setFoodSystem()
	{
		dishes[0] = "Burger";
		dishes[1] = "Pizza";
		dishes[2] = "Pasta";
		dishes[3] = "Wrap";
		dishes[4] = "Fries";
		dishes[5] = "Nuggets";
		for (int i = 0; i < 6; i++)
		{
			dishesQuantity[i] = 10;
		}
		dishesPrice[0] = 299.99;
		dishesPrice[1] = 649.99;
		dishesPrice[2] = 249.99;
		dishesPrice[3] = 349.99;
		dishesPrice[4] = 99.99;
		dishesPrice[5] = 149.99;
		dishesReadyTime[0] = 20.0;
		dishesReadyTime[1] = 30.0;
		dishesReadyTime[2] = 20.0;
		dishesReadyTime[3] = 25.0;
		dishesReadyTime[4] = 10.0;
		dishesReadyTime[5] = 15.0;
		//******************DRINKS******************
		drinks[0] = "Coke";
		drinks[1] = "Sprite";
		drinks[2] = "Fanta";
		drinks[3] = "Dew";
		drinks[4] = "Soda";
		drinks[5] = "Water";
		for (int i = 0; i < 6; i++)
		{
			drinksQuantity[i] = 5;
		}
		drinksPrice[0] = 79.99;
		drinksPrice[1] = 79.99;
		drinksPrice[2] = 79.99;
		drinksPrice[3] = 99.99;
		drinksPrice[4] = 69.99;
		drinksPrice[5] = 49.99;
	}
	void displayMenu()
	{
		cout << "\n\t\t\tMENU";
		cout << "\n\tDISHES \t\t\tPRICE \t\t\tSTOCK" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			if (dishes[i] != "")
			{
				cout << i + 1 << ". \t" << dishes[i] << "\t\t\tRs." << dishesPrice[i] << "\t\t" << dishesQuantity[i] << endl;
			}
		}
		cout << "\n\tDRINKS \t\t\tPRICE \t\t\tSTOCK" << endl << endl;
		for (int i = 0; i < 20; i++)
		{

			if (drinks[i] != "")
			{
				cout << i + 1 << ". \t" << drinks[i] << "\t\t\tRs." << drinksPrice[i] << "\t\t" << drinksQuantity[i] << endl;

			}
		}
	}
};
#endif