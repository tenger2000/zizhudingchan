#include "address.h"


address::address()
{
}

void printaddress(address& address)
{
	cout << "������" << address.m_Uname << "\t��ַ:" << address.Address << "\t�绰:" << address.mPhoneNo << endl;
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
		ofs.open("address.txt", ios::app);
		ofs << this->m_Uname << "\t" << Address << "\t" << mPhoneNo << endl;
		ofs.close();
	}
	return;





}

void address::intiaddress()
{
	ifstream ifs;
	m_Vaddress.clear();
	ifs.open("address.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		ofstream fout("address.txt");
		return;
	}
	address A;
	while (ifs >> A.m_Uname && ifs >> A.Address && ifs >> A.mPhoneNo)
	{
		if (this->m_Uname == A.m_Uname)
			m_Vaddress.push_back(A);
	}
	ifs.close();
}
