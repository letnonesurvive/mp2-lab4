#include <cstdlib>
#include <time.h>
#include "Result.h"

void main() //q1 -������������� ����� q2- ������������������ ���������� 
{
	setlocale(LC_ALL, "Russian");
	string id;
	int tacts,sq;
	double intens, rate;
	//Task t1;
	//cout << "�������� ����� �������" << endl;
	//cout << "������� �������� �������" << endl;
	//cin >> id;
	//cout << "������� ����� ���������� � ������" << endl;
	//cin >> tacts;
	//cout << "������� ������ �������" << endl;
	//cin >> sq;
	//cout << "������� ������������������ ����������" << endl;
	//cin >> rate;
	////t1 = { id,tacts,cores };
	//cout << "������� �������������� ������ �����" << endl;
	//cin >> intens;
	//CPU cpu(tacts,sq,intens,rate);
	TProc cpu(10, 3, 0.5, 0.2);
	cpu.RunJob();
	Result r1(cpu);
	r1.AllStatus();
}