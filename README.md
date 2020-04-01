## DFRobot_ESP_PH_BY_GREENPONIK Library
---------------------------------------------------------

ESP Ph Reading and Calibration
@ https://github.com/greenponik/DFRobot_ESP_PH_BY_GREENPONIK

>using Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2

>based on DFRobot_PH @ https://github.com/DFRobot/DFRobot_PH


## Example

```C++

#include "DFRobot_ESP_PH.h"
#include <EEPROM.h>

DFRobot_ESP_PH ph;
#define ESPADC 4096.0   //the esp Analog Digital Convertion value
#define ESPVOLTAGE 3300 //the esp voltage supply value
#define PH_PIN 35		//the esp gpio data pin number
float voltage, phValue, temperature = 25;

void setup()
{
	Serial.begin(115200);
	EEPROM.begin(32);//needed to permit storage of calibration value in eeprom
	ph.begin();
}

void loop()
{
	static unsigned long timepoint = millis();
	if (millis() - timepoint > 1000U) //time interval: 1s
	{
		timepoint = millis();
		//voltage = rawPinValue / esp32ADC * esp32Vin
		voltage = analogRead(PH_PIN) / ESPADC * ESPVOLTAGE; // read the voltage
		Serial.print("voltage:");
		Serial.println(voltage, 4);
		
		//temperature = readTemperature();  // read your temperature sensor to execute temperature compensation
		Serial.print("temperature:");
		Serial.print(temperature, 1);
		Serial.println("^C");

		phValue = ph.readPH(voltage, temperature); // convert voltage to pH with temperature compensation
		Serial.print("pH:");
		Serial.println(phValue, 4);
	}
	ph.calibration(voltage, temperature); // calibration process by Serail CMD
}

float readTemperature()
{
	//add your code here to get the temperature from your temperature sensor
}

```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
ESP32  |      √       |             |            | 
ESP8266  |             |        √     |            | 

## Credits

Written by Mickael Lehoux from [@greenponik](https://www.greenponik.com/)

>Based on written by Jiawei Zhang(Welcome to our [website](https://www.dfrobot.com/))

# Tutorial here
[![Tutorial here](http://img.youtube.com/vi/EqFw561pO5k/0.jpg)](https://www.youtube.com/watch?v=EqFw561pO5k "PH Meter with ESP32 and DFRobot PH module (SEN0161-V2)")

### Suscribe on our newsletter here: 
en: http://bit.ly/2NuaKbN

fr: http://bit.ly/2XNf61R

https://www.greenponik.com

## support us
[become a patreon](https://www.patreon.com/bePatron?u=32614023)
