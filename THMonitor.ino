#include <arduino.h>
#include "sensor.cpp"
#include "serverReporter.cpp"
#include "taskRunner.cpp"

#define TASK_COUNT 2

TaskRunner *tasks[TASK_COUNT];

void setup() {
	tasks[0] = new THSensor();
	tasks[1] = new ServerReporter((THSensor *)tasks[0]);
}

void loop() {
	for(char i = 0; i < TASK_COUNT; i++) {
		tasks[i]->update();
	}
}
