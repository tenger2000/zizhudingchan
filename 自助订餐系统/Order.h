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

//Order������û�������ַ���绰�����������ڣ�ȷ��״̬ 
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

