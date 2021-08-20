#pragma once
#include<iostream>
#include<vector>
#include "person.h"
#include"menu.h"
#include<fstream>
#include<string>
#include<iomanip>


using namespace std;





class buyer:public Person
{
public:
	buyer();
	buyer(int id, string Uname, string pwd);
	virtual void operMenu();
	//Add Order
	void subOrder();
	//View Order
	void viewOrder();
	//cancel Order
	void CancelOrder();
	void addressManagemen();
	void chooseAddress();
	int m_SID;
private:

};
