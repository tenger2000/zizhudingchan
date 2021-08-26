#include "Order.h"

Order::Order()
{
}

Order::Order(string dishname, int quantity, double price, string name, string address, string mphone)
{
	this->dishName = dishname;
	this->quantity = quantity;
	this->price = price;
	this->m_Uname = name;
	this->Address = address;
	this->mPhoneNo = mphone;
	this->totalprice = quantity * price;
}



void Order::addOrder(string name)
{
	this->m_Uname = name;
	string ordername;
	ordername =name + ".txt";
	ofstream ofs;
	ofs.open(ordername,ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		ofs.close();
		return;
	}
	viewMenu();
	string tempdishID, tempquantity, tempdishname, tempdishprice;
	while (true)
	{
		cout << "请输入您需要的菜品ID：";
		cin >> tempdishID;
		cout << "请输入您需要的菜品份数：";
		cin >> tempquantity;
		if (tempdishID == "0")
			break;
		for (vector<Menu>::iterator i = Vmenu.begin(); i != Vmenu.end(); i++)
		{
			if (tempdishID == i->dishID)
			{
				tempdishname = i->dishName; tempdishprice = i->price;
			}
		}
		ofs << tempdishID << "\t" << tempdishname << "\t" << tempdishprice << "\t" << tempquantity;
	}
	
	ofs.close();
	cout << OrderDate();
}

string Order::OrderDate()
{
	struct tm newtime;
	char *tmpbuf=new char[128];
	string buf;
	time_t lt1;

	time(&lt1);
	localtime_s(&newtime, &lt1);

	strftime(tmpbuf, 128, "%F, %T\n", &newtime);
	buf = string(tmpbuf);
	return buf;
}

