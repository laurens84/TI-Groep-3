void stop (){
	motor[motorB] = 0;
	motor[motorC] = 0;
}

void collision(){
	if (SensorValue[S3] < 30){
		//rem(SensorValue[S3]);
		stop();
	}
	else return;
}
