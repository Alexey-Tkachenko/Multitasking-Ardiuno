#ifndef _TASK_BASE_H_
#define _TASK_BASE_H_

struct TaskBase
{
	int _state;
	virtual bool Step() = 0;
};

#endif

