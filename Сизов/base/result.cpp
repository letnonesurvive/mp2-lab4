#include "Result.h"

int Result::GetPrograms()
{
	return c.count_allprogram;
}
int Result::GetComplited()
{
	return c.count_completed;
}
int Result::GetUnfinish()
{
	return c.count_queue;
}
double Result::GetIgnored()
{
	return c.count_ignored;
}
double Result::GetDowntime()
{
	return c.count_downtime;
}
void Result::AllStatus()
{
	cout.precision(2);
	//if (c.tacts > 10)
	{
		cout << "����� ���� ������� ����� " << GetPrograms() << endl;
		cout << endl;
		cout << "������������� ����� " << GetUnfinish() << endl;
		cout << "����������� ����������� ����� " << GetComplited() << endl;
		cout << "����������� ����������� ����� " << GetIgnored() << "%" << endl;
		cout << "������ ������� " << GetDowntime() << "%" << endl;
		cout << endl;
		for (int i = 0; i < c.stGet.size(); i++)
			cout << c.stGet[i] << endl;
		cout << endl;
		for (int i = 0; i < c.stComplete.size(); i++)
			cout << c.stComplete[i] << endl;
	}
	//else if (c.tacts <= 10)//���������� ���������
	//{
	//	int i = 1, j = 0;
	//	cout << "������������� ������ ����� = " << c.intens<<endl;
	//	cout << "�������� ���������� = " << c.rate << endl;
	//	cout << "����: " << i << endl;
	//	cout << "����� ������ ������� �������" << endl;
	//	for (i,j;j<c.stComplete.size(), i < c.stGet.size(); i++,j++)
	//	{
	//		cout << "����: " << i + 1 << endl;
	//		cout << c.stGet[i]<<" ";
	//		if (c.stGet[i] < c.intens)
	//			cout << "����� ������ ������� �������" << endl;
	//		else if (c.stGet[i] >= c.intens)
	//			cout << "����� ������ ������� �� ����" << endl;
	//		cout << c.stComplete[j] << " ";
	//		if (c.stComplete[j] < c.rate)
	//			cout << "�� ������ ����� ��������� ���� ���������" << endl;
	//		else if (c.stComplete[j] >= c.rate)
	//			cout << "��������� �� ���� ���������" << endl;
	//	}
	//}
}