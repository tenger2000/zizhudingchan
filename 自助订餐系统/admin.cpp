#include "admin.h"

admin::admin()
{
	initialVector();
}

admin::admin(string Uname, string pwd)
{
	this->m_Uname = Uname;
	this->m_Pwd = pwd;
	this->initialVector();
}
void admin::operMenu()
{
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << "|" << setfill('*') << setw(29) << "��ӭ " << this->m_Uname << " ��¼" << setfill('*') << setw(22) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "1��������" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "2�����Ա��" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "3������˵�" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "4���������" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "5�����Ա��" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "0���˳��˺�" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << "��ѡ�����ı�ţ�";
}
void printbuyer(buyer& buyer) {
	cout << "�û�ID��" << buyer.m_SID << "\t�û���:" << buyer.m_Uname << "\t����:" << buyer.m_Pwd << endl;
}

void printseller(seller& seller) {
	cout << "�û�ID��" << seller.m_SID << "\t�û���:" << seller.m_Uname << "\t����:" << seller.m_Pwd << endl;
}


void admin::addPerson(Person* p)
{
	while (true) {
		cout << setfill('-') << setw(62) << "-" << endl;
		cout << "|" << setfill('*') << setw(35) << "1��ע���˺�" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "0���˳�ע��" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(61) << "|" << endl;
		cout << setfill('-') << setw(62) << "-" << endl;
		cout << "��ѡ�����ı��:";
		int choose, id;
		string filename = "";
		cin >> choose;
		while (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
			cout << "������������������ţ�";
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			if (p == NULL)
				filename = "buyer.txt";
			else
				filename = "employee.txt";
			break;
		case 0:
			return;
			break;
		default:
			cout << "������ı�Ŵ�������������" << endl;
			break;
		}
		ofstream ofs;
		ofs.open(filename, ios::out | ios::app);
		string name, pswd;
		do {
			cout << "����������������";
			cin >> name;
			cout << "�������������룺";
			cin >> pswd;
			srand((unsigned)time(0));
			id = rand() % 9000 + 1001;
		}while ((this->checkRepeat(id, choose, name)));
		ofs << id << " " << name << " " << pswd << endl;
		if (!ofs.fail())
		{
			cout << "�˺�ע��ɹ���" << endl;
			ofs.close();
			return;
		}
		else
		{
			cout << "�˺�ע��ʧ�ܣ�������ע��!" << endl;
		}
	}
	return;
}

void admin::viewAllMenu(int choose)
{
		switch (choose)
		{
		case 1:
			cout << "��������б�" << endl;
			for_each(this->m_Vbuyer.begin(), this->m_Vbuyer.end(), printbuyer);
			break;
		case 2:
			cout << "����Ա���б�" << endl;
			for_each(this->m_Vseller.begin(), this->m_Vseller.end(), printseller);
			break;
		case 3:
			viewMenu();
			break;
		case 4:
			viewMenu();
			break;
		default:
			break;
		}
}

void admin::viewComRomInfo()
{
}

void admin::cleanResRecord()
{
}

void admin::initialVector()
{
	this->m_Vbuyer.clear();
	this->m_Vseller.clear();
	this->m_Vmenu.clear();
	this->m_Vorder.clear();
	ifstream ifs;
	ifs.open("buyer.txt", ios::in);
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
		while (ifs >> B.m_SID && ifs >> B.m_Uname && ifs >> B.m_Pwd)
		{
			m_Vbuyer.push_back(B);
		}
	}
	ifs.close();
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

bool admin::checkRepeat(int id, int type, string name)
{
	switch (type)
	{
	case 1:
		for (vector<buyer>::iterator it = m_Vbuyer.begin(); it != m_Vbuyer.end(); it++)
		{
			if (id == it->m_SID || name == it->m_Uname)
			{
				cout << "ID�������ظ�������������" << endl;
				return true;
			}
		}
		break;
	case 2:
		for (vector<seller>::iterator it = m_Vseller.begin(); it != m_Vseller.end(); it++)
		{
			if (id == it->m_SID || name == it->m_Uname)
			{
				cout << "ID�������ظ�������������" << endl;
				return true;
			}
		}
		break;
	default:
		return true;
		break;
	}
	return false;
}
