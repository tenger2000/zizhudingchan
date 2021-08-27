#pragma once
#include"person.h"
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>

using namespace std;
class address:public Person
{
public:
	string Address, mPhoneNo;
	address();
	void viewaddress();
	void Addaddress();
	void intiaddress();
	vector<address> m_Vaddress;


};

