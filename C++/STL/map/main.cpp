#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<int, string> ma;
	multimap<int, string> mumap;

	ma.insert(map<int, string>::value_type(1, "One"));
	ma.insert(map<int, string>::value_type(2, "Two"));
	ma.insert(make_pair(3, "Three"));
	ma.insert(pair<int, string>(100, "One Thousand"));
	ma[1000000] = "One Million";

	cout << "map�ﹲ��" << ma.size() << "��key-value��" << endl;
	cout << "" << endl;
	map<int, string>::const_iterator iterma=ma.begin();
	while (iterma != ma.end())
	{
		cout << iterma->first << ": " << iterma->second.c_str() << endl;
		++iterma;
	}
	cout << ma[100] << endl;

	cout << endl << endl;
	mumap.insert(ma.begin(), ma.end());
	mumap.insert(map<int, string>::value_type(1, "One"));
	mumap.insert(map<int, string>::value_type(2, "Two"));
	mumap.insert(make_pair(3, "Three"));
	mumap.insert(pair<int, string>(100, "One Thousand"));
	//mumap[1000000] = "One Million";  ����
	cout << "multimap�ﹲ��" << mumap.size() << "��key-value��" << endl;
	cout << "" << endl;
	map<int, string>::const_iterator itermumap = mumap.begin();
	while (itermumap != mumap.end())
	{
		cout << itermumap->first << ": " << itermumap->second.c_str() << endl;
		++itermumap;
	}
	//cout << mumap[100] << endl; ����
	cout << endl << endl;
	//����
	itermumap = mumap.find(101);
	if (itermumap != mumap.end())
	{
		cout << "�ҵ���1 " << endl;
		size_t n = mumap.count(1);
		for (size_t i = 0; i < n; i++)
		{
			cout << "\t Key: " << itermumap->first;
			cout << ", Value [" << i << "] = ";
			cout << itermumap->second << endl;
			++itermumap;
		}
	}
	else {
		cout << "û�ҵ�" << endl;
	}


	system("pause");
	return 0;
}