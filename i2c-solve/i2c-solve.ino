
#include <Wire.h>
void receive()
{
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(13,LOW);
  delay(300);
  int av = Wire.available();
  char c = Wire.read();
  Serial.println(c);
}



void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(4800);
  Wire.begin(1);
  Wire.onReceive(receive);
}

void loop() {
  // put your main code here, to run repeatedly:

}
