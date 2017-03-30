/*
sensor true is black line
sensor false is not black
Standard motor speed is 25
*/

#define TOP_SPEED 50
#define LOW_SPEED 5
#define STOP 0
#define DELAY 5

void Aandrijving(bool sensor_left,bool sensor_right){
	if (sensor_left == false && sensor_right == false){			// Rechtdoor
		speed_left = TOP_SPEED;
		speed_right = TOP_SPEED;
	}
	else if (sensor_left == false && sensor_right == true){	// Naar rechtsdraaien
		for(int i=TOP_SPEED; i>LOW_SPEED; i--){
			speed_right = i;
			speed_left = TOP_SPEED;
			delay(DELAY);
		}
	}
	else if (sensor_left == true && sensor_right == false){ // Naar links draaien
		for(int i=TOP_SPEED; i>LOW_SPEED; i--){
			speed_left = i;
			speed_right = TOP_SPEED;
			delay(DELAY);
		}
	}
	else if (sensor_left == true && sensor_right == true){	// Stop voor kruispunt
		speed_left = STOP;
		speed_right = STOP;
	}
	else {
		/*Problemen*/
	}
	motor[motorB] = speed_left;
	motor[motorC] = speed_right;
}

// 	if (sensor_right == true && speed_right >= 5 ){
// 		speed_right -= 1;
// 		speed_left += 1;
// 	}
// 	else if(sensor_left == false && speed_right <= 25){
// 		speed_right += 1;
// 		speed_left -= 1;
// 	}
// 	if (sensor_left == true && speed_left >= 5 ){
// 		speed_left -= 1 ;
// 		speed_right += 1;
// 	}
// 	else if(sensor_left == false && speed_left <= 25){
// 		speed_left += 1;
// 		speed_right -= 1;
// 	}
// 	motor[motorB] = speed_left;
// 	motor[motorC] = speed_right;
// }