#pragma once
#include<iostream>
#include<vector>
#include "person.h"
#include<fstream>
#include"menu.h"
#include<string>
#include<iomanip>



using namespace std;

//Order类存有用户名，地址，电话，数量，日期，确认状态 
class Order :public Menu,Person
{
private:
	string customerName, adress, phone;
	int num;
	Date bookDate;
	bool modify;
public:
	Order();
	Order(string dishName, string dishID, double price, string customerName, string adress, string phone, Date bookDate);
	Order(string dishName, string dishID, double price);
	Order(Menu, int);
	const bool operator==(Order order2);
	string getCustomerName();
	string getAdress();
	string getPhone();
	Date getBookDate();
	bool getModify();
	int getNum();
	bool setCustomerName(string customerName);
	bool setAdress(string adress);
	bool setPhone(string phone);
	bool setnum(int num);
	bool setBookDate(Date bookDate);
	void setModify();
};

