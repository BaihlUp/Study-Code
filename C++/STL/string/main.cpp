#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string strString("Hello String!");
	cout << strString << endl;
	cout << strString.size() << endl;
	cout << strString.c_str() << endl; //ת������C�����ַ���
	const char *string1 = strString.c_str();
	cout << string1 << endl;

	string::const_iterator itr = strString.begin();
	while (itr != strString.end())
	{
		//cout << *itr << endl;
		++itr;
	}
	cout << endl << endl;
	/*�ַ�������*/
	string strSample1("Hello");
	string strSample2("string!");
	strSample1 += strSample2;
	cout << strSample1 << endl;

	char *strSample3 = "I am baihl";
	strSample1.append(strSample3);  //�ַ�������
	cout << strSample1 << endl;

	//�ַ�������
	string strFind1("Good day String! Today is beautiful!");
	cout << strFind1 << endl;
	size_t nOffset = strFind1.find("day", 0);
	if (nOffset != string::npos)
	{
		cout << "���±꣺" << nOffset << "�ҵ���day!" << endl;
	}
	else
		cout << "û�ҵ�" << endl;
	
	//�ַ�����
	size_t nCharOffset = strFind1.find('a', 0);
	while (nCharOffset != string::npos)
	{
		cout << "���±꣺" << nCharOffset << "�ҵ���a" << endl;
		size_t nSearchOffset = nCharOffset + 1;
		nCharOffset = strFind1.find('a', nSearchOffset);
	}

	//�ַ����ض�
	string strErase(strFind1);
	strErase.erase(13, 28);
	cout << endl << endl << strErase << endl;

	string::const_iterator iCharS = find(strErase.begin(), strErase.end(), 'S');
	if (iCharS != strErase.end())
	{
		strErase.erase(iCharS);
	}
	cout << strErase << endl;

	//�ַ�����ת
	cout << endl << endl;
	string strReverse(strFind1);
	cout << strReverse << endl;
	reverse(strReverse.begin(), strReverse.end());
	cout << strReverse << endl;

	//�ַ�����Сдת��
	string strTransform = "baihl";
	transform(strTransform.begin(), strTransform.end(), strTransform.begin(), toupper);
	cout << strTransform << endl;
	transform(strTransform.begin(), strTransform.end(), strTransform.begin(), tolower);
	cout << strTransform << endl;

	//find_first_of
	cout << endl << "find_first_of: " << endl;
	string numerics("0123456789");
	string name("r2d3k");
	string::size_type pos = name.find_first_of(numerics);
	if (pos != string::npos)
		cout << "�ҵ��ˣ��±꣺ " << pos << endl;
	else
		cout << "not found!!" << endl;

	string::size_type pos1 = name.find_last_of(numerics);  //name�Ӻ���ǰƥ�䣬�ҵ��״�ƥ��numerics���ַ�λ��
	//string::size_type pos1 = name.find_first_not_of(numerics); //�������ַ������״γ��ֵĲ�ƥ��name�κ��ַ������ַ�����, ��0��ʼ����, ���ȫ��ƥ���򷵻�string::npos
	if (pos1 != string::npos)
		cout << "�ҵ��ˣ��±꣺ " << pos1 << endl;
	else
		cout << "not found!!" << endl;
	cout << endl;
	system("pause");
	return 0;
}