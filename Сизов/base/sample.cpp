#include "Queue.h"

void main() //q1 -������������� ����� q2- ������������������ ���������� 
{
	TQueue<int> a(5);
	for (int i = 0; i < 5; i++)
	{
		a.Put(i);
	}
	a.Get();
	a.Put(5);
	cout << a.GetFirst()<<endl;
	cout << a << endl;
	cout << a.GetLast();
	/*cout << a<<endl;
	cout << a;*/
}