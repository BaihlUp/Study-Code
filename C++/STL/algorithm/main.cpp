#include"demo.h"

int main()
{
	cout << endl << "--------------------------------------" ;
	cout << endl << "����Ԫ�ظ�����" << endl;
	count();

	cout << endl << "--------------------------------------";
	cout << endl << "���ֵ��Сֵ�㷨ʾ����" << endl;
	max_min();

	cout << endl << "--------------------------------------";
	cout << "�����㷨ʾ����" << endl;
	find_search();
	
	cout << endl << "--------------------------------------";
	cout << endl << "adjacent_find demo��" << endl;
	adjacent_find();

	cout << endl << "--------------------------------------";
	cout << endl << "binary_search demo��" << endl;
	binary_search();

	cout << endl << "--------------------------------------";
	cout << endl << "bound demo��" << endl;
	bound();

	cout << endl << "--------------------------------------";
	cout << endl << "for_each demo��" << endl;
	for_each();

	cout << endl << "--------------------------------------";
	cout << endl << "compare demo��" << endl;
	compare_demo();

	cout << endl << "--------------------------------------";
	cout << endl << "modify algorithm demo��" << endl;
	copy_modify();

	cout << endl << "--------------------------------------";
	cout << endl << "permutation demo��" << endl;
	permutaion();

	cout << endl << "--------------------------------------";
	cout << endl << "transform demo��" << endl;
	transform_alg();

	system("pause");
	return 0;
}