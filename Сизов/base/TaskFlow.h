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
	unsigned int all_tacts;//���-�� ������ ��������
	unsigned int squeue;//������� ����������
	double intens;//������������� ������ �����
	double rate;//�������� ����������
	unsigned int all_cores;//����� ���-�� ����
	unsigned int free_cores;//��������� ����
	int core_load;
	int c_progs;// ����� ��������
	int c_uncomplete;//����� ������������� �����
	int c_complete;//����������� �������
	int c_ignore;//����� ����������� �����
	int c_downtime;//����� ������� 
	int c_execution;//��� ����� ���������� ���� ��������
	vector<Task> jobs;
	double Random(int min,int max);//������ �� 0 �� 1 (�������� ������)
public:
	TProc();
	TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate,int _cores);
	Task GetNewTask();
	bool IsTask();
	bool IsComplete();
	void RunJob();
	friend class Result;
};