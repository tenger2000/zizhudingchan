#include "seller.h"

seller::seller()
{
	
}

seller::seller(int id, string Uname, string Upswd)
{
	this->m_SID = id;
	this->m_Uname = Uname;
	this->m_Pwd = Upswd;
	initbuyer();
}
void printseller(seller& seller) {
	cout << "�û�ID��" << seller.m_SID << "\t�û���:" << seller.m_Uname << "\t����:" << seller.m_Pwd << endl;
}
void seller::operMenu()
{
}

void seller::viewseller()
{
	cout << "����Ա���б�" << endl;
	for_each(this->m_Vseller.begin(), this->m_Vseller.end(), printseller);
}

void seller::initseller()
{
	m_Vseller.clear();
	ifstream ifs;
	ifs.open("employee.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		ofstream fout("employee.txt");
		return;
	}
	else
	{
		seller S;
		while (ifs >> S.m_SID && ifs >> S.m_Uname && ifs >> S.m_Pwd)
		{
			m_Vseller.push_back(S);
		}
	}
	ifs.close();
}
