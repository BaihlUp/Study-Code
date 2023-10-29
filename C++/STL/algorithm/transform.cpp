/*
transform()�㷨��������ʽ��
	transform(b1, e1, b2, op);
	transform(b1, e1, b2, b3, op);

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<functional>
#include<iterator>

using namespace std;

template <class T>
void static print(T elem)
{
	cout << elem << " ";
}

void transform_alg()
{
	vector<int> ivec;
	list<int> ilist;

	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}
	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	transform(ivec.begin(), ivec.end(), ivec.begin(), negate<int>());   //��������ȡ��
	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	transform(ivec.begin(), ivec.end(), back_inserter(ilist), bind2nd(multiplies<int>(), 10));
	for_each(ilist.begin(), ilist.end(), print<int>);
	cout << endl;

	transform(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " "), negate<int>()); //ʹ�������������
	cout << endl;

	//������������
	transform(ivec.begin(), ivec.end(), ivec.begin(), ivec.begin(), multiplies<int>());
	for_each(ivec.begin(), ivec.end(), print<int>);
	cout << endl;

	ilist.clear();
	transform(ivec.begin(), ivec.end(), ivec.rbegin(), back_inserter(ilist), plus<int>());   //���
	for_each(ilist.begin(), ilist.end(), print<int>);
	cout << endl;

}