#ifndef __WIFIMODULE__
#define __WIFIMODULE__
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "constants.h"

class WifiModule {
	public:
		WifiModule() {
			connect();
		}

		void get(char *to) {
			WiFiClient client;
			HTTPClient http;
			http.begin(client, to);
			int httpCode = http.GET();
			String payload = http.getString();
			http.end();
		}

		IPAddress getIP() {
			return WiFi.localIP();
		}

	private:
		void connect() {
			WiFi.mode(WIFI_STA);
			WiFi.begin(MY_SSID, MY_PASSWORD);

			while(WiFi.status() != WL_CONNECTED) {
				delay(500);
			}
		}
};

#endif
