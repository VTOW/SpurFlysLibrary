#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Mod_Vex_Comp_Control.c"

void
tank (int iSpeedL, int iSpeedR) {
	motorSet(port2,  iSpeedL);
	motorSet(port3,  iSpeedL);
	motorSet(port4,  iSpeedL);
	motorSet(port5,  iSpeedR);
	motorSet(port6,  iSpeedR);
	motorSet(port7,  iSpeedR);
}

void
arm (int iSpeed) {
	motorSet(port10, iSpeed);
	motorSet(port1,  iSpeed);
	motorSet(port8,  iSpeed);
	motorSet(port9,  iSpeed);
}

void
initIO () {
	setAllMotor393();
	motorSetup(port2, false, LINESPEED);
	motorSetup(port3, false, LINESPEED);
	motorSetup(port4, false, LINESPEED);
	motorSetup(port5, false, LINESPEED);
	motorSetup(port6, false, LINESPEED);
	motorSetup(port7, false, LINESPEED);

	motorSetup(port1,  true);
	motorSetup(port8,  false);
	motorSetup(port9,  true);
	motorSetup(port10, false);

	sTeam = "BOTS 'N STUFF";
	bLCDAuton =
	bLCDUserControl =  true;
}

void
pre_auton () {
	clearAllIME();
}

task
autonomous () {
}

task
usercontrol () {
	while (true) {
		tank ((vexRT[Ch3]), (vexRT[Ch2]));
		arm ((vexRT[Btn6U] - vexRT[Btn6D]) * 127);
	}
}
