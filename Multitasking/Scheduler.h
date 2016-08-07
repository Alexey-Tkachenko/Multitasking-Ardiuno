#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "TaskBase.h"

template<int MAX_TASKS, typename TaskCounter = byte>
class Scheduler
{
private:
	TaskCounter usedTasks;
	TaskBase* tasks[MAX_TASKS];

public:
	Scheduler() : usedTasks()
	{
	}

	bool AddTask(TaskBase* task)
	{
		if (!task)
		{
			return false;
		}

		if (usedTasks < MAX_TASKS)
		{
			tasks[usedTasks++] = task;
			return true;
		}

		return false;
	}

	void Run()
	{
		TaskCounter current = 0;
		while (usedTasks)
		{
			if (tasks[current]->Step())
			{
				if (current != usedTasks - 1)
				{
					tasks[current] = tasks[usedTasks - 1];
				}
				--usedTasks;
			}
			else
			{
				++current;
			}

			if (current == usedTasks)
			{
				current = 0;
			}
		}
	}
};

#endif

