#pragma once
#include<iostream>
#include<vector>
#include "person.h"
#include"address.h"
#include<fstream>
#include"menu.h"
#include<string>
#include<iomanip>
#include<map>
#include<shlwapi.h>
#include<io.h>
#include<sstream>
# include <stdlib.h>

#pragma comment(lib, "shlwapi.lib")
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
	void createdir();
	string createdoc(string name);
	string OrderDate();
	map<int,string> mapordername;
};

