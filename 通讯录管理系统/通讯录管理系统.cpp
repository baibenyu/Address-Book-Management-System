#include <iostream>
using namespace std;
constexpr int MAX = 1000;

struct Person
{
	string name = "";
	int age = 0;
	bool sex = false;
	string phonenumber = "";
	string address = "";
};

struct AddressBooks
{
	Person pArray[MAX];
	int size = 0;
};

//展示界面
void showMenu()
{
	cout << "请选择对应数字来执行您的操作!" << endl;
	cout << "1.显示联系人" << endl;
	cout << "2.添加联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.修改联系人" << endl;
	cout << "5.查询联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出程序" << endl;
}

void addPerson(AddressBooks* p)
{
	if (p->size == MAX)
	{
		cout << "名额已满,请充值会员解锁更多名额吧." << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入名字:" << endl;
		cin >> name;
		p->pArray[p->size].name = name;

		bool sex;
		cout << "请输入性别:(0表示男生,1表示女生)" << endl;
		cin >> sex;
		p->pArray[p->size].sex = sex;

		int age;
		cout << "请输入年龄:" << endl;
		cin >> age;
		p->pArray[p->size].age = age;

		string phonenumber;
		cout << "请输入电话号码:" << endl;
		cin >> phonenumber;
		p->pArray[p->size].phonenumber = phonenumber;

		string address;
		cout << "请输入住址:" << endl;
		cin >> address;
		p->pArray[p->size].address = address;
		p->size += 1;
		cout << "添加成功" << endl;
	}
}

void showPerson(AddressBooks* p)
{
	if (p->size == 0)
	{
		cout << "记录为空,请先添加联系人" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << p->pArray[i].name << " " << p->pArray[i].age << " " << p->pArray[i].address 
				<< " " <<( p->pArray[i].sex ==1 ? "女" :"男") << " " << p->pArray[i].phonenumber << endl;
		}
	}
}

int isExist(AddressBooks* p, string name)
{
	for (int i = 0; i < p->size; i++)
	{
		if (p->pArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void delPerson(AddressBooks* p)
{
	string name;
	cout << "请输入要删除的人的姓名:" << endl;
	cin >> name;
	int position = isExist(p, name);
	if (position != -1)
	{
		p->pArray[position] = p->pArray[p->size - 1];
		p->size -= 1;
		cout << "删除成功!" << endl;
	}
	else
	{
		cout << "指定联系人不存在!" << endl;
	}
}

void findPerson(AddressBooks* p)
{
	cout << "请输入要查找的人的姓名:" << endl;
	string name;
	cin >> name;

	int position = isExist(p, name);
	if (position != -1)
	{
		cout << "查找成功!" << endl;
		cout << p->pArray[position].name << " " << p->pArray[position].age << " " << p->pArray[position].address << " "
			<< (p->pArray[position].sex == 1 ? "女" : "男") << " " << p->pArray[position].phonenumber << endl;
	}
	else
	{
		cout << "指定人名不存在!" << endl;
	}
}

void clearPerson(AddressBooks* p)
{
	p->size = 0;
}

void modifyPerson(AddressBooks* p)
{
	cout << "请输入要修改的人的姓名:" << endl;
	string name;
	cin >> name;

	int position = isExist(p, name);
	if (position != -1)
	{
		cout << "请输入要修改的选项编号:" << endl;
		cout << "1.姓名 2.性别 3.电话 4.住址 5.年龄" << endl;
		int pick;
		cin >> pick;
		switch (pick)
		{
		case 1:
		{
			cout << "请输入要修改的人的姓名:" << endl;
			string name;
			cin >> name;
			p->pArray[position].name = name;
			break;
		}
			
		case 2:
		{
			cout << "请输入要修改的人的性别(0男1女):" << endl;
			bool sex;
			cin >> sex;
			p->pArray[position].sex = sex;
			break;
		}
		case 3:
		{
			cout << "请输入要修改的人的电话:" << endl;
			string phonenumber;
			cin >> phonenumber;
			p->pArray[position].phonenumber = phonenumber;
			break;
		}
		case 4:
		{
			cout << "请输入要修改的人的住址:" << endl;
			string address;
			cin >> address;
			p->pArray[position].address = address;
			break;
		}
		case 5:
		{
			cout << "请输入要修改的人的年龄:" << endl;
			int age;
			cin >> age;
			p->pArray[position].age = age;
			break;
		}
		default:
		{
			cout << "请输入1-5之间的正整数!" << endl;
			break;
		}
		}
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "指定人名不存在!" << endl;
	}
}

int main()
{
	AddressBooks abks;
	int select = 0;
	showMenu();
	while (true)
	{
		cin >> select;

		switch (select)
		{
			// 退出程序
		case 0:
			cout << "感谢使用,再见!" << endl;
			return 0;
			break;

			// 显示所有联系人
		case 1:
			showPerson(&abks);
			break;

			// 添加联系人
		case 2:
			addPerson(&abks);
			break;

			// 删除联系人
		case 3:
			delPerson(&abks);
			break;

			// 修改联系人
		case 4:
			modifyPerson(&abks);
			break;

			// 查询联系人
		case 5:
			findPerson(&abks);
			break;

			// 清空联系人
		case 6:
			clearPerson(&abks);
			break;
		}
	}
}