#pragma systemFile

#ifndef LIB_H_
#define LIB_H_

void
clearLCDLines () {
	clearLCDLine(0);
	clearLCDLine(1);
}

void
waitForReleased5U () {
	while (vexRT[Btn5U]){} wait1Msec(25);
}

void
waitForReleased5D () {
	while (vexRT[Btn5D]){} wait1Msec(25);
}

void
waitForReleased6U () {
	while (vexRT[Btn6U]){} wait1Msec(25);
}

void
waitForReleased6D () {
	while (vexRT[Btn6D]){} wait1Msec(25);
}

void
waitForReleased7U () {
	while (vexRT[Btn7U]){} wait1Msec(25);
}

void
waitForReleased7R () {
	while (vexRT[Btn7R]){} wait1Msec(25);
}

void
waitForReleased7D () {
	while (vexRT[Btn7D]){} wait1Msec(25);
}

void
waitForReleased7L () {
	while (vexRT[Btn7L]){} wait1Msec(25);
}

void
waitForReleased8U () {
	while (vexRT[Btn8U]){} wait1Msec(25);
}

void
waitForReleased8R () {
	while (vexRT[Btn8R]){} wait1Msec(25);
}

void
waitForReleased8D () {
	while (vexRT[Btn8D]){} wait1Msec(25);
}

void
waitForReleased8L () {
	while (vexRT[Btn8L]){} wait1Msec(25);
}

#include "util.h"
#include "motorLibrary.h"

#endif
