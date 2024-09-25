#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "wifi_id.h"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, 7*3600); // UTC+7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  timeClient.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());  
  delay(1000); // this speeds up the simulation
}
