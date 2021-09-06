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
	cout << "�û�ID��" << buyer.m_SID << "\t�û���:" << buyer.m_Uname << "\t����:" << buyer.m_Pwd << endl;
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
	cout << "1����ӵ�ַ" << endl;
	cout << "2���޸ĵ�ַ" << endl;
	cout << "�������ţ�";
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
	cout << "����������ԭʼ���룺";
	cin >> temppswd;
	ofstream ofs;
	ofs.open("buyer.txt", ios::out || ios::beg);
	for (vector<buyer>::iterator it = this->m_Vbuyer.begin(); it != this->m_Vbuyer.end(); it++)
	{
		if (it->m_Uname == this->m_Uname && it->m_Pwd == temppswd)
		{
			cout << "���������������룺";
			cin >> temppswd;
			it->m_Pwd = temppswd;
		}
		else if (it->m_Uname == this->m_Uname && it->m_Pwd != temppswd)
		{
			cout << "������������������������룡������";
			ofs.close();
			break;
		}
		ofs << it->m_SID << "\t" << it->m_Uname << "\t" << it->m_Pwd << endl;
	}
	ofs.close();
}

void buyer::viewbuyer()
{
	cout << "��������б�" << endl;
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
		cout << "�ļ���ʧ��" << endl;
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


