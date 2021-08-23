#pragma once
#include<iostream>

using namespace std;




class Person {
public:
	//operator menu
	virtual void operMenu() { return; }
	string m_Uname;
	string m_Pwd;
	int m_SID;
};