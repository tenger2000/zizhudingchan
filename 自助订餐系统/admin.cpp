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
	cout << "|" << setfill('*') << setw(29) << "»¶Ó­ " << this->m_Uname << " µÇÂ¼" << setfill('*') << setw(22) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "1¡¢ä¯ÀÀÂò¼Ò" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "2¡¢ä¯ÀÀÔ±¹¤" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "3¡¢ä¯ÀÀ²Ëµ¥" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "4¡¢ä¯ÀÀ¶©µ¥" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "5¡¢Ìí¼ÓÔ±¹¤" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(35) << "0¡¢ÍË³öÕËºÅ" << setfill('*') << setw(26) << "|" << endl;
	cout << "|" << setfill('*') << setw(61) << "|" << endl;
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << "ÇëÑ¡ÔñÄúµÄ±àºÅ£º";
}
void admin::addPerson(Person* p)
{
	while (true) {
		cout << setfill('-') << setw(62) << "-" << endl;
		cout << "|" << setfill('*') << setw(35) << "1¡¢×¢²áÕËºÅ" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(35) << "0¡¢ÍË³ö×¢²á" << setfill('*') << setw(26) << "|" << endl;
		cout << "|" << setfill('*') << setw(61) << "|" << endl;
		cout << setfill('-') << setw(62) << "-" << endl;
		cout << "ÇëÑ¡ÔñÄúµÄ±àºÅ:";
		int choose, id;
		string filename = "";
		cin >> choose;
		while (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
			cout << "ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë±àºÅ£º";
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
			cout << "ÄúÊäÈëµÄ±àºÅ´íÎó£¬ÇëÖØÐÂÊäÈë" << endl;
			break;
		}
		ofstream ofs;
		ofs.open(filename, ios::out | ios::app);
		string name, pswd;
		do {
			cout << "ÇëÊäÈëÄúµÄÐÕÃû£º";
			cin >> name;
			cout << "ÇëÊäÈëÄúµÄÃÜÂë£º";
			cin >> pswd;
			srand((unsigned)time(0));
			id = rand() % 9000 + 1001;
		}while ((this->checkRepeat(id, choose, name)));
		ofs << id << " " << name << " " << pswd << endl;
		if (!ofs.fail())
		{
			cout << "ÕËºÅ×¢²á³É¹¦£¡" << endl;
			ofs.close();
			return;
		}
		else
		{
			cout << "ÕËºÅ×¢²áÊ§°Ü£¬ÇëÖØÐÂ×¢²á!" << endl;
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
				cout << "ID»òÐÕÃûÖØ¸´£¬ÇëÖØÐÂÊäÈë" << endl;
				return true;
			}
		}
		break;
	case 2:
		for (vector<seller>::iterator it = m_Vseller.begin(); it != m_Vseller.end(); it++)
		{
			if (id == it->m_SID || name == it->m_Uname)
			{
				cout << "ID»òÐÕÃûÖØ¸´£¬ÇëÖØÐÂÊäÈë" << endl;
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
