/// @file

/*! \brief Een functie die de robot rustig laat remmen
 *
 * de fucntie gaat gelijdelijk aan de hand van een formule de snelheid afnemen
 * als een object dichter bij is dan 7 cm woorden de motors op 0 gezet.
 *
 *
 * \param[in] Int afstand de afstnd tot het object gemeten door sensor 3
 *
 */
void rem(int afstand){
speed_left = motor[leftMotor];
speed_right = motor[rightMotor];
motor[leftMotor] = (int) (speed_left * ((((float) SensorValue[RGBLsensor] - SLMIN) / (SLMAX-SLMIN))));
motor[rightMotor] = (int) (speed_right * ((((float) SensorValue[RGBRsensor] - SRMIN) / (SRMAX-SRMIN))));
	if (afstand <= 10){
		speed_left = 0;
		speed_right = 0;
		motor[motorB] = speed_left;
		motor[motorC] = speed_right;
		return;
}
if (speed_left > speed_right){
	speed_right = speed_left;
} else {
	speed_left = speed_right;
	}

clearTimer(T1);
	while (speed_left > 0 && speed_right > 0){

		if (SensorValue[S3] <= 7){
			speed_left = 0;
			speed_right = 0;
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
			delay(1500);
			return;
}

		//om de duizend microseconde word de snelheid bij gewerkt.
	if (time1[T1] >= 175){
			speed_left = speed_left -   ((30/ afstand) * 5 );
			speed_right = speed_right - ((30/ afstand) * 5 );

			//checkt als niet 1 van snelheidswaarde niet op min staan
			if (speed_left < 0){
			speed_left = 0;
			}
			if (speed_right < 0){
			speed_right = 0;
			}
			motor[leftMotor] = (int) (speed_left * ((((float) SensorValue[RGBLsensor] - SLMIN) / (SLMAX-SLMIN))));
			motor[rightMotor] = (int) (speed_right * ((((float) SensorValue[RGBRsensor] - SRMIN) / (SRMAX-SRMIN))));
			clearTimer(T1);
		}
		}
			speed_left = 0;
			speed_right = 0;
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
		}
