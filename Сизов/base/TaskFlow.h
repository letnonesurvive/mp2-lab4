#include "Queue.h"
#include "time.h"
#include <cstdlib>
#include <random>
#include <chrono>
#include <vector>

struct Task
{
	int ticks;
	int cores;
};

class TProc
{
private:
	int num_cores;
	int free_cores;
	unsigned int tacts;//кол-во тактов имитации
	unsigned int squeue;//очередь процессора
	double intens;//интенсивность потока задач
	double rate;//мощность процессора
	int count_queue;
	int count_allprogram;
	int count_completed;
	double count_ignored;
	double count_downtime;
	vector<Task> jobs;
	vector<double> stGet, stComplete;
	double Random(int min,int max);//рандом от 0 до 1 (неплохой рандом)
public:
	TProc();
	TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate,int _cores);
	Task GetNewTask();
	bool IsTask();
	bool IsComplete(Task a);// чем больше производительность тем лучше 
	void RunJob();//логика такова что процеесор всегда занят первым заданием в очереди, если такое есть
	friend class Result;
};