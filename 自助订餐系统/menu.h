#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<iomanip>
#include"person.h"
#include<vector>

using namespace std;

//定义日期类，存年月日及小时 
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




