#include <cstdlib>
#include <time.h>
#include "Result.h"

void main() //q1 -интенсивность задач q2- производительность процессора 
{
	setlocale(LC_ALL, "Russian");
	string id;
	int tacts,sq;
	double intens, rate;
	//Task t1;
	//cout << "—оздайте новое задание" << endl;
	//cout << "¬ведите название задани€" << endl;
	//cin >> id;
	//cout << "¬ведите врем€ выполнени€ в тактах" << endl;
	//cin >> tacts;
	//cout << "¬ведите размер очереди" << endl;
	//cin >> sq;
	//cout << "¬ведите производительность процессора" << endl;
	//cin >> rate;
	////t1 = { id,tacts,cores };
	//cout << "¬ведите интенсивоность потока задач" << endl;
	//cin >> intens;
	//CPU cpu(tacts,sq,intens,rate);
	TProc cpu(10, 3, 0.5, 0.2);
	cpu.RunJob();
	Result r1(cpu);
	r1.AllStatus();
}