#ifndef _EXPRESS_TASK_H_
#define _EXPRESS_TASK_H_

#define DECLARE_TASK(T) class T : public TaskBase {
#define BEGIN_TASK private: virtual bool Step() override { \
	switch (this->_state) { \
	case 0:

#define END_TASK default: this->_state = -1; return true; }}};

#define YIELD this->_state = __LINE__; return false; case __LINE__:
#define YIELD_WHILE(cond) case __LINE__: if ((cond)) { this->_state = __LINE__; return false;}

#define FOREVER for(;;)

#define CAN_SLEEP unsigned long _sleep;
#define SLEEP(interval) {this->_sleep = millis() + (interval);} YIELD_WHILE(millis() < this->_sleep);

#endif

