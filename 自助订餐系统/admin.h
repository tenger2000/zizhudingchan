#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"seller.h"
#include<algorithm>
#include<iomanip>

using namespace std;









class admin :public seller
{
public:
	//default struct
	admin();
	//struct with parameter
	admin(string Uname, string pwd);
	virtual void operMenu();
	//add Person
	void addPerson(Person*p);
	bool checkRepeat(int id, int type,string name);
};

