bool leftSensor(){
  if (SensorValue[BWsensor] < 50){
    // zwart links
    return true;
  }
  else{
    // wit
    return false;
  }
}

bool rightSensor(){
  if (SensorValue[RGBsensor] < 40){
    // zwart rechts
    return true;
  }
  else{
    // wit
    return false;
  }
}
