#pragma once
#include"person.h"
#include<string>
#include<vector>
#include<fstream>
#include <functional>
#include <algorithm>

using namespace std;
class address:public Person
{
public:
	string Address, mPhoneNo;
	int ID;
	address();
	void viewaddress();
	void Addaddress();
	void initaddress();
	void Chgaddress();
	vector<address> m_Vaddress,m_Alladdress;


};

