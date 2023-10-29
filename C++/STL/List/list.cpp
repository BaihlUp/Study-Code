#include<iostream>
#include<list>

using namespace std;
void InsertList();
void DeleteList();
void ReverseList();
void PrintList(list<int> &li)
{
	list<int>::iterator liter = li.begin();
	for (; liter != li.end(); liter++)
	{
		cout << *liter << "  ";
	}
	cout << endl;
}

int main()
{
	InsertList();
	cout << endl;

	DeleteList();
	cout << endl;
	ReverseList();

	system("pause");
	return 0;
}

void InsertList()
{
	cout << "list ����Ԫ��ʾ����" << endl;
	list<int> li;
	list<int> li2;

	li.push_front(2);
	li.push_front(3);
	li.push_front(4);
	li.push_front(5);
	li.push_front(6);

	//PrintList(li);

	li.insert(li.begin(), 1);
	li.insert(li.end(), 4, 20);

	PrintList(li);

	for (int i = 10; i < 16; i++)
	{
		li2.push_back(i);
	}
	PrintList(li2);

	list<int>::iterator liter = li.begin();

	//li.insert(li.begin(), li2.begin(), li2.end());
	liter++;
	li.insert(liter, ++li2.begin(), --li2.end());

	PrintList(li);
}


void DeleteList()
{
	cout << "list ɾ��Ԫ��ʾ����" << endl;
	list<int> li;
	list<int> li2;

	li.push_back(2);
	li.push_back(3);
	li.push_back(4);
	li.push_back(5);
	li.push_back(6);

	PrintList(li);
	list<int>::iterator liter = li.begin();
	//li.erase(++liter);
	++liter;
	li.erase(li.begin(), liter);

	PrintList(li);
}


void ReverseList()
{
	cout << "list ��ת������ʾ����" << endl;
	list<int> li;
	list<int> li2;

	li.push_back(2);
	li.push_back(-3);
	li.push_back(10);
	li.push_back(-5);
	li.push_back(6);
	PrintList(li);

	//����
	cout << "sort: ";
	li.sort();
	PrintList(li);

	//��ת
	cout << "reverse: " ;
	li.reverse();
	PrintList(li);
}