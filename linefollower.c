/*
	Author: Glenn Koning

*/
void leftSensorSpeed(int SensorValueLeft) // RGBsensor left
{
	if (SensorValueLeft <= SLMIN){
		if (left_speed < STOP){
			left_speed++;
		}
		else if (left_speed > STOP){
			left_speed--;
		}
		else{
			left_speed = STOP;
		}
	}
	else if (SensorValueLeft >= SLMAX){
		if (left_speed < SPEED){
			left_speed++;
		}
		else if (left_speed > SPEED){
			left_speed--;
		}
		else{
			left_speed = SPEED;
		}
	}
	else {
		int value = (int)((((float)SensorValueLeft - SLMIN) / (SLMAX-SLMIN)) * SPEED);
		if (left_speed < value){
			left_speed++;
		}
		else if (left_speed > value){
			left_speed--;
		}
		else{
			left_speed = value;
		}
	}
}

void rightSensorSpeed(int SensorValueRight) // RGBsensor right
{
	if (SensorValueRight <= SRMIN){
		if (right_speed < STOP){
			right_speed++;
		}
		else if (right_speed > STOP){
			right_speed--;
		}
		else{
			right_speed = STOP;
		}
	}
	else if (SensorValueRight >= SRMAX){
		if (right_speed < SPEED){
			right_speed++;
		}
		else if (right_speed > SPEED){
			right_speed--;
		}
		else{
			right_speed = SPEED;
		}
	}
	else {
		int value = (int)((((float)SensorValueRight - SRMIN) / (SRMAX-SRMIN)) * SPEED);
		if (right_speed < value){
			right_speed++;
		}
		else if (right_speed > value){
			right_speed--;
		}
		else{
			right_speed = value;
		}
	}
}

void turn(int direction){
	switch (direction) {
		case left:
			motor[rightMotor] = STOP;
			motor[leftMotor] = 50;
			delay(750);
			motor[rightMotor] = STOP;
			motor[leftMotor] = STOP;
			break;
		case right:
			motor[rightMotor] = 50;
			motor[leftMotor] = STOP;
			delay(750);
			motor[rightMotor] = STOP;
			motor[leftMotor] = STOP;
			break;
		case front:
			motor[rightMotor] = 50;
			motor[leftMotor] = 50;
			delay(500);
			break;
		case back:
			motor[rightMotor] = 50;
			motor[leftMotor] = -50;
			delay(730);
			motor[rightMotor] = STOP;
			motor[leftMotor] = STOP;
			break;
		case left45:
			motor[rightMotor] = STOP;
			motor[leftMotor] = 50;
			delay(375);
			motor[rightMotor] = STOP;
			motor[leftMotor] = STOP;
			break;
		case right45:
			motor[rightMotor] = 50;
			motor[leftMotor] = STOP;
			delay(375);
			motor[rightMotor] = STOP;
			motor[leftMotor] = STOP;
			break;
	}
}

void waitForBTCmd(){
	while (btCmd == 0){
		motor[rightMotor] = STOP;
		motor[leftMotor] = STOP;
	}
	if (btCmd == 'L'){
		turn(left);
		btCmd = 0;
	}
	else if (btCmd == 'R'){
		turn(right);
		btCmd = 0;
	}
	else if (btCmd == 'U'){
		turn(front);
		btCmd = 0;
	}
	else if (btCmd == 'D'){
		turn(back);
		btCmd = 0;
	}
	else {
		motor[rightMotor] = STOP;
		motor[leftMotor] = STOP;
		btCmd = 0;
		// rem(10);
	}
}

void lineFollower(){
	leftSensorSpeed(SensorValue[RGBLsensor]);
	rightSensorSpeed(SensorValue[RGBRsensor]);
	if (SensorValue[RGBLsensor] <= SLMIN && SensorValue[RGBRsensor] <= SRMIN){	// Crossing detected
		waitForBTCmd();
	}
	else {
		motor[rightMotor] = right_speed;
		motor[leftMotor] = left_speed;
	}
}
