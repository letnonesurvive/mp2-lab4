#include "Queue.h"

void main()
{
	TQueue<int> a(5);
	for (int i = 0; i < 5; i++)
	{
		a.Put(i);
	}
	a.Get();
	a.Put(5);
	cout << a.GetFirst();
	/*cout << a<<endl;
	cout << a;*/
}