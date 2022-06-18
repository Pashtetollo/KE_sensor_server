
#pragma once
#include "ServerAPI.h"
#include "FS.h"
#include "SPIFFS.h"


struct Config {
  String ssid;
  String password;
  String username;
  String wifipassword;
  int temperature;
  int humidity;
  int moisture;
  int lightLevel;
  };

char *filename = "/config.txt";  
Config config;                        


void saveLoginData(String jsonData){
  doc.clear();
  deserializeJson(doc, jsonData);
  // Copy values from the JsonDocument to the Config
  config.ssid = doc["ssid"] | "isempty";
  config.password = doc["password"] | "isempty";
  config.wifipassword = doc["wifipassword"] | "isempty";
  config.username = doc["username"] | "isempty";
  config.temperature = doc["temperature"] | 25;
  config.humidity = doc["humidity"] | 60;
  config.moisture = doc["moisture"] | 30;
  config.lightLevel = doc["luminosity"] | 800;
  doc.clear();
  }

// Loads the
// configuration from a file
void loadConfiguration() {
  // Open file for reading
  File file = SPIFFS.open(filename);
  Serial.println("opened config file for reading");
  doc.clear();
  deserializeJson(doc, file);
  // Copy values from the JsonDocument to the Config
  config.lightLevel = doc["light"] | 12000;
  config.temperature = doc["temperature"] | 25;
  config.humidity = doc["humidity"] | 60;
  config.moisture = doc["moisture"] | 70;
  config.ssid = doc["ssid"] | "isempty";
  config.password = doc["password"] | "isempty";
  config.wifipassword = doc["wifipassword"] | "isempty";
  config.username = doc["username"] | "isempty";
  doc.clear();
  file.close();
}

// Saves the configuration to a file
void saveConfiguration() {
  SPIFFS.remove(filename);

  // Open file for writing
  File file = SPIFFS.open(filename, FILE_WRITE);
  if (!file) {
    Serial.println(F("Failed to create file"));
    return;
  }

  // Allocate a temporary JsonDocumen
doc.clear();
  // Set the values in the document
  doc["light"] = config.lightLevel;
  doc["temperature"] = config.temperature;
  doc["humidity"] = config.humidity;
  doc["moisture"] = config.moisture;
  doc["ssid"] = config.ssid;
  doc["password"] = config.password;
  doc["wifipassword"]=config.wifipassword;
  doc["username"] = config.username;


  
  // Serialize JSON to file
  if (serializeJson(doc, file) == 0) {
    Serial.println(F("Failed to write to file"));
  }

  // Close the file
  file.close();
}
