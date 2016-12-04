#pragma systemFile

#ifndef UTIL_H
#define UTIL_H

/**
 * Calculates tanget in radians
 *
 * @param 	fInput Inputted angle
 *
 * @return	Tanget of input
 */
#define tan(fInput) sin(fInput) / cos(fInput)

/**
 * Calculates tanget in degrees
 *
 * @param 	fInput Inputted angle
 *
 * @return	Tanget of input
 */
#define tanDegree(fInput) sinDegrees(fInput) / cosDegrees(fInput)

/**
 * Limits a number to a high and a low
 *
 * @param 	iInput Inputted value
 * @param   iHigh  Highest the input can be
 * @param   iLow   Lowest the input can be
 *
 * @return	iInput within iHigh and iLow
 */
#define clipNum(iInput, iHigh, iLow) iInput <= iLow ? iLow : (iInput >= iHigh ? iHigh : iInput)

typedef struct {
	float current;
	float kP;
	float kI;
	float kD;
	float target;
	float error;
	float integral;
	float derivative;
	float lastError;
	float threshold;
	int   deltaTime;
	int   lastTime;
} pid;

#endif
