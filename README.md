# SPUR-FLYS Library

This is a library created for RobotC and for use on SPUR-FLYS (Team 21) by Jess Zarchi

The library contains the following:
  - TrueSpeed for all ports
  - Custom controller curves
  - Custom motor setup
  - Rewritten competition control
  - Rerun
  - And more to come
  
Overview of the main functions:
  - clearLcdLines ();
  - trueSpeed (int iPort, int iInput);
  - clearAllIME ();
  - setAllMotor393 ();
  - setAllMotor269 ();
  - motorSetup (tMotor iPort, bool bIsReverse, enTrueSpeed bIsTrueSpeed, bool bSlew);
  - motorSetup (tMotor iPort, bool bIsReverse, enTrueSpeed bIsTrueSpeed);
  - motorSetup (tMotor iPort, bool bIsReverse);
  - motorSet (int iPort, int iSpeed);
  - logDrive (int iInput, float iMultiply);
  - testAllMotors();
  - tan (float fInput);
  - tanDegrees (float fInput);
  - clipNum (int iInput, int iHigh, int iLow);
