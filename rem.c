//functie die remt
void rem(int afstand){
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
	if (time1[T1] >= 350){
			speed_left = speed_left -   ((30/ afstand) * 10 ) ;//((((float) SensorValue[RGBLsensor] - RGBMIN) / (RGBMAX-RGBMIN)));
			speed_right = speed_right - ((30/ afstand) * 10 ) ;//((((float) SensorValue[RGBRsensor] - RGBMIN) / (RGBMAX-RGBMIN)));

			//checkt als niet 1 van snelheidswaarde niet op min staan
			if (speed_left < 0){
			speed_left = 0;
			}
			if (speed_right < 0){
			speed_right = 0;
			}
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
			clearTimer(T1);
		}
		}
			speed_left = 0;
			speed_right = 0;
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
		}
