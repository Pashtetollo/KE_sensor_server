# Hardware-Wireless-Sensor

<h3>This module represents a code for battery-powered module with sensors for measuring climate units, such as temperature, humidity, luminosity, etc.</h3>

- On power-up this sensor module connects to the main local server created by the main module and sends data from it's sensors to the main module, after what enters deep sleep mode for preserving it`s charge.
- Duration of deep sleep (which corresponds to the interval of reading data from sensors) is hardcoded at 30 min, but can be updated during transfering of sensor data (if the interval was changed by user on local/remote site)


<h2>Setup</h2> 

To setup a device, upload a code to a ESP8266 with programmator or ide such as ArduinoIDE/PlatformIO
<h3>Used side libraries:</h3> 

- Arduino core for ESP8266: https://github.com/esp8266/Arduino