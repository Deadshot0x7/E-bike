#include "timer.h"

Timer timer;

const int LM393 = 2;
int relay = 3;
int counter = 0;
void setup() {
  attachInterrupt(digitalPinToInterrupt(LM393), count, RISING);
  Serial.begin(115200);
  timer.setInterval(1000);
  timer.setCallback(RPM);
  timer.start();
  pinMode(relay, OUTPUT);
}

void count() {
  counter++;
}

void RPM() {
  Serial.println(counter * 60);
  counter = 0;
}

void loop() {
  timer.update();
  if (counter ==0)
  {
    digitalWrite(relay,HIGH); 
  }
}