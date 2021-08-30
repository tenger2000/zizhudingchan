#pragma once
#include<iostream>
#include"person.h"
#include<string>
#include<fstream>
#include<vector>
#include"buyer.h"
#include"seller.h"
#include"Order.h"
#include"menu.h"
#include"address.h"
#include<algorithm>
#include<iomanip>

using namespace std;









class admin :public buyer
{
public:
	//default struct
	admin();
	//struct with parameter
	admin(string Uname, string pwd);
	virtual void operMenu();
	//add Person
	void addPerson(Person*p);
	//view computer room info
	void Viewbuyer();
	void Viewseller();
	void viewComRomInfo();
	// clean reservation record
	void cleanResRecord();
	// initialize stu and teacher vector 
	void initialVector();
	// check repeat account
	bool checkRepeat(int id, int type,string name);

	vector<buyer> m_Vbuyer;
	vector<seller> m_Vseller;
	vector<Order> m_Vorder;
	vector<Menu> m_Vmenu;
	vector<address> m_Vaddress;
};

