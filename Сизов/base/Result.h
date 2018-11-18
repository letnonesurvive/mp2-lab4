#include "TaskFlow.h"

class Result
{
	TProc c;
public:
	Result(TProc c1) :c(c1) {}
	int GetPrograms();
	int GetComplited();
	int GetUnfinish();
	double GetIgnored();
	double GetDowntime();
	void AllStatus();
};
