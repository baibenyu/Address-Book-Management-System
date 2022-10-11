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

//չʾ����
void showMenu()
{
	cout << "��ѡ���Ӧ������ִ�����Ĳ���!" << endl;
	cout << "1.��ʾ��ϵ��" << endl;
	cout << "2.�����ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.�޸���ϵ��" << endl;
	cout << "5.��ѯ��ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�����" << endl;
}

void addPerson(AddressBooks* p)
{
	if (p->size == MAX)
	{
		cout << "��������,���ֵ��Ա�������������." << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������:" << endl;
		cin >> name;
		p->pArray[p->size].name = name;

		bool sex;
		cout << "�������Ա�:(0��ʾ����,1��ʾŮ��)" << endl;
		cin >> sex;
		p->pArray[p->size].sex = sex;

		int age;
		cout << "����������:" << endl;
		cin >> age;
		p->pArray[p->size].age = age;

		string phonenumber;
		cout << "������绰����:" << endl;
		cin >> phonenumber;
		p->pArray[p->size].phonenumber = phonenumber;

		string address;
		cout << "������סַ:" << endl;
		cin >> address;
		p->pArray[p->size].address = address;
		p->size += 1;
		cout << "��ӳɹ�" << endl;
	}
}

void showPerson(AddressBooks* p)
{
	if (p->size == 0)
	{
		cout << "��¼Ϊ��,���������ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << p->pArray[i].name << " " << p->pArray[i].age << " " << p->pArray[i].address 
				<< " " <<( p->pArray[i].sex ==1 ? "Ů" :"��") << " " << p->pArray[i].phonenumber << endl;
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
	cout << "������Ҫɾ�����˵�����:" << endl;
	cin >> name;
	int position = isExist(p, name);
	if (position != -1)
	{
		p->pArray[position] = p->pArray[p->size - 1];
		p->size -= 1;
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	{
		cout << "ָ����ϵ�˲�����!" << endl;
	}
}

void findPerson(AddressBooks* p)
{
	cout << "������Ҫ���ҵ��˵�����:" << endl;
	string name;
	cin >> name;

	int position = isExist(p, name);
	if (position != -1)
	{
		cout << "���ҳɹ�!" << endl;
		cout << p->pArray[position].name << " " << p->pArray[position].age << " " << p->pArray[position].address << " "
			<< (p->pArray[position].sex == 1 ? "Ů" : "��") << " " << p->pArray[position].phonenumber << endl;
	}
	else
	{
		cout << "ָ������������!" << endl;
	}
}

void clearPerson(AddressBooks* p)
{
	p->size = 0;
}

void modifyPerson(AddressBooks* p)
{
	cout << "������Ҫ�޸ĵ��˵�����:" << endl;
	string name;
	cin >> name;

	int position = isExist(p, name);
	if (position != -1)
	{
		cout << "������Ҫ�޸ĵ�ѡ����:" << endl;
		cout << "1.���� 2.�Ա� 3.�绰 4.סַ 5.����" << endl;
		int pick;
		cin >> pick;
		switch (pick)
		{
		case 1:
		{
			cout << "������Ҫ�޸ĵ��˵�����:" << endl;
			string name;
			cin >> name;
			p->pArray[position].name = name;
			break;
		}
			
		case 2:
		{
			cout << "������Ҫ�޸ĵ��˵��Ա�(0��1Ů):" << endl;
			bool sex;
			cin >> sex;
			p->pArray[position].sex = sex;
			break;
		}
		case 3:
		{
			cout << "������Ҫ�޸ĵ��˵ĵ绰:" << endl;
			string phonenumber;
			cin >> phonenumber;
			p->pArray[position].phonenumber = phonenumber;
			break;
		}
		case 4:
		{
			cout << "������Ҫ�޸ĵ��˵�סַ:" << endl;
			string address;
			cin >> address;
			p->pArray[position].address = address;
			break;
		}
		case 5:
		{
			cout << "������Ҫ�޸ĵ��˵�����:" << endl;
			int age;
			cin >> age;
			p->pArray[position].age = age;
			break;
		}
		default:
		{
			cout << "������1-5֮���������!" << endl;
			break;
		}
		}
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "ָ������������!" << endl;
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
			// �˳�����
		case 0:
			cout << "��лʹ��,�ټ�!" << endl;
			return 0;
			break;

			// ��ʾ������ϵ��
		case 1:
			showPerson(&abks);
			break;

			// �����ϵ��
		case 2:
			addPerson(&abks);
			break;

			// ɾ����ϵ��
		case 3:
			delPerson(&abks);
			break;

			// �޸���ϵ��
		case 4:
			modifyPerson(&abks);
			break;

			// ��ѯ��ϵ��
		case 5:
			findPerson(&abks);
			break;

			// �����ϵ��
		case 6:
			clearPerson(&abks);
			break;
		}
	}
}