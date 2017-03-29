task collision(){
	while(1){
		if (SensorValue[S3] < 30) object = 1;
		else object = 0;
		delay(100);
	}
}
