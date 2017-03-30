void stop (){
	motor[motorB] = 0;
	motor[motorC] = 0;
}

void collision(){
	while (SensorValue[S3] < 30) stop();
	}
	return;
}
