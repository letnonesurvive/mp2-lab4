#include <cstdlib>
#include "Result.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int tacts,sq,cores;
	double intens, rate;
	cout << "������� ��������� ����������" << endl;
	cout << "������� ����� ������ ������� (� ������)" << endl;
	cin >> tacts;
	cout << "������� ������ �������" << endl;
	cin >> sq;
	cout << "������� ������������������ ����������" << endl;
	cin >> rate;
	cout << "������� �������������� ������ �����" << endl;
	cin >> intens;
	cout << "������� ���-�� ���� ����������" << endl;
	cin >> cores;
	cout << endl;
	TProc proc(tacts,sq,intens,rate,cores);
	proc.RunJob();
	Result r1(proc);
	r1.AllStatus();
}