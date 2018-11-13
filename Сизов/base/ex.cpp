#include "stack.h"
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
	cout << a;
}