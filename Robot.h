#ifndef _ROBOT_H
#define _ROBOT_H

#pragma platform(NXT)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Sensor, S1,     BWsensor,       sensorLightActive)
#pragma config(Sensor, S2,     RGBsensor,      sensorColorNxtRED)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, driveRight, encoder)

int speed_right = 25;
int speed_left = 25;
int object = 0;

//variables voor bluetooth.c
long nLastXmitTimeStamp = nPgmTime;
long nDeltaTime         = 0;
const int kMaxSizeOfMessage = 30;
const int INBOX = 5;

#include "bluetooth.c"
#include "rem.c"
#include "collision.c"
#include "lijnvolger.c"
#include "sensors.c"

#endif /* _ROBOT_H */
