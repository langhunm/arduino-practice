bool start;
bool hongwai;
int style;
bool change;

void setstart(){
  start=true;
  change=true;
  }
void openled(int pin, int spd)
{
  digitalWrite(pin, HIGH);
  delay(spd);
  digitalWrite(pin, LOW);
  delay(spd);
}


void setup() {
Serial.begin(4800);
pinMode(2, INPUT_PULLUP); //sensor 
pinMode(10, OUTPUT);
pinMode(5, INPUT);
attachInterrupt(0, setstart, HIGH);
start=false;
hongwai=false;
style=1;
change=false;


}

void loop() {
if(digitalRead(5)==HIGH){
    openled(10,300);
    }

}
