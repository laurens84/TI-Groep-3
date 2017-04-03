#pragma config(Sensor, S1,     BWsensor,       sensorLightActive)
#pragma config(Sensor, S2,     RGBsensor,      sensorColorNxtRED)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, driveRight, encoder)
#pragma platform(NXT)

#include "header.c"

task main() {
  changeSpeedRampingParms(motorA, 15, 5, 15, 5);
  startTask(bluetooth);
  while (1) {
    while(btCmd != 0) {
      collision();
      lineFollower(leftSensorSpeed(), rightSensorSpeed());
    }
    if ((nMotorRunState[motorB] != runStateIdle) || (nMotorRunState[motorC] != runStateIdle)){
			rem(30);
		}
  }
}
