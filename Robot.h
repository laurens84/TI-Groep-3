#ifndef _ROBOT_H
#define _ROBOT_H

#pragma config(Sensor, S1,     BWsensor,       sensorLightActive)
#pragma config(Sensor, S2,     RGBsensor,      sensorColorNxtRED)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)

int speed_right = 25;
int speed_left = 25;

#include "bluetooth.c"
#include "collision.c"
#include "lijnvolger.c"
#include "rem.c"
#include "sensors.c"

#endif /* _ROBOT_H */
