#include "TaskFlow.h"

double TProc::Random(int min,int max)
{
		std::mt19937_64 rng;
		uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
		rng.seed(ss);
		std::uniform_real_distribution<double> unif(min, max);
		return(unif(rng));
}
TProc::TProc():count_completed(0), count_ignored(0), count_allprogram(0), count_downtime(0), count_queue(0),free_cores(8)
{
	num_cores = 8;
	tacts = 10;
	squeue = 3;
	intens = 0.5;
	rate = 0.5;
}
TProc::TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate,int _cores):count_completed(0), count_ignored(0), count_allprogram(0), count_downtime(0), count_queue(0),free_cores(_cores)
{
	if (_squeue > MAXQUEUE)
		throw;
	num_cores = _cores;
	tacts = _tacts;
	squeue = _squeue;
	intens = _intens;
	rate = _rate;
}
Task TProc :: GetNewTask()
{
	Task tmp;
	tmp.cores = Random(1, 4);
	tmp.ticks = Random(0, 10);
	return tmp;
}
bool TProc::IsTask()
{
	double q1 = Random(0,1);//q1 в методичке
	stGet.push_back(q1);
	if (q1 <= intens) //если меньше значит генерируем новое задание
	{
		count_allprogram++;
		return true;
	}
	else
		return false;
}
bool TProc::IsComplete(Task a)
{
	if (a.cores==0&&a.ticks==0)
		return false;//уже выполнилось
	double q2 = Random(0,1);//q2 в методичке 
	stComplete.push_back(q2);
	if (q2 <= rate) //значит завершено задание
		return true;
	else
		return false;
}
void TProc::RunJob()
{
	bool busy = false;
	TQueue <Task> queueTasks(squeue);
	for (int i = 0; i < tacts; i++)
	{
		if (IsTask())
		{
			Task tmp = GetNewTask();
			if (!queueTasks.IsEmpty())
			{
				queueTasks.Put(tmp);
				busy = true;
				if (queueTasks.GetFirst().cores <= free_cores)
				{
					free_cores -= queueTasks.GetFirst().cores;
					jobs.push_back(queueTasks.Get());
					for (int j = 0; j < jobs.size(); j++)
					{
						if (IsComplete(jobs[j]))
						{
							free_cores += jobs[j].cores;
							jobs[j] = { 0 , 0 };
							count_completed++;
						}
						else continue;
					}
				}
				else if (queueTasks.GetFirst().cores > free_cores)//число ядер задачи больше свободных(первой на очереди)
					continue;
			}
			else count_ignored++;
		}
		else
		{

		}
	}
	//bool busy = false;//занятость процессора
	//TQueue <int> queueTasks(squeue + 1);//+1 так как первый элемент очереди как будто загружен в процессор
	//for (int i = 0; i < tacts; i++)
	//{
	//	if (GetNewTask())//допустим что за один такт мы можем сгенерировать задание, записать его в очередь
	//	{
	//		if (!queueTasks.IsFull())
	//		{
	//			if (busy&&IsComplete())// в процессор загружена программа первая в очереди, следовательно busy=true 
	//			{
	//				queueTasks.Get();
	//				count_completed++;
	//			}
	//			queueTasks.Put(i);
	//			busy = true;
	//		}
	//		else count_ignored++;
	//	}
	//	else
	//	{
	//		if (queueTasks.IsEmpty())
	//		{
	//			count_downtime++;
	//			busy = false;
	//		}
	//		else
	//		{
	//			if (IsComplete())
	//			{
	//				count_completed++;
	//				queueTasks.Get();
	//				if (queueTasks.IsEmpty()){
	//					busy = false;
	//				}
	//				else {
	//					busy = true;
	//				}
	//			}
	//			else
	//				continue;
	//		}
	//	}
	//}
	//if (busy = true)//завершаем программу в процессоре
	//	count_completed++;
	//if (count_allprogram == 0)
	//	count_ignored = 0;
	//else
	//    count_ignored = (count_ignored / count_allprogram) * 100;
	//count_queue = queueTasks.Size()-1;
	//count_downtime = (count_downtime / tacts)*100;
}