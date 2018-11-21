#include <cstdlib>
#include "Result.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int tacts,sq,cores;
	double intens, rate;
	cout << "Задайте параметры процессора" << endl;
	cout << "Введите время работы системы (в тактах)" << endl;
	cin >> tacts;
	cout << "Введите размер очереди" << endl;
	cin >> sq;
	cout << "Введите производительность процессора" << endl;
	cin >> rate;
	cout << "Введите интенсивоность потока задач" << endl;
	cin >> intens;
	cout << "Введите кол-во ядер процессора" << endl;
	cin >> cores;
	cout << endl;
	TProc proc(tacts,sq,intens,rate,cores);
	proc.RunJob();
	Result r1(proc);
	r1.AllStatus();
}