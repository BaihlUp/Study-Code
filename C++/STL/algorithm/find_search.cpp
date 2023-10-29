/*
�㷨������
���������
	count
	count_if
���ң�
	find
	find_if
�����±꣺
	distance
���Ҷ����
	search
	search_n
	find_end
	find_first_of(b,e,sb,se)
	find_first_of(b,e,sb,se,bp)

������������
	bind1st(op, value)
	bind2nd(op, value)
	not1(op)
	not2(op)
	mem_fun_ref(op)
	mem_fun(op)
	ptr_fun(op)

Ԥ����ĺ�������
	greater_equal<type>()
	lesss_equal<type>()
	greater<type>()
	less<type>()
*/
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>

using namespace std;

template <typename elementType>
bool IsEven(const elementType& number)
{
	return ((number % 2) == 0);
}

bool checkEven(int elem, bool even)
{
	if (even)
		return elem % 2 == 0;
	else
		return elem % 2 == 1;
}

void find_search()
{
	vector<int> vec;
	list<int> li;

	for (int i = -3; i < 6; i++)
	{
		vec.push_back(i);
	}
	cout << "vector: ";
	for (vector<int>::iterator itervec = vec.begin(); itervec != vec.end(); itervec++)
	{
		cout << *itervec << " ";
	}
	cout << endl;

	vector<int>::iterator itervec;
	/*itervec = find(vec.begin(), vec.end(), -1);
	if (itervec != vec.end())
	{
		cout << "find -1, distance is : " << distance(vec.begin(), itervec) << endl << endl;
	}*/
	itervec = find_if(vec.begin(), vec.end(), IsEven<int>);    //���ҵ�һ��ż����λ��
	if (itervec != vec.end())
	{
		cout << "����ż��, distance is : " << distance(vec.begin(), itervec) << endl << endl;
	}
	
	for (int i = 1; i < 4; i++)
	{
		li.push_back(i);
	}
	//li.push_back(-1);
	cout << "list: ";
	for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	vector<int>::iterator iterSearch;
	iterSearch = search(vec.begin(), vec.end(), li.begin(), li.end());  //��vector�в���list
	//iterSearch = find_end(vec.begin(), vec.end(), li.begin(), li.end());//�Ӻ���ǰ�ң���һ��
	//iterSearch = search_n(vec.begin(), vec.end(), 4, 3);  //��vector�в���4��3
	//iterSearch = search_n(vec.begin(), vec.end(), 3, 6, greater<int>()); //������3������6
	if (iterSearch != vec.end())
	{
		cout << "find list, distance is : " << distance(vec.begin(), iterSearch) << endl << endl;
	}
	else {
		cout << "not found!!" << endl;
	}

	cout << "********" << endl;
	cout << "Number 2: " << endl;

	vector<int> ivec;
	for (int i = 1; i <= 9; i++)
	{
		ivec.push_back(i);
	}
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	bool checkEvenArgs[3] = { true,false,true };

	vector<int>::iterator pos;
	pos = search(ivec.begin(), ivec.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);  //����������ż��/����/ż��
	while (pos != ivec.end())
	{
		cout << "�ҵ��ˣ� " << distance(ivec.begin(), pos) << endl;
		pos++;
		pos = search(pos, ivec.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);  //����������ż��/����/ż��
	}

	cout << "********" << endl;
	cout << "Number 3: " << endl;
	list<int> searchList;
	searchList.push_back(3);
	searchList.push_back(6);
	searchList.push_back(99);

	cout << "vector: ";
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl<<"list: ";
	for (list<int>::iterator iter = searchList.begin(); iter != searchList.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	vector<int>::iterator pos1;
	pos1 = find_first_of(ivec.begin(), ivec.end(), searchList.begin(), searchList.end());//��vector�в���list������һ�����ҵ���һ���򷵻�
	if (pos1 != ivec.end())
	{
		cout << "�ҵ��ˣ� " << distance(ivec.begin(), pos1) << endl;
	}
	else
		cout << "not found!!" << endl;

	cout << "reverse_iterator: " << endl;
	vector<int>::reverse_iterator rpos;			//���������
	rpos = find_first_of(ivec.rbegin(), ivec.rend(), searchList.begin(), searchList.end());
	if (rpos != ivec.rend())
	{
		cout << "�ҵ��ˣ� " << distance(ivec.begin(), rpos.base()) << endl;  //rpos.base()���������������
	}
	else
		cout << "not found!!" << endl;
}
