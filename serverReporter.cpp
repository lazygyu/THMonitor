#ifndef __SERVER_REPORTER__
#define __SERVER_REPORTER__

#include <arduino.h>
#include "wifi.cpp"
#include "TaskRunner.cpp"
#include "sensor.cpp"
#include "constants.h"

class ServerReporter: public TaskRunner {
	private:
		WifiModule *wifi;	
		THSensor *sensor;
		char buffer[255];

	public:
		ServerReporter(THSensor *ss): TaskRunner(SERVER_REPORT_INTERVAL), sensor(ss) {
			wifi = new WifiModule();
		}

		void run() {
			sprintf(buffer, "%s/%d?humi=%5.2f&temp=%5.2f", ServerAddr, DEVICE_ID, sensor->getHumidity(), sensor->getTemperature());
			wifi->get(buffer);
		}
};

#endif
