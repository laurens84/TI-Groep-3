void Aandrijving(float sensor_left,float sensor_right){
	/*
	if (sensor_right == true && speed_right >= 5 ){
		speed_right -= 1;
		speed_left += 1;
		}else if(sensor_left == false && speed_right <= 25){
		speed_right += 1;
		speed_left -= 1;
	}
	if (sensor_left == true && speed_left >= 5 ){
		speed_left -= 1 ;
		speed_right += 1
	}
	else if(sensor_left == false && speed_left <= 25){
		speed_left += 1;
		speed_right -= 1;
	} */
	motor[motorB] =10 + sensor_left();
	motor[motorC] =10 + sensor_right();
}
