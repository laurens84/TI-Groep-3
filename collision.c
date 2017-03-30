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
		sensorstate = 0;
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
		sensorstate = 1;
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
		sensorstate = 2;
	}
}

void collision() {
	while (SensorValue[S3] < 30) stop();
}
