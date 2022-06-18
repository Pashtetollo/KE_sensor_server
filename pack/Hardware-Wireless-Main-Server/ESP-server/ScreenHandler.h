#pragma once
#include "FS.h"
#include <SPI.h>
#include <TFT_eSPI.h>
#include "InnerStorage.h"
#include "IntToStr.h"
TFT_eSPI tft = TFT_eSPI();
#define MIN_PAGE 0
#define MAX_PAGE 1
#define CALIBRATION_FILE "/calibrationData"
bool updated = true;
int prevPage =0;
int page = 0;
int startX=0;
int startY=0;
int movedX=0;
int movedY=0;
  unsigned long timeNow = millis();
  uint16_t calibrationData[5];
  uint8_t calDataOK = 0;
  uint16_t x, y;


void setupScreen(){
  tft.init();
  tft.setRotation(1);
  if (!SPIFFS.begin()) {
    Serial.println("Can't init SPIFFS, restarting");
  }

  // check if calibration file exists
  if (SPIFFS.exists(CALIBRATION_FILE)) {
    
  Serial.println("found calibration file");
    File f = SPIFFS.open(CALIBRATION_FILE, "r");
    if (f) {
      if (f.readBytes((char *)calibrationData, 14) == 14)
        calDataOK = 1;
      f.close();
    }
  }
  if (calDataOK) {
    // calibration data valid
    tft.setTouch(calibrationData);
  } else {
  Serial.println("recalibrate");
    // data not valid. recalibrate
    tft.calibrateTouch(calibrationData, TFT_WHITE, TFT_RED, 15);
    // store data
    File f = SPIFFS.open(CALIBRATION_FILE, "w");
    if (f) {
      f.write((const unsigned char *)calibrationData, 14);
      f.close();
    }
  }
}
int selectPage(){
  if(millis()-timeNow < 800){
    return -100;
    } else{
    if (tft.getTouch(&x, &y)) {
      timeNow = millis();
      startX=x;
      for(int i =0; i<20;i++){
      tft.getTouch(&x, &y);
      movedX=x;
      delay(10);
        }
          if ((startX-movedX) > 100 && (page<MAX_PAGE)){
        page++;
        return(1); //+page
        Serial.println(page);
        }
        else if((movedX-startX) >100 && (page>MIN_PAGE)){
        page--;
        return(-1); //-page
        Serial.println(page);
        } else{
          return(10); //press register
          }
movedX=0;
        }
      }
  }

  void drawMenu (String headerText ){
    tft.fillScreen(TFT_BLACK);
    tft.fillRect  (0,0, 480,320, TFT_OLIVE);
    tft.fillRect(0,0, 480,70, TFT_BROWN);
    
    tft.drawRect(0,0, 480,320, TFT_VIOLET);
    tft.drawRect(0,0, 480,70, TFT_VIOLET);
    tft.setCursor(150,10);
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.println(headerText);
    }

    void drawLinesForRecors(){
      for(int i=0;i<6;i++)
         tft.fillRect(20, 80+(i*40), 440, 30,TFT_DARKGREEN);
      }
    void drawSquares(){
          tft.fillRect(20, 90, 210,90,TFT_DARKGREEN);
          tft.fillRect(250, 90,210,90,TFT_DARKGREEN);
          tft.fillRect(20, 200, 210,90,TFT_DARKGREEN);
          tft.fillRect(250, 200, 210,90,TFT_DARKGREEN);
      }
  void drawPage(int pageNum){
    switch(pageNum){
      case(0):
      drawMenu("Main menu");
      drawSquares();
        tft.setTextDatum(CC_DATUM);
        tft.setTextSize(2);
        tft.drawString("Temp, C",130,120);
        tft.drawString(int2str(currentTemperature),130, 155);
        
        tft.setTextDatum(CC_DATUM);
        tft.setTextSize(2);
        tft.drawString("Humidity, %",340,120);
        tft.drawString(int2str(currentHumidity),340, 155);
        
        tft.setTextDatum(CC_DATUM);
        tft.setTextSize(2);
        tft.drawString("Luminosity, lux",130,230);
        tft.drawString(int2str(currentLight),130, 265);
        
        tft.setTextDatum(CC_DATUM);
        tft.setTextSize(2);
        tft.drawString("Soil Moist, %",340,230);
        tft.drawString(int2str(currentMoisture),340, 265);

        
        tft.setTextDatum(TL_DATUM);
        tft.setTextSize(1);
        tft.setCursor(20,300);
        tft.println("Last data updated: ");
        
        tft.setCursor(170,300);
        tft.print(currTime);
        break;
      case(1):
         drawMenu("User parameters");
        tft.setTextDatum(CL_DATUM);
         drawLinesForRecors();
         tft.setTextSize(2);
         tft.drawString("Connected to Wifi: " + config.ssid ,30,95);
         tft.drawString("Username: " + config.username ,30,135);
         tft.drawString("Set temperature: ",30,175);
         tft.drawString(int2str(config.temperature),260,175);
         tft.drawString("Set humidity: ",30,215);
         tft.drawString(int2str(config.humidity),260,215);
         tft.drawString("Set moisture: ",30,255);
         tft.drawString(int2str(config.moisture),260,255);
         tft.drawString("Set light level: ",30,295);
         tft.drawString(int2str(config.lightLevel),260,295);
      break;
      default:
       drawMenu("Default");
        return;
      }    
    }
  
void handleScreenMenu(){
  prevPage = page;
  selectPage();
  if((page!=prevPage) || updated == true){
    updated = false;
    drawPage(page);
  }
}

  
