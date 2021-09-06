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
	cout << "菜品ID：" << menu.dishID << "\t菜品名:" << menu.dishName << "\t单价:" << menu.price << endl;
}

bool Menu::checkRepeat(string id, string dishname) {
	for (vector<Menu>::iterator  i =m_Vmenu.begin(); i != m_Vmenu.end(); i++)
	{
		if (id==i->dishID||dishname==i->dishName)
		{
			cout << "ID或菜品名称重复，请重新输入" << endl;
			return true;
		}
	}
	return false;
}

void Menu::viewMenu()
{
	initMenu();
	cout << "所有菜品列表：" << endl;
	for_each(m_Vmenu.begin(), m_Vmenu.end(), printmenu);
}

void Menu::addMenu()
{
	ofstream ofs;
	ofs.open("menu.txt", ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		ofs.close();
		return;
	}
	string id;
	string tempdishname, tempdishprice;
	do {
		cout << "请输入菜品名称：";
		cin >> tempdishname;
		cout << "请输入菜品单价：";
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
		cout << "文件打开失败" << endl;
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



