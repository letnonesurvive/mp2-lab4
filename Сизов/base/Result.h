#include "TaskFlow.h"

class Result
{
	TProc proc;
public:
	Result(TProc c1) :proc(c1) {}
	unsigned int GetAllTacts();
	int GetPrograms();
	int GetComplited();
	int GetUnfinish();
	int GetIgnored();
	int GetDowntime();
	int GetTimeExecution();
	int GetCoreLoad();
	void AllStatus();
};
