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
	Order();
	Order(string dishID,string dishname,double dishprice,string name,string address,string mphone);
	Order(string name);
	char* OrderDate();

};

