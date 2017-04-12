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
			nMotorEncoderTarget[motorA] = 90;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		else if (sensorstate == right) {
			nMotorEncoderTarget[motorA] = 90;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		sensorstate = front;
	}
	else if (d == left){
		if (sensorstate == front){
			nMotorEncoderTarget[motorA] = 90;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		else if (sensorstate == right){
			nMotorEncoderTarget[motorA] = 180;
			motor[motorA] = 85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		sensorstate = left;
	}
	else if (d == right){
		if (sensorstate == front){
			nMotorEncoderTarget[motorA] = 90;
			motor[motorA] = -85;
			while (nMotorRunState[motorA] != runStateIdle) {}
		}
		else if (sensorstate == left){
			nMotorEncoderTarget[motorA] = 180;
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
* It will then wait for two seconds. If the object is still there after two seconds, the robot will go and drive around it.
* It will do this by turning his sensor looking if there is room for him to go that way.
* If there is no room for him at his left and right, it will turn around and go back.
* However, if there is room for him, he wil turn left or right(depending on where there is room for him to go)
* The sensor will then turn to the object again and the robot will control it's motors depending on how close he is to the object.
* If the robot sees the line again, it wil stop looking at the object and get himself back on track.
* The music will also begin to play again.
*
*/

void collision() {
	if (SensorValue[S3] < 30) {
		if (sound == 1) {
			stopTask(playTetris);
			sound = 0;
		}
		if ((nMotorRunState[motorB] != runStateIdle) || (nMotorRunState[motorC] != runStateIdle)) rem(SensorValue[S3]);
		startTask(playPause);
		delay(2000);
		if (SensorValue[S3] < 30) {
			object = 1;
			while (SensorValue[S3] < 20) {
				motor[motorB] = -10;
				motor[motorC] = -10;
			}
			while (SensorValue[S3] > 20) {
				motor[motorB] = 10;
				motor[motorC] = 10;
			}
			startTask(playSirene);
			if (!look(left)){
				turn(left);
				look(right);
				while (SensorValue[RGBRsensor] != SRMIN && SensorValue[RGBLsensor] != SLMIN) {
					motor[motorC] = 10;
					if (SensorValue[S3] < 30) motor[motorB] = (SensorValue[S3]);
					else motor[motorB] = 30;
				}
				turn(left_until);
				delay(50);
				motor[motorB] = STOP;
				motor[motorC] = STOP;
				look(front);
			}
			else if (!look(right)){
				turn(right);
				look(left);
				while (SensorValue[RGBRsensor] != SRMIN && SensorValue[RGBLsensor] != SLMIN) {
					motor[motorB] = 10;
					if (SensorValue[S3] < 30) motor[motorC] = (SensorValue[S3]);
					else motor[motorC] = 30;
				}
				turn(right_until);
				delay(50);
				motor[motorB] = STOP;
				motor[motorC] = STOP;
				look(front);
			}
			else {
				while (SensorValue[S3] < 20) {
					motor[motorB] = -10;
					motor[motorC] = -10;
				}
				turn(back);
				look(front);
			}
			object = 0;
		}
	}
	if (sound == 0) {
		startTask(playTetris);
		sound = 1;
	}
}
