#pragma once
#include<iostream>
#include<vector>
#include"Order.h"
#include<fstream>
#include<string>
#include<iomanip>


using namespace std;





class buyer:public Order
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
	void ChangPswd();
};
