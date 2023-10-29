/*
�����㷨��
	adjacent_find(a, d)  //������������
	adjacent_find(b, e, p) //���ν�ʲ���

*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool doubled(int elem1, int elem2)
{
	return elem1 * 2 == elem2;
}

void adjacent_find()
{
	vector<int> ivec;
	for (int i = 0; i < 10; i++)
		ivec.push_back(i);
	ivec.insert(ivec.end(), 3, 9);

	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	vector<int>::iterator iter;
	iter = adjacent_find(ivec.begin(), ivec.end());
	if (iter != ivec.end())
	{
		cout << "found it : " << distance(ivec.begin(), iter) << endl;
	}
	else
	{
		cout << "not found!!!" << endl;
	}

	iter = adjacent_find(ivec.begin(), ivec.end(), doubled); //���Һ�ߵ�����ǰ�ߵ�������������λ��
	if (iter != ivec.end())
	{
		cout << "found it : " << distance(ivec.begin(), iter) << endl;
	}
	else
	{
		cout << "not found!!!" << endl;
	}

	cout << endl;
}