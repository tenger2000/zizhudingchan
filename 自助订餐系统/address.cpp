#include "address.h"


address::address()
{
}

void printaddress(address& address)
{
	cout <<address.ID<< "\t������" << address.m_Uname << "\t��ַ:" << address.Address << "\t�绰 : " << address.mPhoneNo << endl;
}

void address::viewaddress()
{
	cout << "���е�ַ�б�" << endl;
	for_each(m_Vaddress.begin(), m_Vaddress.end(), printaddress);
}

void address::Addaddress()
{
	char Q;
	cout << "�����������ջ���ַ��";
	cin >> Address;
	cout << "������������ϵ�绰��";
	cin >> mPhoneNo;
	cout << "��ȷ����ĵ�ַ�Ƿ���ȷ��" << endl;
	cout << this->m_Uname << "\t" << Address << "\t" << mPhoneNo << endl;
	cout << "��ȷ������Y\t����������N" << endl;
	cin >> Q;
	while (!(Q == 'Y' || Q == 'N' || Q == 'y' || Q == 'n'))
	{
		cin.clear();
		while (cin.get() != '\n') {
			continue;
		}
		cout << "������������������ţ�";
		cin >> Q;
	}
	if (Q == 'Y' || Q == 'y')
	{
		ofstream ofs;
		int serialnumber;
		serialnumber = m_Vaddress.size() + 1;
		ofs.open("address.txt", ios::app);
		ofs << serialnumber +"��\t" << this->m_Uname << "\t" << Address << "\t" << mPhoneNo << endl;
		ofs.close();
	}
	return;
}

void address::initaddress()
{
	ifstream ifs;
	ifs.open("address.txt", ios::beg);
	m_Vaddress.clear();
	m_Alladdress.clear();
	if (!ifs.is_open())
	{
		cout << "address.txt��ʧ��" << endl;
		ifs.close();
		ofstream fout("address.txt");
		return;
	}
	address A;
	while (ifs >> A.ID && ifs >> A.m_Uname && ifs >> A.Address && ifs >> A.mPhoneNo)
	{
		if (this->m_Uname == A.m_Uname)
			m_Vaddress.push_back(A);
		m_Alladdress.push_back(A);
	}
	ifs.close();
}

void address::Chgaddress()
{
	viewaddress();
	int choose;
	ofstream ofs;
	ofs.open("address.txt", ios::beg);
	cout << "��������Ҫ�޸ĵĵ�ַ��ţ�";
	cin >> choose;
	for (vector<address>::iterator it = m_Alladdress.begin(); it != m_Alladdress.end(); it++)
	{
		if (it->ID==choose)
		{
			cout << "�����������ջ���ַ��";
			cin >> it->Address;
			cout << "������������ϵ�绰��";
			cin >> it->mPhoneNo;
		}
		ofs << it->ID << "\t" << it->m_Uname << "\t" << it->Address << "\t" << it->mPhoneNo << endl;
	}
	ofs.close();
}
