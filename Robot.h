#ifndef _ROBOT_H
#define _ROBOT_H

#pragma config(Sensor, S3,     sonar,          sensorSONAR)
#pragma config(Sensor, S1,     BWsensor,       sensorLightActive)
#pragma config(Sensor, S2,     RGBsensor,      sensorColorNxtRED)

int speed_right = 25;
int speed_left = 25;
int object = 0;

#endif /* _ROBOT_H */
