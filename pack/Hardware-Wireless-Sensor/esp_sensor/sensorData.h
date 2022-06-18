#include <Wire.h>
#include <BH1750.h>
#include "DHT.h"
#define DHTPIN 4    
#define DHTTYPE DHT11  
#define SENSOR A0
#define BH_SCL 0 //D3
#define BH_SDA 2 //D4

int temperature =0;
int humidity = 0;
DHT dht(DHTPIN, DHTTYPE);

int getSensorTemp(){
  temperature = dht.readTemperature();
  delay(2000);
  if (isnan(temperature) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return -1;
  }
  return temperature;
}
int getSensorGumidity(){
  humidity = dht.readHumidity();
  delay(2000);
  if (isnan(humidity) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return -1;
  }
  return humidity;
}

int getMoisture(){
  pinMode(SENSOR, INPUT);
  int moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(SENSOR);
  moisture_percentage = ((100*sensor_analog/4095.00));
  return(moisture_percentage);
  }

int getLuminosity(){
  BH1750 lightMeter;
  Wire.begin(BH_SDA, BH_SCL);
  lightMeter.begin();
  while(!lightMeter.measurementReady(true)){
    delay(100);
    }
  int lux = int(lightMeter.readLightLevel());
  return lux;
}
