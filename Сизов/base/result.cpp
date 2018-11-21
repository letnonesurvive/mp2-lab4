#include "Result.h"
unsigned int Result :: GetAllTacts()
{
	return proc.all_tacts;
}
int Result::GetPrograms()
{
	if (proc.c_progs == 0)//чтобы не было деления на ноль
		return 1;
	return proc.c_progs;
}
int Result::GetComplited()
{
	if (proc.c_complete == 0)//аналогично
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
		cout << "Всего было поданых задач " << GetPrograms() << endl;
		cout << "Колличество завершенных задач " << GetComplited() << endl;
		cout << "Незавершенных задач " << GetUnfinish()<< endl;
		cout << "Среднее время выполнения программы " << double(GetTimeExecution()) / GetComplited()<< endl;
		cout << "Средняя загруженность ядер " << double(GetCoreLoad())*100/ (GetAllTacts()*proc.all_cores)<< "%" << endl;
		cout << "Откланенных задач " << (double(GetIgnored()) / GetPrograms())*100<< "%" <<  endl;
		cout << "Бездействие процессора " << (double(GetDowntime())/GetAllTacts())*100<< "%" << endl;
		cout << endl;
}