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
      delay(50);
			break;
	}
}
