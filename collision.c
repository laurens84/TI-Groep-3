void collision(){
	if (SensorValue[S3] < 30){
		rem(SensorValue[S3]);
	}
	else return;
}
