#pragma config(Sensor, S1,     BWsensor,       sensorLightActive)
#pragma config(Sensor, S2,     RGBsensor,      sensorColorNxtRED)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, driveRight, encoder)

#include "header.c"

task main() {
  while (1) {
    collision();
    Aandrijving(leftSensor(), rightSensor());
  }
}
