int gyro_first =3;
int gyro_second= 4;
int tilt_sensor=5;
int relay_pin=6;
void setup() {
  Serial.begain(9600);
  pin.Mode(gyro_first,Input);
  pin.Mode(gyro_second,Input);
  pin.Mode(tilt_sensor,Input);
  pin.Mode(relay_pin,Output);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Hello World I'm inside Loop function");


}
