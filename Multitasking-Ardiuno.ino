#include "Multitasking/Multitasking.h"

DECLARE_TASK(BlinkerTask) CAN_SLEEP
	byte pin;
	bool state;
public:
	BlinkerTask(byte pin) : pin(pin), state() {}

BEGIN_TASK
	pinMode(pin, OUTPUT);
	FOREVER
	{
		digitalWrite(pin, state = !state);
		SLEEP(100);
	}
END_TASK


void setup()
{
	(Instance<Scheduler<2>>::CreateNoGuard() 
		<< Instance<BlinkerTask>::CreateNoGuard(13)
	).Run();
}

void loop()
{
}
