/// @file

/*! \brief Een functie die de robot rustig laat remmen
 *
 * de functie gaat gelijdelijk aan de hand van een formule de snelheid afnemen
 * als een object dichter bij is dan 7 cm woorden de motors op 0 gezet.
 *
 *
 * \param[in] Int afstand de afstand tot het object gemeten door sensor 3
 *
 *
 */
void rem(int afstand){
	//speed_left en speed_right is de maximale snelheid in deze functie
	//speed_left = motor[leftMotor];
	//speed_right = motor[rightMotor];

// motor word aangestuurd aan de hand van de positie op de lijn wat woord gemten met de sensors
//motor[leftMotor] = (int) (speed_left * ((((float) SensorValue[RGBLsensor] - SLMIN) / (SLMAX-SLMIN))));
//motor[rightMotor] = (int) (speed_right * ((((float) SensorValue[RGBRsensor] - SRMIN) / (SRMAX-SRMIN))));

//een nood stop voor als de object te dicht bij is
	/*if (afstand <= 10){
		//snelheid word op 0 gezet
		speed_left = 0;
		speed_right = 0;
		motor[motorB] = speed_left;
		motor[motorC] = speed_right;
		startTask playSecret;
		return;*/
//}
//de snelhied word gelijk gemaat
	if (speed_left > speed_right){
		speed_right = speed_left;
	}
	else {
		speed_left = speed_right;
	}

clearTimer(T1);
//een loop todat de robot stilstaat
	while (speed_left > 0 && speed_right > 0){


		//een check als de object niet te dicht bij is gekomen
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
			// als dat wel het gevalis woord de waarde op 0 gezet
			if (speed_left < 0){
			speed_left = 0;
			}
			if (speed_right < 0){
			speed_right = 0;
			}
			///brief
			//de motors woorden bijgesteld aan de hand van de waardes van de kleuren sensors
			//het gedeelte na speed_left en speed_right zorgt ervoor dat er altijd een getal tussen 0 en 1 uitkomt
			//het getal van 0 en 1 word vermenigvuldig met de maximale snelheid waarvan de maximum steeds omlaag gaat
			motor[leftMotor] = (int) (speed_left * ((((float) SensorValue[RGBLsensor] - SLMIN) / (SLMAX-SLMIN))));
			motor[rightMotor] = (int) (speed_right * ((((float) SensorValue[RGBRsensor] - SRMIN) / (SRMAX-SRMIN))));
			clearTimer(T1);
		}
	}
	//de functie moet altijd zo eindigen dat bijde motoren stilstaan.
	motor[motorB] = 0;
	motor[motorC] = 0;
	//muziekje van een game dat een object gevonden is.
	startTask(playSecret);
}
