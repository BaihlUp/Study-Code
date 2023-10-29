/*
�����㷨��
	lower_bound()
	upper_bound()
	equal_range()

����ʽ�����е�Ч�ĳ�Ա���������ܸ���
*/
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void bound()
{
	list<int> ilist;

	for (int i = 1; i < 10; i++)
		ilist.push_back(i);

	for (int i = 1; i < 10; i++)
		ilist.push_back(i);

	ilist.sort();

	for (list<int>::iterator iter = ilist.begin(); iter != ilist.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	list<int>::iterator pos1;
	pos1 = lower_bound(ilist.begin(), ilist.end(), 5);
	if (pos1 != ilist.end())
		cout << "��һ��5��λ�ã� " << distance(ilist.begin(), pos1) << endl;

	list<int>::iterator pos2;
	pos2 = upper_bound(ilist.begin(), ilist.end(), 5);
	if (pos2 != ilist.end())
		cout << "����5�ĵ�һ��λ�ã� " << distance(ilist.begin(), pos2) << endl;

	pair<list<int>::iterator, list<int>::iterator> range;
	range = equal_range(ilist.begin(), ilist.end(), 5);
	cout << "��һ��5��λ�ã� " << distance(ilist.begin(),range.first) << endl;
	cout << "����5�ĵ�һ��λ�ã� " << distance(ilist.begin(), range.second) << endl;

	cout << endl;
}