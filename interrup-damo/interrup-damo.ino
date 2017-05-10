
unsigned long time_isr;

void openled(int pin, int sped)
{
  digitalWrite(pin, HIGH);
  delay(sped);
  digitalWrite(pin, LOW);
  delay(sped);
}

void intter() {
  unsigned long time_isr_tmp;
  unsigned long time_isr_tmp1 = millis();
  time_isr_tmp =  time_isr_tmp1 - time_isr;
  time_isr = time_isr_tmp1;
  Serial.print("hongwai:");
  Serial.println(time_isr_tmp);
//  Serial.println("intter");
  if (time_isr_tmp > 200)
  {
    openled(13, 800);
     Serial.println("intter");
  }
}



void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  time_isr = millis();
  attachInterrupt(0, intter, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
