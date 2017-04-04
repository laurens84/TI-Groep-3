/*
	Author: Glenn Koning

*/

int leftSensorSpeed() // BWsensor
{
	if (SensorValue[RGBLsensor] <= RGBMIN){
		return LOW_SPEED;
	}
	else if (SensorValue[RGBLsensor] >= RGBMAX){
		return TOP_SPEED;
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
	else if (SensorValue[RGBRsensor] >= RGBMAX){
		return TOP_SPEED;
	}
	else {
		return (int)((((float)SensorValue[RGBRsensor] - RGBMIN) / (RGBMAX-RGBMIN)) * TOP_SPEED);
	}
}

void waitForBTCmd(){
	if (btCmd == 'L'){
		// turn left
	}
	else if (btCmd == 'R'){
		// turn Right
	}
	else {
		motor[rightMotor] = STOP;
		motor[leftMotor] = STOP;
	}
}

void lineFollower(int left_sensor_speed, int right_sensor_speed){
  	if (left_sensor_speed == LOW_SPEED && right_sensor_speed == LOW_SPEED){	// Crossing detected
			waitForBTCmd();
  	}
  	else {
			motor[rightMotor] = speed_left = left_sensor_speed;
			motor[leftMotor] = speed_right = right_sensor_speed;
  	}
}
