//functie die remt

//input int afstand, afstand tot object in centimeters 
void rem(int afstand){
if (afstand <= 7){
	speed_left = 0;
		speed_right = 0;
		motor[motorB] = speed_left;
		motor[motorC] = speed_right;
		return;
}
//motors snelheid gelijk maken aan de langsaamste motor
if (speed_left > speed_right){
	speed_right = speed_left;
} else {
	speed_left = speed_right;
	}
clearTimer(T1);
	while (speed_left > 0 && speed_right > 0){
		//nood stop als afstand kleiner is dan 7 cm
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
			motor[motorB] = (int) (speed_left * ((((float) SensorValue[RGBLsensor] - RGBMIN) / (RGBMAX-RGBMIN))));
			motor[motorC] = (int) (speed_right * ((((float) SensorValue[RGBRsensor] - RGBMIN) / (RGBMAX-RGBMIN))));
			clearTimer(T1);
		}
		}
			speed_left = 0;
			speed_right = 0;
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
		}
