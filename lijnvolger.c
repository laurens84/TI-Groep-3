#pragma config(Sensor, S1,     BWsensor,       sensorLightActive)
#pragma config(Sensor, S2,     RGBsensor,      sensorColorNxtRED)
int speed_right = 25;
int speed_left = 25;
void Aandrijving(bool sensor_left,bool sensor_right)

{

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
		}else if(sensor_left == false && speed_left <= 25){
		speed_left += 1;
		speed_right -= 1;
	}
	motor[motorB] = speed_left;
	motor[motorC] = speed_right;
}
bool leftSensor()
{
  if (SensorValue[BWsensor] < 50){
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
  if (SensorValue[RGBsensor] < 40){
    // zwart rechts
    return true;
  }
  else{
    // wit
    return false;
  }
}


//speed = speed - (afstandobjet  * 3.33)  / speed)* 20 )
