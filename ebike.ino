
#include<Wire.h>
int pinOut = 10;
int i = 7 ; // Ir Sensor 
int r=3; // Buzzer
const int MPU_addr=0x68; int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int minVal=265; int maxVal=402;
double x; 
void ir_value()
{
  int statusSensor = digitalRead (i);
  if (statusSensor==1 || statusSensor=0)
  {
    Serial.println("It's Black or White")
    digitalWrite(r,HIGH);
  }
  if (statusSensor == 1 )
  {
    Serial.println("it's a Black ");
    delay(1000);
    digitalWrite(r,HIGH);
    
  }
  if ( statusSensor == 0)
  {
    Serial.println("it's a  White");
    delay(1000);
    digitalWrite(r,HIGH);
    
  }
  else
  {
    digitalWrite(r,LOW);
  }


}

void setup()
{
    pinMode(3,OUTPUT);
    pinMode(7,OUTPUT);
     pinMode(10, OUTPUT); 
     Wire.begin(); Wire.beginTransmission(MPU_addr); 
     Wire.write(0x6B); Wire.write(0); 
     Wire.endTransmission(true); 
     Serial.begin(9600);
} 
void loop()
{ 
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B); Wire.endTransmission(false); 
Wire.requestFrom(MPU_addr,14,true); 
AcX=Wire.read()<<8|Wire.read(); AcY=Wire.read()<<8|Wire.read(); AcZ=Wire.read()<<8|Wire.read();
int xAng = map(AcX,minVal,maxVal,0,180); int yAng = map(AcY,minVal,maxVal,0,180); 
int zAng = map(AcZ,minVal,maxVal,0,180);

x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI); 

Serial.print("AngleX= "); Serial.println(x);

Serial.println("-----------------------------------------"); delay(500);
  if (x >= 60 && x >=  300)
  {
    digitalWrite(pinOut, LOW); delay(10);
  }
else
{
  digitalWrite(pinOut, HIGH); delay(10);
}
ir_value();
}
