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
	unsigned int tacts;//���-�� ������ ��������
	unsigned int squeue;//������� ����������
	double intens;//������������� ������ �����
	double rate;//�������� ����������
	int count_queue;
	int count_allprogram;
	int count_completed;
	double count_ignored;
	double count_downtime;
	vector<Task> jobs;
	vector<double> stGet, stComplete;
	double Random(int min,int max);//������ �� 0 �� 1 (�������� ������)
public:
	TProc();
	TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate,int _cores);
	Task GetNewTask();
	bool IsTask();
	bool IsComplete(Task a);// ��� ������ ������������������ ��� ����� 
	void RunJob();//������ ������ ��� ��������� ������ ����� ������ �������� � �������, ���� ����� ����
	friend class Result;
};