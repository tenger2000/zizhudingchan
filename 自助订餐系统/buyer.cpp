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
	cout << "|" << setfill('*') << setw(29) << "��ӭ " << this->m_Uname << " ��¼" << setfill('*') << setw(22) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "1����ʼ���" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "2���������" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "3��ȡ������" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "4����ַ����" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "5���޸�����" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "0���˳��˺�" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << "��ѡ�����ı�ţ�";
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
	cout << "��������Ҫȡ���Ķ������:";
	cin >> orderid;
	Cancel(orderid);
}

void buyer::addressManagemen()
{
	this->Addaddress();
}

void buyer::ChangPswd()
{
}


