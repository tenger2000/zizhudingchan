#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<iomanip>
#include"person.h"
#include<vector>

using namespace std;

//���������࣬�������ռ�Сʱ 
class Date
{
public:
	int year, month, day, hour;
	Date();
	Date(int y, int m, int d, int h);
};

class Menu:public Person
{
public:
	string dishName, dishID;
	double price;
	Menu();
	Menu(string dishName, string dishID, double price);
	virtual void operMenu();

};




