#include "menu.h"

Menu::Menu()
{
}

Menu::Menu(string dishName, string dishID, double price)
{
	this->dishName = dishName;
	this->price = price;
}

void Menu::VMenu()
{
	char buf[1024] = { '\0' };
	ifstream ifs;
	ifs.open("menu.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "file not exist." << endl;
		ifs.close();
		ofstream fout("menu.txt");
		if (fout)
		{
			cout << "����ϵ������Ա��Ӳ˵�" << endl;
			system("pause");
			return;
		}
	}
	string ID, name, price;
	cout << "���" << setfill(' ') << setw(8) << "����" << setw(8) << "�۸�" << endl;
	while (ifs.peek()!=EOF)
	{
		ifs >> ID && ifs >> name && ifs >> price;
		cout << left;
		cout << setw(8) << ID << setw(8) << name << setw(8) << price << endl;
	}
}

