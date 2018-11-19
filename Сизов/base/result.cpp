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
		cout << "Всего было поданых задач " << GetPrograms() << endl;
		cout << endl;
		cout << "Незавершенных задач " << GetUnfinish() << endl;
		cout << "Колличество завершенных задач " << GetComplited() << endl;
		cout << "Колличество откланенных задач " << GetIgnored() << "%" << endl;
		cout << "Тактов простоя " << GetDowntime() << "%" << endl;
		cout << endl;
		for (int i = 0; i < c.stGet.size(); i++)
			cout << c.stGet[i] << endl;
		cout << endl;
		for (int i = 0; i < c.stComplete.size(); i++)
			cout << c.stComplete[i] << endl;
	}
	//else if (c.tacts <= 10)//потактовая развертка
	//{
	//	int i = 1, j = 0;
	//	cout << "Интенсивность потока задач = " << c.intens<<endl;
	//	cout << "Мощность процессора = " << c.rate << endl;
	//	cout << "Такт: " << i << endl;
	//	cout << "Новая задача успешно создана" << endl;
	//	for (i,j;j<c.stComplete.size(), i < c.stGet.size(); i++,j++)
	//	{
	//		cout << "Такт: " << i + 1 << endl;
	//		cout << c.stGet[i]<<" ";
	//		if (c.stGet[i] < c.intens)
	//			cout << "Новая задача успешно создана" << endl;
	//		else if (c.stGet[i] >= c.intens)
	//			cout << "Новой задачи создано не было" << endl;
	//		cout << c.stComplete[j] << " ";
	//		if (c.stComplete[j] < c.rate)
	//			cout << "На данном такте программа была завершена" << endl;
	//		else if (c.stComplete[j] >= c.rate)
	//			cout << "Программа не была завершена" << endl;
	//	}
	//}
}