void collision(){
	if (SensorValue[S3] < 30){
		rem(SensorValue[S3]);
		motor[motorA] = 15;
		delay(500);
		motor[motorA] = 0;

	}
	else return;
}
