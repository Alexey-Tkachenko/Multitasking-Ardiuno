#include "Multitasking/Multitasking.h"

class BlinkerTask : public TaskBase
{
private:
	byte pin;
	bool state;
public:
	explicit BlinkerTask(byte pin)
		: TaskBase(), pin(pin), state()
	{
		pinMode(pin, OUTPUT);
	}

	virtual bool Step() override 
	{
		delay(100);
		digitalWrite(pin, state = !state);
		return false;
	}
};

void setup()
{
	Scheduler<16> scheduler;

	BlinkerTask blinker(13);
	
	scheduler << blinker;

	scheduler.Run();
}

void loop()
{
}
