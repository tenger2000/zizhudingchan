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

