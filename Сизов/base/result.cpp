#include "Result.h"
unsigned int Result :: GetAllTacts()
{
	return proc.all_tacts;
}
int Result::GetPrograms()
{
	if (proc.c_progs == 0)//����� �� ���� ������� �� ����
		return 1;
	return proc.c_progs;
}
int Result::GetComplited()
{
	if (proc.c_complete == 0)//����������
		return 1;
	return proc.c_complete;
}
int Result::GetUnfinish()
{
	return proc.c_uncomplete;
}
int Result::GetIgnored()
{
	return proc.c_ignore;
}
int Result::GetDowntime()
{
	return proc.c_downtime;
}
int Result::GetTimeExecution()
{
	return proc.c_execution;
}
int Result::GetCoreLoad()
{
	return proc.core_load;
}
void Result::AllStatus()
{
	cout.precision(2);
		cout << "����� ���� ������� ����� " << GetPrograms() << endl;
		cout << "����������� ����������� ����� " << GetComplited() << endl;
		cout << "������������� ����� " << GetUnfinish()<< endl;
		cout << "������� ����� ���������� ��������� " << double(GetTimeExecution()) / GetComplited()<< endl;
		cout << "������� ������������� ���� " << double(GetCoreLoad())*100/ (GetAllTacts()*proc.all_cores)<< "%" << endl;
		cout << "����������� ����� " << (double(GetIgnored()) / GetPrograms())*100<< "%" <<  endl;
		cout << "����������� ���������� " << (double(GetDowntime())/GetAllTacts())*100<< "%" << endl;
		cout << endl;
}