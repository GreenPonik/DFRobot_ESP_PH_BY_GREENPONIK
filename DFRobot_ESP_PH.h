/*
 * file DFRobot_ESP_PH.h * @ https://github.com/GreenPonik/DFRobot_ESP_PH_BY_GREENPONIK
 *
 * Arduino library for Gravity: Analog pH Sensor / Meter Kit V2, SKU: SEN0161-V2
 * 
 * Based on the @ https://github.com/DFRobot/DFRobot_PH
 * Copyright   [DFRobot](http://www.dfrobot.com), 2018
 * Copyright   GNU Lesser General Public License
 *
 * ##################################################
 * ##################################################
 * ########## Fork on github by GreenPonik ##########
 * ############# ONLY ESP COMPATIBLE ################
 * ##################################################
 * ##################################################
 * 
 * version  V1.1
 * date  2019-06
 */

#ifndef _DFROBOT_ESP_PH_H_
#define _DFROBOT_ESP_PH_H_

#include "Arduino.h"

#define PHVALUEADDR 0x00 //the start address of the pH calibration parameters stored in the EEPROM

#define PH_8_VOLTAGE 1122
#define PH_6_VOLTAGE 1478
#define PH_5_VOLTAGE 1654
#define PH_3_VOLTAGE 2010

#define ReceivedBufferLength 10 //length of the Serial CMD buffer

class DFRobot_ESP_PH
{
public:
    DFRobot_ESP_PH();
    ~DFRobot_ESP_PH();
    void calibration(float voltage, float temperature, char *cmd); //calibration by Serial CMD
    void calibration(float voltage, float temperature);
    float readPH(float voltage, float temperature); // voltage to pH value, with temperature compensation
    void begin();                                   //initialization

private:
    float _phValue;
    float _acidVoltage;
    float _neutralVoltage;
    float _voltage;
    float _temperature;

    char _cmdReceivedBuffer[ReceivedBufferLength]; //store the Serial CMD
    byte _cmdReceivedBufferIndex;

private:
    boolean cmdSerialDataAvailable();
    void phCalibration(byte mode); // calibration process, wirte key parameters to EEPROM
    byte cmdParse(const char *cmd);
    byte cmdParse();
};

#endif
