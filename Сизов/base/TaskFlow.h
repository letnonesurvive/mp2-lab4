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
	unsigned int all_tacts;//кол-во тактов имитации
	unsigned int squeue;//очередь процессора
	double intens;//интенсивность потока задач
	double rate;//мощность процессора
	unsigned int all_cores;//всего кол-во ядер
	unsigned int free_cores;//свободных ядер
	int core_load;
	int c_progs;// всего программ
	int c_uncomplete;//число незавершенных задач
	int c_complete;//завершенных програм
	int c_ignore;//число откланенных задач
	int c_downtime;//такты простоя 
	int c_execution;//все время выполнения всех программ
	vector<Task> jobs;
	double Random(int min,int max);//рандом от 0 до 1 (неплохой рандом)
public:
	TProc();
	TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate,int _cores);
	Task GetNewTask();
	bool IsTask();
	bool IsComplete();
	void RunJob();
	friend class Result;
};