#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;
#ifndef Functions_H
#define Functions_H
template <class T>
void deleteElement(T array[], T element)
{
	int  total = 20;
	for (int i = 0; i < total; i++)
	{
		if (array[i] == element)
		{
			for (int j = i; j < (total - 1); j++)
			{
				array[j] = array[j + 1];
				i--;
				total--;
			}
		}
	}
}
template <class T>
bool itemCheck(T array[], T item)
{
	bool check = false;
	for (int i = 0; i < 20; i++)
	{
		if (array[i] == item)
		{
			check = true;
			break;
		}
	}
	return check;
}

template <class B>
int findItemIndex(B array[], B item)
{
	int index = -1;
	for (int i = 0; i < 20; i++)
	{
		if (array[i] == item)
		{
			index = i;
			break;
		}
	}
	return index;
}
#endif