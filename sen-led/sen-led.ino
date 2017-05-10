void openled(int pin, int spd)
{
  digitalWrite(pin, HIGH);
  delay(spd);
  digitalWrite(pin, LOW);
  delay(spd);
}

void setup() {
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(4)==HIGH){
    openled(10,300);
    }

}
