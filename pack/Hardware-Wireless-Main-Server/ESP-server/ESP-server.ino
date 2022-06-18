#pragma once
#include "soc/timer_group_struct.h"
#include "ScreenHandler.h"
#include "soc/timer_group_reg.h"
#include "webPages.h"
// Set your access point network credentials
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
const char *ssid = "Xiaomi_615C";
const char *password = "roman24/7";

TaskHandle_t Task1;
TaskHandle_t Task2;
//Your IP address or domain name with URL path

const char *APssid = "ESP-Server";
const char *APpassword = "123321ZX";


/*
  connects to wifi with global ssid and password parameters which are aquired from SPIFFS
*/
void connectWiFi(){
  Serial.print("Setting AP (Access Point)…");
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    yield();
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  }
  
/*
  setups async webserver with hardcoded ip address
*/
void setupAsyncWebServer(){
  Serial.println("settig up soft ap to create server");
  WiFi.softAP(APssid, APpassword);
  delay(200);
  if (!WiFi.softAPConfig(IPAddress(192, 168, 5, 1), IPAddress(192, 168, 5, 1), IPAddress(255, 255, 255, 0))) {
    Serial.println("STA Failed to configure");
  }
  Serial.print("client AP IP address: ");
  Serial.println(WiFi.softAPIP());
  
  // when sensor module sends data to this endpoint, updates climate config and resends aquired data to global server
  server.on("/sensorData", HTTP_POST, 
      [](AsyncWebServerRequest *request){},
      [](AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final){},
      [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
      {
        if(index + len == total){
        Serial.println(String((char*)data));
        yield();
        request->send(200);
        yield();
        postData(String((char*)data));
        updated = true;
        } else{
          Serial.println("Check sum failed, corrupted data, wait for resend");
          request->send(419);
          }
      });
  server.on("/login", HTTP_POST, 
      [](AsyncWebServerRequest *request){},
      [](AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final){},
      [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
      {
        Serial.println(String((char*)data));
        if(index + len == total){
          request->send(200);
          saveLoginData(String((char*)data));
          isLogged = true;
          updated = true;
        }
        });
      yield();
   server.on("/login", HTTP_GET,[](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
    });
  yield();
  server.begin();
  }

void AsyncServer(void * pvParameters) {
  yield();
   setupAsyncWebServer();
   Serial.println("initialized webserver");
   for(;;){
    
   TIMERG0.wdt_wprotect=TIMG_WDT_WKEY_VALUE;
  TIMERG0.wdt_feed=1;
  TIMERG0.wdt_wprotect=0;
    delay(10);
   }
  }


void HandleMenu(void * pvParameters){
  Serial.println("handlemenu");
  setupScreen();
  drawPage(0);
  for(;;){
  Serial.println("handlemen loou");
  yield();
  handleScreenMenu();
  delay(500);
    }
  }
  
void setup() {
  Serial.begin(115200);
  SPIFFS.begin();
  loadConfiguration();
  connectWiFi();
  setupScreen();
   Serial.println("setting up thread");   
    xTaskCreatePinnedToCore(
    AsyncServer, /* Task function. */
    "Task1",   /* name of task. */
    100000,     /* Stack size of task */
    NULL,      /* parameter of the task */
    1,         /* priority of the task */
    NULL,    /* Task handle to keep track of created task */
    0);   
}
void loop(){
  handleScreenMenu();
  delay(100);
  }
