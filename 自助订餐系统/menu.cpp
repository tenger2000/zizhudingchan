#include "menu.h"


Menu::Menu()
{

}

Menu::Menu(string dishName, string dishID, double price)
{
	this->dishName = dishName;
	this->price = price;
}

void printmenu(Menu& menu)
{
	cout << "��ƷID��" << menu.dishID << "\t��Ʒ��:" << menu.dishName << "\t����:" << menu.price << endl;
}

bool Menu::checkRepeat(string id, string dishname) {
	for (vector<Menu>::iterator  i =m_Vmenu.begin(); i != m_Vmenu.end(); i++)
	{
		if (id==i->dishID||dishname==i->dishName)
		{
			cout << "ID���Ʒ�����ظ�������������" << endl;
			return true;
		}
	}
	return false;
}

void Menu::viewMenu()
{
	initMenu();
	cout << "���в�Ʒ�б�" << endl;
	for_each(m_Vmenu.begin(), m_Vmenu.end(), printmenu);
}

void Menu::addMenu()
{
	ofstream ofs;
	ofs.open("menu.txt", ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ofs.close();
		return;
	}
	string id;
	string tempdishname, tempdishprice;
	do {
		cout << "�������Ʒ���ƣ�";
		cin >> tempdishname;
		cout << "�������Ʒ���ۣ�";
		cin >> tempdishprice;
		srand((unsigned)time(0));
		id = rand() % 900000 + 100001;
	} while (checkRepeat(id, tempdishname));
	ofs << id << " " << tempdishname << " " << tempdishprice << endl;
}

void Menu::initMenu()
{
	ifstream ifs;
	m_Vmenu.clear();
	ifs.open("menu.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		ofstream fout("menu.txt");
		return;
	}
	Menu m;
	while (ifs >> m.dishID && ifs >> m.dishName && ifs >> m.price)
	{
		m_Vmenu.push_back(m);
	}
	ifs.close();
}



