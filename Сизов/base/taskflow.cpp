#include "TaskFlow.h"
#include <iostream>
double TProc::Random(int min, int max)
{
	std::mt19937_64 rng;
	uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	rng.seed(ss);
	std::uniform_real_distribution<double> unif(min, max);
	return(unif(rng));
}
TProc::TProc() : c_progs(0), c_uncomplete(0), c_complete(0), c_ignore(0), c_downtime(0), c_execution(0),core_load(0)
{
	all_tacts = 100;
	squeue = 3;
	intens = 0.5;
	rate = 0.5;
	all_cores = 8;
	free_cores = 8;
}
TProc::TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate, int _cores) : c_progs(0), c_uncomplete(0), c_complete(0), c_ignore(0), c_downtime(0), c_execution(0),core_load(0)
{
	if (_squeue > MAXQUEUE)
		throw;
	if (_intens > 1 || _intens <= 0 || _rate > 1 || _rate <= 0)
		throw;
	all_tacts = _tacts;
	squeue = _squeue;
	intens = _intens;
	rate = _rate;
	all_cores = _cores;
	free_cores = _cores;
}
Task TProc::GetNewTask()
{
	Task tmp;
	tmp.cores = Random(1 , 4);
	tmp.ticks = 1;
	return tmp;
}
bool TProc::IsTask()
{
	double q1 = Random(0, 1);//q1 в методичке
	if (q1 <= intens) //если меньше значит генерируем новое задание
		return true;
	else
		return false;
}
bool TProc::IsComplete()
{
	double q2 = Random(0, 1);//q2 в методичке 
	if (q2 <= rate) //значит завершено задание
		return true;
	else
		return false;
}
void TProc::RunJob()
{
	TQueue <Task> queueTasks(squeue);
	for (int i = 0; i < all_tacts; i++)
	{
		if (IsTask())
		{
			c_progs++;
			Task tmp = GetNewTask();
			if (tmp.cores > all_cores || queueTasks.IsFull())//программа запросила больше ядер чем вообще существует у процессора
				c_ignore++;
			else if (!queueTasks.IsFull())
				queueTasks.Put(tmp);
		}
		for (int j = 0; j < jobs.size(); j++)//смотрим какие программы завершились в процессоре
		{
			if (IsComplete())
			{
				free_cores += jobs[j].cores;
				c_execution += jobs[j].ticks;
				c_complete++;
				jobs.erase(jobs.begin() + j);
				j--;
			}
			else
				jobs[j].ticks++;
		}
		while (queueTasks.First().cores <= free_cores && !queueTasks.IsEmpty())//если возможно то записываем новую программу на этом такте из очереди
		{
			free_cores -= queueTasks.First().cores;
			jobs.push_back(queueTasks.Get());
		}
		core_load = core_load + (all_cores - free_cores);
		if (jobs.empty())
			c_downtime++;
	}
	c_uncomplete = jobs.size() + queueTasks.Size();
}