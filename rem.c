//functie die remt
void rem(int afstand){
if (afstand <= 7){
	speed_left = 0;
		speed_right = 0;
		motor[motorB] = speed_left;
		motor[motorC] = speed_right;
		return;
}
/*
if (speed_left > speed_right){
	speed_right = speed_left;
} else {
	speed_left = speed_right;
	} */
clearTimer(T1);
	while (speed_left > 0 && speed_right > 0){
	//om de duizend microseconde word de snelheid bij gewerkt.
	if (time1[T1] > 350){
		if (afstand <= 10){
			speed_left = 0;
			speed_right = 0;
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
			break;
		}
			speed_left = speed_left - (int)   ((30/ afstand) * 10 )* ((((float) SensorValue[RGBLsensor] - RGBMIN) / (RGBMAX-RGBMIN)));
			speed_right = speed_right - (int) ((30/ afstand) * 10 )* ((((float) SensorValue[RGBRsensor] - RGBMIN) / (RGBMAX-RGBMIN)));

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
