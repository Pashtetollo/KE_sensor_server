#pragma once
#include <HTTPClient.h>
#include "ScreenHandler.h"
#include <WiFiClient.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <ArduinoJson.h>
#include "AsyncJson.h"
#define postURL "http://192.168.31.64:8080/sensors"
#define timeURL "http://worldtimeapi.org/api/timezone/EET"
String dateTime ="";
String currTime="";
bool isLogged = false;
int currentTemperature=0;
int currentHumidity=0;
int currentMoisture=0;
int currentLight=0;
DynamicJsonDocument doc(1024);
int myIterator=0;
String getTime(){
  HTTPClient timeHttp;
  WiFiClient client;
  timeHttp.begin(client, timeURL);
  yield();
  while(timeHttp.GET()!=200)
  Serial.println("time");
  yield();
  deserializeJson(doc, timeHttp.getString());
  yield();
  String myTime = doc["datetime"];
  Serial.println(myTime);
   return myTime;
  }

void postData(String jsonData){
  currTime = getTime();
  yield();
  doc.clear();
  deserializeJson(doc, jsonData);
  yield();
  currentTemperature= doc["temperature"];
  currentHumidity= doc["humidity"];
  currentMoisture= 100-(int)doc["soilMoisture"]*4;
  currentLight = doc["luminosity"];
  dateTime = currTime.substring(0, currTime.length()-6);
  currTime=dateTime;
  jsonData=jsonData.substring(0, jsonData.length()-1);
  jsonData.concat(",\"time\":\"");
  jsonData.concat(dateTime);
  jsonData.concat("\"}");
  yield();
        HTTPClient http;
        http.begin(postURL);
        
      http.addHeader("Content-Type", "application/json");
  yield();
        int httpCode = http.POST(jsonData);
  yield();
        Serial.println("Http code");
        Serial.println(httpCode);
        http.end();
  Serial.println(jsonData);
  }
