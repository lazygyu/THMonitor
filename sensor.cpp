#ifndef __SENSOR__
#define __SENSOR__

#include <arduino.h>
#include <DHT.h>
#include "taskRunner.cpp"
#include "constants.h"

class THSensor: public TaskRunner {
	private:
		DHT* dht;
		float humidity;
		float temperature;

	public:
		THSensor(): TaskRunner(READ_SENSOR_INTERVAL) {
			dht = new DHT(DHT_PIN, DHT_TYPE);
			dht->begin();
			humidity = 0;
			temperature = 0;
		}

		void run() {
				humidity = dht->readHumidity();
				temperature = dht->readTemperature();
		}

		float getHumidity() {
			return humidity;
		}

		float getTemperature() {
			return temperature;
		}
};

#endif
