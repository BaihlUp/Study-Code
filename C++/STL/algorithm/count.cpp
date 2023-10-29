#include<iostream>
#include<algorithm>
#include<functional>
#include<list>
#include<vector>

using namespace std;

template <typename elementType>
bool IsEven(const elementType& number)
{
	return ((number % 2) == 0);
}

void count()
{
	vector<int> vec;
	list<int> li;

	for (int i = -3; i < 6; i++)
	{
		vec.push_back(i);
	}

	for (vector<int>::iterator itervec = vec.begin(); itervec != vec.end(); itervec++)
	{
		cout << *itervec << " ";
	}
	cout << endl;

	cout << "��vector��4�ĸ����ǣ� " << count(vec.begin(), vec.end(), 4) << endl << endl;

	size_t nNumber = count_if(vec.begin(), vec.end(), IsEven<int>);   //����vector���м���ż��
	cout << "vector���� " << nNumber << " ��ż��" << endl << endl;

	nNumber = count_if(vec.begin(), vec.end(), not1(bind2nd(modulus<int>(), 2))); //ʹ�ú���������
	cout << "vector���� " << nNumber << " ��ż��" << endl << endl;

	nNumber = count_if(vec.begin(), vec.end(), bind2nd(greater<int>(), 4));  //������������Ԥ��������
	cout << "vector �� " << nNumber << " ��������4" << endl << endl;
}

