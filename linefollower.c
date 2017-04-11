/// @file
/// \mainpage Author Information
///
///  linefollower
///  Glenn Koning
///  11-4-2017
///
/// \section linefollower Linefollower in action
///
/// De lijnvolger volgt een zwarte lijn doormiddel van 2 kleurensensoren.
///
/// Hoe werkt dit precies? :
/// Linker sensor stuurt rechter motor aan.
/// Rechter sensor stuurt linker motor aan.

/*! \brief LeftSensorSpeed function to change speed value of speed_left
 *
 *  Verhoogt of verlaagd speed_left waarde aan de hand van sensor waarde.
 *
 * \param[in] SensorValueLeft Int SensorValueLeft <sensor waarde links als input>
 */
void leftSensorSpeed(int SensorValueLeft) // RGBsensor left
{
	if (SensorValueLeft <= SLMIN){
		if (speed_left < STOP){
			speed_left++;
		}
		else if (speed_left > STOP){
			speed_left--;
		}
		else{
			speed_left = STOP;
		}
	}
	else if (SensorValueLeft >= SLMAX){
		if (speed_left < SPEED){
			speed_left++;
		}
		else if (speed_left > SPEED){
			speed_left--;
		}
		else{
			speed_left = SPEED;
		}
	}
	else {
		int value = (int)((((float)SensorValueLeft - SLMIN) / (SLMAX-SLMIN)) * SPEED);	// calculate speed value from sensor value when it is between SLMIN and SLMAX
		if (speed_left < value){
			speed_left++;
		}
		else if (speed_left > value){
			speed_left--;
		}
		else{
			speed_left = value;
		}
	}
}

/*! \brief RightSensorSpeed function to change speed value of speed_right
 *
 *  Verhoogt of verlaagd speed_right waarde aan de hand van sensor waarde.
 *
 * \param[in] SensorValueRight Int SensorValueRight <sensor waarde rechts als input>
 */
void rightSensorSpeed(int SensorValueRight) // RGBsensor right
{
	if (SensorValueRight <= SRMIN){
		if (speed_right < STOP){
			speed_right++;
		}
		else if (speed_right > STOP){
			speed_right--;
		}
		else{
			speed_right = STOP;
		}
	}
	else if (SensorValueRight >= SRMAX){
		if (speed_right < SPEED){
			speed_right++;
		}
		else if (speed_right > SPEED){
			speed_right--;
		}
		else{
			speed_right = SPEED;
		}
	}
	else {
		int value = (int)((((float)SensorValueRight - SRMIN) / (SRMAX-SRMIN)) * SPEED);		// calculate speed value from sensor value when it is between SLMIN and SLMAX
		if (speed_right < value){
			speed_right++;
		}
		else if (speed_right > value){
			speed_right--;
		}
		else{
			speed_right = value;
		}
	}
}

/*! \brief Turn function to turn the robot
 *
 *  Met deze functie kan je de robot in elke gewenste richting draaien.
 *
 * \param[in] direction Int direction <Geef een richting aan waar je naartoe wilt draaien>
 */
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
			delay(200);
			break;
		case back:
			motor[rightMotor] = 50;
			motor[leftMotor] = -50;
			delay(730);
			motor[rightMotor] = STOP;
			motor[leftMotor] = STOP;
			break;
		case left_until:
			motor[leftMotor] = 50;
			motor[rightMotor] = STOP;
			delay(200);
			while (SensorValue[RGBRsensor] != SRMIN){
				motor[leftMotor] = 50;
				motor[rightMotor] = STOP;
			}
			break;
		case right_until:
			motor[rightMotor] = 50;
			motor[leftMotor] = STOP;
			delay(200);
			while (SensorValue[RGBLsensor] != SLMIN){
				motor[rightMotor] = 50;
				motor[leftMotor] = STOP;
			}
			break;
	}
}

/*! \brief wsitForBTCMD function to give the robot bluetooth commands
 *
 *  Wanneer de robot geen instructies heeft zal hij stil staan.
 *	Bij de commando's 'L' = links, 'R' = rechts, 'U' = vooruit, 'D' = achteruit, zal de robot die kant op draaien met de turn functie.
 */
void waitForBTCmd(){
	while (btCmd == 0){					 // while btcmd is 0 robot waits for instructions.
		motor[rightMotor] = STOP;
		motor[leftMotor] = STOP;
	}
	if (btCmd == 'L'){					// turn left
		turn(left_until);
		btCmd = 0;
	}
	else if (btCmd == 'R'){			// turn right
		turn(right_until);
		btCmd = 0;
	}
	else if (btCmd == 'U'){			// forwards
		turn(front);
		btCmd = 0;
	}
	else if (btCmd == 'D'){			// backwards
		turn(back);
		btCmd = 0;
	}
	else {											// stop
		motor[rightMotor] = STOP;
		motor[leftMotor] = STOP;
		btCmd = 0;
		// rem(10);
	}
}

/*!	\brief LineFollower to follow the black line.
 *
 *  Roept de leftSensorSpeed en rightSensorSpeed functie aan om de waardes van speed_left en speed_right te updaten.
 *  Als beide sensoren de zwarte lijn zien zal de robot een kruising detecteren en wordt de waitForBTCmd functie aangeroepen.
 *  Anders worden de motoren met de snelheidswaardes uit speed_left en speed_right aangestuurd.
 */

void lineFollower(){
	leftSensorSpeed(SensorValue[RGBLsensor]);
	rightSensorSpeed(SensorValue[RGBRsensor]);
	if (SensorValue[RGBLsensor] <= SLMIN && SensorValue[RGBRsensor] <= SRMIN){	// Crossing detected
		waitForBTCmd();
	}
	else {
		motor[rightMotor] = speed_right;
		motor[leftMotor] = speed_left;
	}
}
