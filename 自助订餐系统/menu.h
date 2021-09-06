#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<iomanip>
#include"person.h"
#include<vector>
#include <algorithm>

using namespace std;
class Menu
{
public:
	string dishName, dishID;
	double price;
	Menu();
	Menu(string dishName, string dishID, double price);
	void viewMenu();
	void addMenu();
	void initMenu();
	bool checkRepeat(string id, string dishname);
	vector<Menu> m_Vmenu;
};




