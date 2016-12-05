#define RIGHTARM I2C_1
#define LEFTARM  I2C_2
#define RIGHTCHASSIS I2C_3
#define LEFTCHASSIS  I2C_4

task
record () {
	clearDebugStream();

	writeDebugStream("\nautonomous[150][3] = {");

	for (int i = 0; i < 150; i++) {
		int arm = (SensorValue[RIGHTARM] + -SensorValue[LEFTARM]) / 2;
		int rChassis = SensorValue[RIGHTCHASSIS];
		int lChassis = SensorValue[LEFTCHASSIS];
		writeDebugStream("\n{%i, %i, %i}", arm, rChassis, lChassis);

		if (i != 149)
			writeDebugStream(",");
		else
			writeDebugStream("};");

		delay (100);
	}
	allTasksStop();
}
