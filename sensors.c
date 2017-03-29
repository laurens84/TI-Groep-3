#define BWMIN 49	//Black
#define BWMAX 75	//White

#define RGBMIN 19	//Black
#define RGBMAX 56	//White

#define FACTOR 100

int leftSensor() // BWsensor
{
	if (SensorValue[BWsensor] =< BWMIN){
		float x = (1 / (BWMAX-BWMIN)) * FACTOR;
		return x;
	}
	else {
		float x = ((SensorValue[BWsensor] - BWMIN) / (BWMAX-BWMIN)) * FACTOR;
		return x;
	}
}

int rightSensor() // RGBsensor
{
	if (SensorValue[RGBsensor] =< RGBMIN){
		float x = (1 / (RGBMAX-RGBMIN)) * FACTOR;
		return x;
	}
	else {
		float x = ((SensorValue[RGBsensor] - RGBMIN) / (RGBMAX-RGBMIN)) * FACTOR;
		return x;
	}
}
