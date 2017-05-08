int counter=0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  counter=counter+1;
  Serial.print(counter);
  Serial.print(":");
  Serial.println("Hello World!");
  delay(600);

}
