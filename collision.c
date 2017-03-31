void stop (){
	motor[motorB] = 0;
	motor[motorC] = 0;
}

void look(int d) {
	if (d == front){
		if (sensorstate == left) {
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle);
		}
		else if (sensorstate == right) {
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle);
		}
		sensorstate = front;
	}
	else if (d == left){
		if (sensorstate == front){
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle);
		}
		else if (sensorstate == right){
			nMotorEncoderTarget[motorA] = 200;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle);
		}
		sensorstate = left;
	}
	else if (d == right){
		if (sensorstate == front){
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle);
		}
		else if (sensorstate == left){
			nMotorEncoderTarget[motorA] = 200;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle);
		}
		sensorstate = right;
	}
}

void collision() {
	while (SensorValue[S3] < 30) rem(SensorValue[S3]);
}
