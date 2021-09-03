#include "admin.h"

admin::admin()
{
	initseller();
}

admin::admin(string Uname, string pwd)
{
	this->m_Uname = Uname;
	this->m_Pwd = pwd;

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
