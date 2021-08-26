#pragma once
#include<iostream>
#include<vector>
#include "person.h"
#include"address.h"
#include<fstream>
#include"menu.h"
#include<string>
#include<iomanip>



using namespace std;

//Order类存有用户名，地址，电话，数量，日期，确认状态 
class Order :public Menu,public address
{
public:
	double totalprice;
	int quantity;
	Order();
	Order(string dishname, int quantity,double price,string name,string address,string mphone);
	void addOrder(string name);
	string OrderDate();
	
};

