/*
	Author: Glenn Koning

*/
#define RGBMIN 20	//Black
#define RGBMAX 60	//White

#define TOP_SPEED 50
#define LOW_SPEED 5

#define STOP 0

int leftSensorSpeed() // BWsensor
{
	if (SensorValue[RGBLsensor] <= RGBMIN){
		return LOW_SPEED;
	}
	else {
		return (int)((((float)SensorValue[RGBLsensor] - RGBMIN) / (RGBMAX-RGBMIN)) * TOP_SPEED);
	}
}

int rightSensorSpeed() // RGBsensor
{
	if (SensorValue[RGBRsensor] <= RGBMIN){
		return LOW_SPEED;
	}
	else {
		return (int)((((float)SensorValue[RGBRsensor] - RGBMIN) / (RGBMAX-RGBMIN)) * TOP_SPEED);
	}
}

void lineFollower(int left_sensor_speed, int right_sensor_speed){
  	if (left_sensor_speed == LOW_SPEED && right_sensor_speed == LOW_SPEED){	// Stop voor kruispunt
  		left_sensor_speed = STOP;
  		right_sensor_speed = STOP;
  	}
  	else {
  		/*Problemen*/
  	}
	motor[rightMotor] = speed_left = left_sensor_speed;
	motor[leftMotor] = speed_right = right_sensor_speed;
}
