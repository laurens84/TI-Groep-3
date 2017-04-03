/// \mainpage Author Information
/// \section Information
///
///     Name:          main.c
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Date:          28-2-2017
///
/// \section doxygen How it works?
///
/// This is the code where the hardware is defined and the robot will be started.

#pragma config(Sensor, S1,     RGBLsensor,       sensorColorNxtRED)
#pragma config(Sensor, S2,     RGBRsensor,      sensorColorNxtRED)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, driveRight, encoder)
#pragma platform(NXT)

#include "header.c"

/*! \brief main
 *
 * The robot will wait before the command to start is given.
 * When the start command is given the robot will first check if there is an object in the way.
 * The robot will start to follow the line as long as there is no object detected.
 *
 * If the command to stop is given, the robot will stop. If there was music playing, that will stop aswell.
 * Now the robot again, will wait for the command to start.
 *
 */

task main() {
  changeSpeedRampingParms(motorA, 15, 5, 15, 5);
  startTask(bluetooth);
  while (1) {
    while(btCmd == 0) {
      collision();
      lineFollower(leftSensorSpeed(), rightSensorSpeed());
    }
    if ((nMotorRunState[motorB] != runStateIdle) || (nMotorRunState[motorC] != runStateIdle)){
			rem(30);
		}
    if (sound == 1) {
			stopTask(playTetris);
			sound = 0;
		}
  }
}
