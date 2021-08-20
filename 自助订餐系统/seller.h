#pragma once
#include<iostream>
#include<vector>
#include "person.h"
#include<fstream>
#include<string>
#include<iomanip>


using namespace std;





class seller:public Person
{
public:
	seller();
	seller(int id, string Uname, string pwd);
	virtual void operMenu();
	int m_SID;
};

