void stop (){
	motor[motorB] = 0;
	motor[motorC] = 0;
}

int look(int d) {
	if (d == front){
		if (sensorstate == left) {
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		else if (sensorstate == right) {
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		sensorstate = front;
	}
	else if (d == left){
		if (sensorstate == front){
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		else if (sensorstate == right){
			nMotorEncoderTarget[motorA] = 200;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		sensorstate = left;
	}
	else if (d == right){
		if (sensorstate == front){
			nMotorEncoderTarget[motorA] = 100;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		else if (sensorstate == left){
			nMotorEncoderTarget[motorA] = 200;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		sensorstate = right;
	}
	if (SensorValue[S3] < 30) return 1;
	else return 0;
}

void collision() {
	if (sound == 1) {
		stopTask(playTetris);
		sound = 0;
	}
	while (SensorValue[S3] < 30) {
		if ((nMotorRunState[motorB] != runStateIdle) || (nMotorRunState[motorC] != runStateIdle)){
			rem(SensorValue[S3]);
		}
	}
	if (sound == 0) {
		startTask(playTetris);
		sound = 1;
	}
}
