/*
���ֵ��Сֵ������
	min_element
	max_element

*/
#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

bool absLess(int elem1, int elem2)
{
	return abs(elem1) < abs(elem2);
}

void max_min()
{
	deque<int> ideq;

	for (int i = -1; i < 8; i++)
	{
		ideq.insert(ideq.begin(),i);
	}
	ideq.push_back(9);

	deque<int>::iterator iter = ideq.begin();
	for (; iter != ideq.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	deque<int>::iterator result = min_element(ideq.begin(), ideq.end());
	cout << "��Сֵ�ǣ� " << *result << endl;
	cout << "���ֵ�ǣ� " << *max_element(ideq.begin(), ideq.end()) << endl;
	cout << endl;

	cout << "�������ֵ�� " << *max_element(ideq.begin(), ideq.end(), absLess) << endl;
	cout << "������Сֵ�� " << *min_element(ideq.begin(), ideq.end(), absLess) << endl;

}