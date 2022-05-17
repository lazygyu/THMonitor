#ifndef __TASKRUNNER__
#define __TASKRUNNER__
#include <arduino.h>

class TaskRunner {
	private:
		unsigned long last;
		unsigned long interval;

	protected:
		unsigned long elapsed;
		TaskRunner(unsigned long interval_value): interval(interval_value) {
			last = millis();
		}
		virtual void run() = 0;

	public:
		void update() {
			unsigned long current = millis();
			elapsed += current - last;
			last = current;

			if (elapsed > interval) {
				run();
				elapsed = 0;
			}
		}
};

#endif
