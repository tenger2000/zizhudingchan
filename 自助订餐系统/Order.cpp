#include "Order.h"

Order::Order()
{
	createdir();
}

Order::Order(string dishname, int quantity, double price, string name, string address, string mphone)
{
	this->dishName = dishname;
	this->quantity = quantity;
	this->price = price;
	this->m_Uname = name;
	this->Address = address;
	this->mPhoneNo = mphone;
	this->totalprice = quantity * price;
}
string OrderDate()
{
	struct tm newtime;
	char* tmpbuf = new char[128];
	string buf;
	time_t lt1;

	time(&lt1);
	localtime_s(&newtime, &lt1);

	strftime(tmpbuf, 128, "%F %T", &newtime);
	buf = string(tmpbuf);
	return buf;
}
string TodayFilePath() {
	string filepath;
	filepath ="./" +OrderDate().substr(0, 10);
	return filepath;
}
void PrintOrder(string filename) {
	ifstream ifs;
	ifs.open(filename, ios::beg);
	string templine;
	while (!ifs.eof())
	{
		getline(ifs, templine);
		cout << templine << endl;
	}
	ifs.close();
}
void Order::createdir() {
	string dir;
	dir = OrderDate().substr(0, 10);
	if (!PathIsDirectory(dir.c_str()))
	{
		::CreateDirectory(dir.c_str(), 0);
	}
}

void getFiles(string path, vector<string>& files)
{
	//文件句柄
	intptr_t  hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
void getJustCurrentFile(string path, vector<string>& files)
{
	//文件句柄 
	intptr_t  hFile = 0;
	//文件信息 
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				//getFiles(path, files);
			}
			else
			{
				files.push_back(fileinfo.name);
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name) ); 
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void Order::addOrder()
{
	string name = this->m_Uname;
	string ordername, orderNO;
	orderNO = OrderDate();
	cout << orderNO << endl;
	ordername = createdoc(name);
	ofstream ofs;
	ofs.open(ordername, ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		ofs.close();
		return;
	}
	viewMenu();
	string tempdishID, tempdishname;
	double tempdishprice, totalprice = 0, tempquantity;
	ofs << "菜品ID" << "\t" << "菜品名称" << "\t" << "菜品单价" << "\t" << "菜品份数" << endl;
	while (true)
	{
		cout << "请输入您需要的菜品ID：";
		cin >> tempdishID;
		if (tempdishID == "0")
			break;
		cout << "请输入您需要的菜品份数：";
		cin >> tempquantity;
		for (vector<Menu>::iterator i = Vmenu.begin(); i != Vmenu.end(); i++)
		{
			if (tempdishID == i->dishID)
			{
				tempdishname = i->dishName; tempdishprice = i->price;
				ofs << tempdishID << "\t" << tempdishname << "\t" << tempdishprice << "\t" << tempquantity << endl;
				totalprice += tempdishprice * tempquantity;
			}
		}
	}
	string tempaddress, tempphone;
	int n = 0, choose;
	do {
		intiaddress();
		for (vector<address>::iterator it = m_Vaddress.begin(); it != m_Vaddress.end(); it++)
		{
			if (name == it->m_Uname)
			{
				n++;
				tempaddress = it->Address; tempphone = it->mPhoneNo;
				cout << n << "、\t" << name << "\t" << tempaddress << "\t" << tempphone << endl;
			}
		}
		if (tempaddress == "")
		{
			cout << "您还没有添加地址，请添加地址！！！" << endl;
			this->Addaddress();
		}
	} while (tempaddress == "");
	cout << "请选择您的地址编号:";
	cin >> choose;
	ofs << "总价" << "\t" << "顾客名称" << "\t" << "地址" << "\t" << "电话" << endl;
	ofs << totalprice << "\t" << name << "\t" << m_Vaddress[choose - 1].Address << "\t" << m_Vaddress[choose - 1].mPhoneNo << endl;
	ofs << OrderDate() << endl;
	ofs.close();
	system("cls");
	cout << "您的订单如下：" << endl;
	PrintOrder(ordername);
	string confirm;
	cout << "请输入 Y/N：";
	cin >> confirm;
	if (confirm != "Y" && confirm != "y")
	{
		remove(ordername.c_str());
	}
}


string Order::createdoc(string name)
{
	string filedoc, file, TodayOrderNO;
	vector<string> files;
	getJustCurrentFile(TodayFilePath(), files);
	char str[16];
	_itoa_s(files.size() + 1, str, 16, 10);
	TodayOrderNO = str;
	filedoc = "./" + file + "/" + name + TodayOrderNO + ".txt";
	ofstream ofs;
	ofs.open(filedoc, ios::app);
	if (!ofs.is_open()) {
		cout << "订单创建失败，请联系管理人员" << endl;
		ofs.close();
		exit(0);
	}
	ofs.close();
	return filedoc;
}


void Order::ViewTodayOrder()
{
	vector<string> files;
	string filename;
	files.clear();
	getFiles(TodayFilePath(), files);
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i].find(this->m_Uname)!=-1)
		{
			PrintOrder(files[i]);
		}
	}
	system("pause");
}

