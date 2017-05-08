


void openled(int pin, int sped)
{
  digitalWrite(pin, HIGH);
  delay(sped);
  digitalWrite(pin, LOW);
  delay(sped);
}

void intter(){
  Serial.println("intter");
  openled(13,800);
  }



void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, intter, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
