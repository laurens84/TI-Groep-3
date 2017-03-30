#define BWBLACK 55	//Black
#define RGBBLACK 30	//Black

bool leftSensor()
{
	if (SensorValue[BWsensor] < BWBLACK){
		// zwart links
		return true;
	}
	else{
		// wit
		return false;
	}
}

bool rightSensor()
{
	if (SensorValue[RGBsensor] < RGBBLACK){
		// zwart rechts
		return true;
	}
	else{
		// wit
		return false;
	}
}
