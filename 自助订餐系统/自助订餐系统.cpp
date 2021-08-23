#include<iostream>
#include<iomanip>
#include<fstream>
#include"person.h"
#include<stdlib.h>
#include"buyer.h"
#include"seller.h"
#include "admin.h"
using namespace std;





void login(string fileName, int type);
void buyermenu(Person* p);
void sellermenu(Person* p);
void adminmenu(Person* p);




int main() {
	while (true) {
		int choose;
		admin* Vadmin=new admin;
		Person* p = NULL;
		cout << setfill('-') << setw(62) << "-" << endl;
		cout << "|" << setfill('*') << setw(40) << "欢迎使用自助订餐系统" << setfill('*') << setw(21) << "|" << endl;
		cout << "|" << setfill('*') << setw(61) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "1、买家登录" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "2、员工登录" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "3、注册账号" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "4、管理账号" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "0、退出系统" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(61) << "|" << endl;
		cout << setfill('-') << setw(62) << "-" << endl;
		cout << "请选择您的编号:";
		cin >> choose;
		while (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
			cout << "输入错误，请重新输入编号：";
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			login("buyer.txt", 1);
			break;
		case 2:
			login("employee.txt", 2);
			break;
		case 3:
			Vadmin->addPerson(p);
			break;
		case 4:
			login("admin.txt", 4);
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "您输入的编号错误，请重新输入" << endl;
			break;
		}
	}
	system("cls");
	return 0;
}


void login(string fileName, int type) {
	while (true)
	{
		Person* p = NULL;
		admin* Vadmin=new admin;
		ifstream ifs;
		ifs.open(fileName, ios::in);
		if (!ifs.is_open())
		{
			cout << "file not exist." << endl;
			ifs.close();
			ofstream fout(fileName);
			if (fout)
			{
				cout << "创建文件成功,请创建账号" << endl;
				system("pause");
				return;
			}
		}
		int temp_id;
		string uName, pswd,temp_Name, temp_pswd;
		cout << "请输入姓名：";
		cin >> uName;
		cout << "请输入密码：";
		cin >> pswd;
		switch (type)
		{
		case 1:
			while(!ifs.eof())
			{
				ifs>>temp_id && ifs >> temp_Name && ifs >> temp_pswd;
				if (uName == temp_Name && pswd == temp_pswd) {
					cout << "登录成功!" << endl;
					p = new buyer(temp_id, temp_Name, temp_pswd);
					buyermenu(p);
					system("cls");
					ifs.close();
					return;
				}
			}
			cout << "用户名或密码输入错误，请重新输入！" << endl;
			ifs.close();
			break;
		case 2:
			while (!ifs.eof())
			{
				ifs >> temp_id && ifs >> temp_Name && ifs >> temp_pswd;
				if (uName == temp_Name && pswd == temp_pswd) {
					cout << "登录成功!" << endl;
					p = new seller(temp_id, temp_Name, temp_pswd);
					sellermenu(p);
					system("cls");
					ifs.close();
					return;
				}
			}
			cout << "用户名或密码输入错误，请重新输入！" << endl;
			ifs.close();
			break;
		case 4:
			ifs >> temp_Name && ifs >> temp_pswd;
			if (uName == temp_Name && pswd == temp_pswd) {
				cout << "登录成功!" << endl;
				p = new admin(temp_Name, temp_pswd);
				adminmenu(p);
				system("cls");
				ifs.close();
				return;
			}
			cout << "用户名或密码输入错误，请重新输入！" << endl;
			ifs.close();
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	return;
}
void buyermenu(Person* p) {
	system("cls");
	p->operMenu();
	buyer* B = (buyer*)p;
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1:
		B->subOrder();
		break;
	case 2:
		B->viewOrder();
		break;
	case 3:
		B->CancelOrder();
		break;
	case 4:
		
		break;
	case 0:
		
		break;
	default:
		break;
	}
	system("cls");
}
void sellermenu(Person* p) {
	p->operMenu();
}
void adminmenu(Person* p) {
	system("cls");
	while (true)
	{
		p->operMenu();
		admin* A = (admin*)p;
		int choose;
		cin.clear();
		while (cin.get() != '\n') {
			continue;
		}
		cin >> choose;
		A->viewAllPerson(choose);
	}
}