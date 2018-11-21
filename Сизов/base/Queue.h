#include <iostream>
#include <string>
using namespace std;
const int MAXQUEUE = 100;

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
		if (_size > 0 && _size <= MAXQUEUE)
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
	TQueue (const TQueue &q)
	{
		size = q.size;
		pMem = new type[size];
		datacount = q.datacount;
		first = q.first;
		last = q.last;
		for (int i = 0; i < size; i++)
			pMem[i] = q.pMem[i];
	}
	TQueue<type> &operator=(const TQueue &q)
	{
		if (this != &q)
		{
			if (size != q.size)
			{
				size = q.size;
				pMem = new type[size];
			}
			datacount = q.datacount;
			first = q.first;
			last = q.last;
			for (int i = 0; i < size; i++)
				pMem[i] = q.pMem[i];
		}
		else return *this;
	}
	bool operator == (const TQueue &q)const
	{
		if (size != q.size)
			return false;
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (pMem[i] != q.pMem[i])
					return false;
			}
			return true;
		}
	}
	bool operator != (const TQueue &q)const
	{
		return!(*this == q);
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
	void Put(type elem)
	{
		if (IsFull())
			throw"Queue is full";
		datacount++;
		last=(++last)%size;
		pMem[last] = elem;
	}
	type First()
	{
		int t_first=first;
		t_first %= size;
		return pMem[t_first];
	}
	type Last()
	{
		return pMem[last];
	}
	~TQueue()
	{
		delete[] pMem;
	}
	int Size()
	{
		return datacount;
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
