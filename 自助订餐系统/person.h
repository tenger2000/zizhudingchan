#pragma once
#include<iostream>

using namespace std;




class Person {
public:
	//operator menu
	virtual void operMenu() = 0;
	string m_Uname;
	string m_Pwd;
};