﻿#include <iostream>
#ifndef __STACK_H__
#define __STACK_H__
using namespace std;
const int MaxStackSize = 100;

template <class T>
class TStack
{
	T *pMem;
	int size;//размер стека
	int top;//позиция последнего записанного элемента
public:
	TStack(int _size)
	{
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw size;
		pMem = new T[size];
		for (int i = 0; i < size; i++)
			pMem[i] = {};
	}

	TStack<T> & operator=(const TStack<T> &s)
	{
		if (this != &s)
		{
			if (size != s.size)
			{
				delete[] pMem;
				pMem = new T[s.size];
				size = s.size;
				top = s.top;
				for (int i = 0; i < size; i++)
					pMem[i] = s.pMem[i];
			}
			else
			{
				for (int i = 0; i < size; i++)
					this->pMem[i] = s.pMem[i];
				top = s.top;
			}
		}
		else return *this;
	}

	TStack(const TStack<T> &s)
	{
		pMem = new T[s.size];
		size = s.size;
		top = s.top;
		for (int i = 0; i < size; i++)
			pMem[i] = s.pMem[i];
	}

	bool operator==(const TStack &st) const
	{
		if (this->size != st.size)
			return false;
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (this->pMem[i] != st.pMem[i])
					return false;
			}
			return true;
		}
	}
	bool operator!=(const TStack &st) const
	{
		return!(*this == st);
	}
	T Back()//чему равен последний элемент
	{
		return pMem[top];
	}

	void Put(T elem)
	{
		if (IsFull())
			throw length_error("Стек полный");
		top++;
		pMem[top] = elem;
	}

	T Get()//нумерация с нуля
	{
		if (IsEmpty())
			throw length_error("Стек пустой");
		T tmp = pMem[top];
		pMem[top] = {};
		top--;
		return tmp;
	}

	bool IsEmpty()
	{
		if (top == -1)
			return true;
		else return false;
	}

	bool IsFull()
	{
		if (top == size - 1)
			return true;
		else return false;
	}

	int Size()
	{
		return size;
	}

	int Top()
	{
		return top;
	}

	friend  ostream& operator<<(ostream &os, TStack<T> &st)
	{
		for (int i = 0; i <= st.top; i++)
			os << st.pMem[i] << endl;
		return os;
	}

	~TStack()
	{
		delete[] pMem;
	}

};

#endif

