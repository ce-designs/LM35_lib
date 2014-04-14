/* 
* LM35.cpp
*
* Created: 13-4-2014 16:31:40
* Author: CE-Designs
* Version: 1.0.0.0 
*/


#include "LM35.h"

// default constructor
LM35::LM35(int tempPin, uint8_t unitOfMeasurement)
{	
	//Resolution = DEFAULT_RESOLUTION;
	TempPin = tempPin;
	UnitOfMeasurement = unitOfMeasurement;
	Resolution = DEFAULT_RESOLUTION;
} //LM35

// default constructor
LM35::LM35(int tempPin, uint8_t unitOfMeasurement, uint8_t resolution)
{
	switch (resolution)
	{
		case DEFAULT_RESOLUTION:
		analogReference(DEFAULT);
		break;
		case HIGH_RESOLUTION:
		analogReference(INTERNAL);
		break;
		default:
		analogReference(DEFAULT);
		break;
	}
	UnitOfMeasurement = unitOfMeasurement;
	Resolution = resolution;
	TempPin = tempPin;
} 

float LM35::Read()
{	
	switch (UnitOfMeasurement + Resolution)
	{
		case 5:
		return readCelcius(analogRead(TempPin));
		case 6:
		return readFahrenheit(analogRead(TempPin));
		case 9:
		return readCelciusHighRes(analogRead(TempPin));		
		case 10:
		return readFahrenheitHighRes(analogRead(TempPin));
		default:
		return 0;
		break;
	}
}

float LM35::readCelcius(int reading)
{	
	return (5.0 * reading * 100.0) / 1024.0;
}

float LM35::readCelciusHighRes(int reading)
{
	return reading / 9.31;
}

float LM35::readFahrenheit(int reading)
{	
	return (((5.0 * reading * 100.0) / 1024.0) * 9.0 / 5.0) + 32.0;
}

float LM35::readFahrenheitHighRes(int reading)
{
	return ((reading / 9.31) * 9.0 / 5.0) + 32.0;
}

void LM35::UseHighResolution()
{
	analogReference(INTERNAL);
}

void LM35::useDefaultResolution()
{
	analogReference(DEFAULT);
}
