#include <Wire.h>


void openled(int pin, int sped)
{
  digitalWrite(pin, HIGH);
  delay(sped);
  digitalWrite(pin, LOW);
  delay(sped);
}
void sent()
{
  int i;
  for (i = 0; i < 5; i++)
  {
    openled(13, 800);
  }


  Wire.beginTransmission(1); // transmit to device #8
  Wire.write("x is ");
  Serial.println("interrupt call sent function!");
  Wire.endTransmission();
}


void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)

  attachInterrupt(0, sent, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}

