#include "Order.h"

Order::Order()
{
}

Order::Order(string dishID, string dishname, double dishprice, string name, string address, string mphone)
{
	this->dishID = dishID;
	this->dishName = dishname;
	this->price = dishprice;
	this->m_Uname = name;
	this->Address = address;
	this->mPhoneNo = mphone;
}



Order::Order(string name)
{
	this->m_Uname = name;
	VMenu();
	cout << "请输入您需要的菜品ID：";
	cin >> this->dishID;

	cout << OrderDate();
}

char* Order::OrderDate()
{
	struct tm newtime;
	char *tmpbuf=new char[128];
	time_t lt1;

	time(&lt1);
	localtime_s(&newtime, &lt1);

	strftime(tmpbuf, 128, "%F, %T\n", &newtime);
	return tmpbuf;
}

