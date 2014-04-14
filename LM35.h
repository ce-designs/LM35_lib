/* 
* LM35.h
*
* Created: 13-4-2014 16:31:56
* Author: CE-Designs
* Version: 1.0.0.0 
*/


#ifndef __LM35_H__
#define __LM35_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define CELSIUS 1
#define FAHRENHEIT 2

#define DEFAULT_RESOLUTION 4
#define HIGH_RESOLUTION 8
//
class LM35
{
//variables
public:
	
protected:
		
private:

	int TempPin;
	uint8_t Resolution;
	uint8_t UnitOfMeasurement;

//functions
public:

	LM35(int tempPin, uint8_t unitOfMeasurement);
	LM35(int tempPin, uint8_t unitOfMeasurement, uint8_t resolution);
	
	float Read();	
	void UseHighResolution();
	void useDefaultResolution();
	
protected:

private:

	float readCelcius(int reading);
	float readFahrenheit(int reading);
	float readCelciusHighRes(int reading);
	float readFahrenheitHighRes(int reading);
	

}; //LM35

#endif //__LM35_H__
