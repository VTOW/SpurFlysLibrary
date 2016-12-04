#pragma systemfile

#ifndef MOTORLIBRARY_H
#define MOTORLIBRARY_H

int originalTrueSpeed[128] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	20, 21, 21, 21, 22, 22, 22, 23, 24, 24,
	25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
	28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
	33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
	37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
	41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
	46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
	52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
	71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
	80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
	88, 89, 89, 90, 90,127,127,127
};

/**
 * Ports 1 and 10 linear rpm remapped values
 */
int L298[128] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 11, 11, 12,
	12, 12, 12, 13, 13, 13, 14, 14, 14, 14,
	15, 15, 15, 16, 16, 16, 17, 17, 17, 18,
	18, 18, 19, 19, 19, 20, 20, 20, 21, 21,
	22, 22, 23, 23, 23, 24, 25, 25, 26, 26,
	26, 27, 27, 28, 28, 29, 29, 30, 30, 31,
	31, 32, 32, 33, 33, 34, 35, 35, 35, 35,
	35, 35, 38, 38, 39, 41, 41, 41, 42, 43,
	45, 46, 47, 47, 48, 49, 49, 50, 51, 52,
	53, 54, 55, 56, 58, 59, 63, 66, 67, 70,
	73, 74, 75, 78, 80, 84, 87, 88, 92, 95,
	97, 100, 105, 108, 114, 117, 121, 122, 124, 127
};

/**
 * Port 2-9 linear rpm remapped values
 */
int MC29[128] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 13, 13, 14,
	14, 14, 14, 15, 15, 15, 15, 16, 16, 16,
	16, 16, 17, 17, 17, 17, 17, 17, 17, 17,
	18, 18, 18, 18, 18, 18, 18, 19, 19, 19,
	19, 19, 20, 20, 20, 20, 21, 21, 21, 22,
	22, 22, 22, 23, 23, 23, 23, 24, 24, 24,
	25, 25, 25, 26, 26, 26, 27, 27, 27, 28,
	28, 28, 29, 29, 30, 30, 30, 31, 31, 32,
	32, 33, 33, 34, 34, 35, 36, 36, 37, 37,
	38, 39, 40, 40, 41, 42, 43, 44, 45, 46,
	46, 48, 49, 50, 51, 53, 55, 56, 58, 60,
	62, 64, 67, 70, 72, 76, 79, 83, 84, 127,
};

/**
 * Makes the controller curve linear
 *
 * @param 	iPort  The port being set
 * @param 	iInput The desired motor value
 *
 * @return	Value to give linear rpm to input
 */
int
trueSpeed (int iPort, int iInput) {
	int iOutput;
	iInput = clipNum(iInput, 127, -127);
	if (iPort == (int)port1 || iPort == (int)port10)
		iOutput = sgn(iInput) * L298[abs(iInput)];
	else
		iOutput = sgn(iInput) * MC29[abs(iInput)];
	return iOutput;
}

int jTrueSpeed(int iInput){
	return sgn(iInput) * originalTrueSpeed[abs(iInput)];
}

/**
 * Clears all I2C ports
 */
void
clearAllIME () {
	SensorValue[I2C_1] =
	SensorValue[I2C_2] =
	SensorValue[I2C_3] =
	SensorValue[I2C_4] =
	SensorValue[I2C_5] =
	SensorValue[I2C_6] =
	SensorValue[I2C_7] =
	SensorValue[I2C_8] = 0;
}

/**
 * Sets all motor types to 393
 */
void
setAllMotor393 () {
	for (int i = 0; i < 10; i++) {
		if (i == (int)port1 || i == (int)port10)
			motorType[i] = tmotorVex393_HBridge;
		else
			motorType[i] = tmotorVex393_MC29;
	}
	wait1Msec(25);
}

/**
 * Sets all motor types to 269
 */
void
setAllMotor269 () {
	for (int i = 0; i < 10; i++) {
		if (i == (int)port1 || i == (int)port10)
			motorType[i] = tmotorVex269_HBridge;
		else
			motorType[i] = tmotorVex269_MC29;
	}
	wait1Msec(25);
}

/**
 * Replaces the built in motor setup
 *
 * @param 	iPort        The port being configured
 * @param 	bIsReverse   If the motor is reversed
 * @param   bIsTrueSpeed If the motor will use trueSpeed
 * @param   bSlew        If the motor will have acceleration curve
 */
bool bMotorReverse[10], bAccelCurve[10], bTrueSpeed[10];
void
motorSetup (tMotor iPort, bool bIsReverse, bool bIsTrueSpeed, bool bSlew) {
	bMotorReverse[iPort] = bIsReverse;
	bTrueSpeed[iPort]    = bIsTrueSpeed;
	bAccelCurve[iPort]   = bSlew;
}

void
motorSetup (tMotor iPort, bool bIsReverse, bool bIsTrueSpeed) {
	bMotorReverse[iPort] = bIsReverse;
	bTrueSpeed[iPort]    = bIsTrueSpeed;
}

void
motorSetup (tMotor iPort, bool bIsReverse) {
	bMotorReverse[iPort] = bIsReverse;
}

/**
 * Sets the motor speed based on the configuration
 *
 * @param 	iPort  The motor being set
 * @param 	iSpeed The motor speed being set
 *
 * @return	Motor set to desired speed
 */
void
motorSet (int iPort, int iSpeed) {
	int iOutput;
	if (bAccelCurve[iPort]) {
		int iError = (bTrueSpeed[iPort] ? trueSpeed(iPort, iSpeed) : iSpeed) - motor[iPort];
		if (abs(iError) >= 4)
			iOutput += sgn(iError) * 3;
		else
			iOutput = iSpeed;
		delay(1);
	} else
		iOutput = bTrueSpeed[iPort] ? trueSpeed(iPort, iSpeed) : iSpeed;
	iOutput = clipNum(iOutput, 127, -127);
	motor[iPort] = bMotorReverse[iPort] ? -iOutput : iOutput;
}

/**
 * Creates a purposely made controller curve
 *
 * @param 	iInput    Input speed (usually will be vexRT)
 * @param 	iMultiply This number will be tuned to change the size of the curve
 *
 * @return	Speed to match desired curve
 */
float
logDrive (int iInput, float iMultiply) {
	return (pow(abs(iInput), iMultiply)) * sgn(iInput);
}

/**
 * Tests all motors for 1 second, used for testing motors
 * to find out what needs to be reversed
 */
void
testAllMotors () {
	clearLCDLines();
	for (int i = 0; i < 10; i++) {
		displayLCDNumber(0, 0, i + 1);
		motorSet(i, 127);
		delay(1000);
		motorSet(i, 0);
		clearLCDLines();
		delay(500);
	}
}

#endif
