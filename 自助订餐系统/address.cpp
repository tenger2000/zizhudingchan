#include "address.h"


address::address()
{
}

void printaddress(address& address)
{
	cout <<address.ID<< "\t姓名：" << address.m_Uname << "\t地址:" << address.Address << "\t电话 : " << address.mPhoneNo << endl;
}

void address::viewaddress()
{
	cout << "所有地址列表：" << endl;
	for_each(m_Vaddress.begin(), m_Vaddress.end(), printaddress);
}

void address::Addaddress()
{
	char Q;
	cout << "请输入您的收货地址：";
	cin >> Address;
	cout << "请输入您的联系电话：";
	cin >> mPhoneNo;
	cout << "请确认你的地址是否正确！" << endl;
	cout << this->m_Uname << "\t" << Address << "\t" << mPhoneNo << endl;
	cout << "正确请输入Y\t错误请输入N" << endl;
	cin >> Q;
	while (!(Q == 'Y' || Q == 'N' || Q == 'y' || Q == 'n'))
	{
		cin.clear();
		while (cin.get() != '\n') {
			continue;
		}
		cout << "输入错误，请重新输入编号：";
		cin >> Q;
	}
	if (Q == 'Y' || Q == 'y')
	{
		ofstream ofs;
		int serialnumber;
		serialnumber = m_Vaddress.size() + 1;
		ofs.open("address.txt", ios::app);
		ofs << serialnumber +"、\t" << this->m_Uname << "\t" << Address << "\t" << mPhoneNo << endl;
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
		cout << "address.txt打开失败" << endl;
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
	cout << "请输入需要修改的地址编号：";
	cin >> choose;
	for (vector<address>::iterator it = m_Alladdress.begin(); it != m_Alladdress.end(); it++)
	{
		if (it->ID==choose)
		{
			cout << "请输入您的收货地址：";
			cin >> it->Address;
			cout << "请输入您的联系电话：";
			cin >> it->mPhoneNo;
		}
		ofs << it->ID << "\t" << it->m_Uname << "\t" << it->Address << "\t" << it->mPhoneNo << endl;
	}
	ofs.close();
}
