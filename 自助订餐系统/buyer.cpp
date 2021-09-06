#include "buyer.h"






buyer::buyer() {

}

buyer::buyer(int id, string Uname, string pwd) {
	this->m_SID = id;
	this->m_Uname = Uname;
	this->m_Pwd = pwd;
	InitOrder();
}
void printbuyer(buyer& buyer) {
	cout << "用户ID：" << buyer.m_SID << "\t用户名:" << buyer.m_Uname << "\t密码:" << buyer.m_Pwd << endl;
}
void buyer::operMenu()
{
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << "|" << setfill('*') << setw(29) << "欢迎 " << this->m_Uname << " 登录" << setfill('*') << setw(22) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "1、开始点菜" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "2、浏览订单" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "3、取消订单" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "4、地址管理" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "5、修改密码" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "0、退出账号" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << "请选择您的编号：";
}
void buyer::subOrder()
{
	this->addOrder();
	system("cls");
}
void buyer::viewOrder()
{
	this->ViewTodayOrder("buyer");
	system("cls");
}
void buyer::CancelOrder()
{
	string orderid;
	this->ViewTodayOrder("buyer");
	cout << "请输入需要取消的订单编号:";
	cin >> orderid;
	Cancel(orderid);
}

void buyer::addressManagemen()
{
	cout << "1、添加地址" << endl;
	cout << "2、修改地址" << endl;
	cout << "请输入编号：";
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		this->Addaddress();
	}
	if (choose == 2)
	{
		this->Chgaddress();
	}
}

void buyer::ChangPswd()
{
	initbuyer();
	string temppswd;
	cout << "请输入您的原始密码：";
	cin >> temppswd;
	ofstream ofs;
	ofs.open("buyer.txt", ios::out || ios::beg);
	for (vector<buyer>::iterator it = this->m_Vbuyer.begin(); it != this->m_Vbuyer.end(); it++)
	{
		if (it->m_Uname == this->m_Uname && it->m_Pwd == temppswd)
		{
			cout << "请输入您的新密码：";
			cin >> temppswd;
			it->m_Pwd = temppswd;
		}
		else if (it->m_Uname == this->m_Uname && it->m_Pwd != temppswd)
		{
			cout << "您输入的密码有误，请重新输入！！！！";
			ofs.close();
			break;
		}
		ofs << it->m_SID << "\t" << it->m_Uname << "\t" << it->m_Pwd << endl;
	}
	ofs.close();
}

void buyer::viewbuyer()
{
	cout << "所有买家列表：" << endl;
	for_each(this->m_Vbuyer.begin(), this->m_Vbuyer.end(), printbuyer);
}

void buyer::initbuyer()
{
	m_Vbuyer.clear();
	InitOrder();
	ifstream ifs;
	ifs.open("buyer.txt", ios::beg);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		ifs.close();
		ofstream fout("buyer.txt");
		return;
	}
	else
	{
		buyer B;
		B.m_Vorder = m_Vorder;
		while (ifs >> B.m_SID && ifs >> B.m_Uname && ifs >> B.m_Pwd)
		{
			m_Vbuyer.push_back(B);
		}
	}
	ifs.close();
}


