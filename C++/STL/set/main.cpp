//���ݽṹ�еĺ����

#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<int> v;
	multiset<int> muv;

	v.insert(1);
	v.insert(123);
	v.insert(12);
	v.insert(23);
	v.insert(199);
	v.insert(2);
	v.insert(199);

	muv.insert(v.begin(),v.end());
	muv.insert(199);

	cout << "��ʾset���������: " << endl;
	set<int>::iterator iter = muv.begin();
	muv.insert(iter, 11);
	while (iter != muv.end())
	{
		cout << *iter << endl;
		++iter;
	}
	cout << endl << endl;
	multiset<int>::iterator muiter = muv.find(2);
	if (muiter != muv.end())
	{
		size_t Offset = distance(muv.begin(),muiter);

		cout << "�ҵ��ˣ���" << Offset << "  value:" << *muiter << endl;
	}
	else
		cout << "û�ҵ�" << endl;

	system("pause");
	return 0;
}