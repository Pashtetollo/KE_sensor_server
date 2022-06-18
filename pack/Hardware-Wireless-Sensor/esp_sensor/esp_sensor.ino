#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include "sensorData.h"
#define ssid "ESP-Server"
#define password "123321ZX"
#define postURL "http://192.168.5.1/sensorData"
  long sleep_duration = 30;
  int iterator;
  String generateJson(){
  char jsonData[256];
  StaticJsonDocument<512> doc;
  JsonObject object = doc.to<JsonObject>();
  delay(3000);
  object["temperature"] = getSensorTemp();
  object["humidity"] = getSensorGumidity();
  object["luminosity"] = getLuminosity();
  object["soilMoisture"] = getMoisture();
  serializeJson(doc, jsonData);
  Serial.print(String(jsonData));
  return String(jsonData);
  }

boolean sendSensorData(String jsonData){
  sleep_duration = 10;
  WiFiClient wifiClient;
  HTTPClient http;
  http.begin(wifiClient,postURL);
  http.addHeader("Content-Type","application/json");
  int httpCode =http.POST(jsonData) ;
  while(httpCode == 419){
    httpCode =http.POST(jsonData) ;
    }

    http.end();
  }
  
void enableDeepSleep(){
  Serial.println("sleep");
  ESP.deepSleep(10e6); // 10 sec
  }

void setup() {
  
  Serial.begin(115200);
  Serial.setTimeout(2000);
  dht.begin();
  while(!Serial) { }
  Serial.println("wake up");
  delay(2000);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {     
    delay(500);
  }
  Serial.println("Connected to wifi");
  Serial.println(WiFi.localIP());
  sendSensorData(generateJson());
  enableDeepSleep();
}
void loop() {
  
  
}
