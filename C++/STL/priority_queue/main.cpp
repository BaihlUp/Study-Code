#include<iostream>
#include<queue>
#include<deque>

using namespace std;

int main()
{
	priority_queue<int> pq; //Ĭ�����ֵ���ȼ�����
	priority_queue<int, deque<int>> gpq;
	

	pq.push(1);
	pq.push(-1);
	pq.push(100);
	pq.push(23);
	
	cout <<"������ĸ�����"<< pq.size() << endl;

	while (!pq.empty())
	{
		cout <<"ɾ�� �� "<< pq.top() << endl;
		pq.pop();
	}
	cout << endl << endl;

	gpq.push(1);
	gpq.push(-1);
	gpq.push(100);
	gpq.push(23);
	cout << "������ĸ�����" << pq.size() << endl;

	while (!gpq.empty())
	{
		cout << "ɾ�� �� " << gpq.top() << endl;
		gpq.pop();
	}

	system("pause");
	return 0;
}