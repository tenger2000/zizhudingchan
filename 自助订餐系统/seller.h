#pragma once
#include<iostream>
#include<vector>
#include "buyer.h"
#include<fstream>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;





class seller:public buyer
{
public:
	seller();
	seller(int id, string Uname, string Upswd);
	virtual void operMenu();
	int m_SID;
	void viewseller();
	void initseller();
	vector<seller> m_Vseller;
};

