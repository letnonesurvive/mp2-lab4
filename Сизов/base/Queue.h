#include <iostream>
using namespace std;
const int MAXSIZE = 100;

template <class type>
class TQueue
{
private:
	int size;
	int datacount;
	int first;
	int last;
	type *pMem;
public:
	TQueue(int _size = 10)
	{
		if (_size > 0 && _size <= MAXSIZE)
		{
			size = _size;
			pMem = new type[size];
			datacount = 0;
			first = 0;
			last = -1;
			for (int i = 0; i < size; i++)
				pMem[i] = {};
		}
		else throw "error of size";
	}
	bool IsEmpty()
	{
		if (datacount == 0)
			return true;
		else return false;
	}
	bool IsFull()
	{
		if (datacount == size)
			return true;
		else return false;
	}
	type Get()
	{
		if (IsEmpty())
			throw "Queue is empty";
		first = first % size;
		type re = pMem[first];
		pMem[first++] = {};
		datacount--;
		return re;
	}
	void Put(int elem)
	{
		if (IsFull())
			throw"Queue is full";
		datacount++;
		last=(++last)%size;
		pMem[last] = elem;
	}
	type GetFirst()
	{
		return pMem[first];
	}
	type GetLast()
	{
		return pMem[last];
	}
	~TQueue()
	{
		delete[] pMem;
	}
	friend ostream& operator <<(ostream &os, TQueue &a)//выводит очередь в правильно порядке
	{
		for (int i = 0; i <a.datacount; i++)
		{
			a.first = a.first % a.size;
			os << a.GetFirst()<<" ";
			a.first++;
		}
		return os;
	}
};
