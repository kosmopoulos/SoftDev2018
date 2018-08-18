//Defines the function to use the laser
void laserEngrave(double laserBrightness) {
  //Maps out brightness from 0-1 to 1-100 to obtain as a percentage then sends signal to turn on laser
  map(laserBrightness, 0, 100, 0, 255);
  analogWrite(laserPin, laserBrightness);
}

void laserOff() {
  analogWrite(laserPin, 0);
}
