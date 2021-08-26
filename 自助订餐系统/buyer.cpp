#include "buyer.h"








buyer::buyer() {

}

buyer::buyer(int id, string Uname, string pwd) {
	this->m_SID = id;
	this->m_Uname = Uname;
	this->m_Pwd = pwd;
	ifstream ifs;
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
	string name =this->m_Uname;
	addOrder(name);
	system("cls");
}
void buyer::viewOrder()
{

}
void buyer::CancelOrder()
{

}

void buyer::addressManagemen()
{
}

void buyer::chooseAddress()
{
}

