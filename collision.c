/// \mainpage Author Information
/// \section Information
///
///     Name:          collision.c
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Date:          29-2-2017
///
/// \section doxygen How it works?
///
/// These functions allows you to let the robot look around and detect objects.

void stop (){
	motor[motorB] = 0;
	motor[motorC] = 0;
}

/*! \brief look
 *
 * This function allows you to let the robot look around and detect objects.
 * It can be called with the following three parameters: left, right and front.
 * Depending of the parameter, the function will rotate the sensor and return 0 if there is not an object detected.
 * If there is an object detected, it will return 1.
 *
 * NOTE! The sensor will not rotate back to it's default state after this function is called!
 *
 */

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

/*! \brief collision
 *
 * This function checks if there is an object within 30CM.
 * If there is an object nearby it wil stop the robot and the music.
 *
 */

void collision() {
	while (SensorValue[S3] < 30) {
		if (sound == 1) {
			stopTask(playTetris);
			sound = 0;
		}
		if ((nMotorRunState[motorB] != runStateIdle) || (nMotorRunState[motorC] != runStateIdle)){
			rem(SensorValue[S3]);
		}
	}
	if (sound == 0) {
		startTask(playTetris);
		sound = 1;
	}
}
