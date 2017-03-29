void rem(int afstand){
	clearTimer(theTimer);
	while (speed >= 0){
		if (time1[theTimer] > 1000){
			speed_left = speed_left - (30/ afstand) * 10
			speed_right = speed_right - (30/ afstand) * 10
			motor[motorB] = speed_left;
			motor[motorC] = speed_right;
			clearTimer(theTimer);
		}
	}
}