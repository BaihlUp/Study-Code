/*
����Ƚ�:
	equal(b,e,b2)		������������е����Ƿ����
	equal(b,e,b2,p)

	mismatch(b,e,b2)		�ҵ�����������һ������ȵ�
	mismatch(b,e,b2,p)

	lexicographical_compare(b,e,b2,e2)   �����һ����������С�ڵڶ�����������true�����򷵻�false
	lexicographical_compare(b,e,b2,e2,p)
*/
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<functional>

using namespace std;

void printCollection(vector<int> vec);
bool sortCollection(vector<int> vec1, vector<int> vec2);

void print1(int elem)
{
	cout << elem << " ";
}

bool bothEvenOrOdd(int elem1, int elem2)
{
	return elem1 % 2 == elem2 % 2;
}

void compare_demo()
{
	vector<int> ivec;
	list<int> li;
	for (int i = 0; i < 9; i++)
	{
		ivec.push_back(i);
	}
	ivec.push_back(11);

	for (int i = 0; i < 9; i++)
	{
		li.push_back(i);
	}
	li.push_back(10);
	li.push_back(0);

	for_each(ivec.begin(), ivec.end(), print1);
	cout << endl;

	for_each(li.begin(), li.end(), print1);
	cout << endl;

	if (equal(ivec.begin(), ivec.end(), li.begin()))
		cout << "�����������" << endl;
	else
		cout << "�������������" << endl;

	if (equal(ivec.begin(), ivec.end(), li.begin(), bothEvenOrOdd))
		cout << "����������Ӧλ�õ�����ż��ͬ" << endl;
	else
		cout << "����������Ӧλ�õ�����ż��ͬ" << endl;


	cout << "mismatch:-----------" << endl;
	pair<vector<int>::iterator, list<int>::iterator> value;
	value = mismatch(ivec.begin(), ivec.end(), li.begin());
	if (value.first == ivec.end() || value.second == li.end())
	{
		cout << "not found������" << endl;
	}else{
		cout << "first mismatch: " << *value.first << " and " << *value.second << endl;
	}
	value = mismatch(ivec.begin(), ivec.end(), li.begin(),less_equal<int>());   //�ҵ�һ�����ڵڶ�����������
	if (value.first == ivec.end() || value.second == li.end())
	{
		cout << "not found������" << endl;
	}
	else {
		cout << "first mismatch: " << *value.first << " and " << *value.second << endl;
	}

	cout << "lexicographical_compare:==============" << endl;   
	if (lexicographical_compare(ivec.begin(), ivec.end(), li.begin(), li.end()))
		cout << "vector С�� list" << endl;
	else
		cout << "vector ���ڵ��� list" << endl;

	vector<int> vec1, vec2, vec3, vec4;
	vec1 = vec2 = vec3 = vec4 = ivec;
	
	
	vec2.push_back(-1);
	vec3.push_back(0);
	vec3.push_back(0);
	vec4.push_back(100);

	vector<vector<int>> cc;
	cc.push_back(vec1);
	cc.push_back(vec4);
	cc.push_back(vec3);
	cc.push_back(vec2);

	for_each(cc.begin(), cc.end(), printCollection);

	sort(cc.begin(), cc.end(), sortCollection);

	cout << "sort after: " << endl;
	for_each(cc.begin(), cc.end(), printCollection);
}

void printCollection(vector<int> vec)
{
	for_each(vec.begin(), vec.end(), print1);

	cout << endl;
}

bool sortCollection(vector<int> vec1, vector<int> vec2)
{
	return lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
}