#include "Queue.h"
#include "time.h"
#include <cstdlib>
#include <random>
#include <chrono>
#include <vector>

class TProc
{
private:
	unsigned int tacts;//���-�� ������ ��������
	unsigned int squeue;//������� ����������
	double intens;//������������� ������ �����
	double rate;//�������� ����������
	int count_queue;
	int count_allprogram;
	int count_completed;
	double count_ignored;
	double count_downtime;
	vector<double> stGet, stComplete;
	double Random();//������ �� 0 �� 1 (�������� ������)
public:
	TProc();
	TProc(unsigned int _tacts, unsigned int _squeue, double _intens, double _rate);
	bool GetNewTask();
	bool IsComplete();// ��� ������ ������������������ ��� ����� 
	void RunJob();//������ ������ ��� ��������� ������ ����� ������ �������� � �������, ���� ����� ����
	friend class Result;
};