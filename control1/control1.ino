bool start;
bool hongwai;
int counter;
unsigned long time_isr;
unsigned long time_isr_Start;
/*
   去抖动思路

   如果时间够长 就讲hongwai置真


*/
void zhixing(int style) {
    Serial.println(style);
}
void hongwaiInter() {

  unsigned long time_isr_tmp;
  unsigned long time_isr_tmp1 = millis();
  time_isr_tmp =  time_isr_tmp1 - time_isr;
  time_isr = time_isr_tmp1;
  Serial.print("hongwai:");
  Serial.println(time_isr_tmp);
  if (time_isr_tmp > 200)
  {
    hongwai = true;
    //    zhixing(5);
    Serial.println("hw sucessfull!");
//    delay(1000000);
  }
//  digitalWrite(2, LOW);
}

void setStart() {
  unsigned long time_isr_tmp2;
  unsigned long time_isr_tmp3 = millis();

  time_isr_tmp2 = time_isr_tmp3 - time_isr_Start;
  time_isr_Start = time_isr_tmp3;
  Serial.print("start:");
  Serial.println(time_isr_tmp2);
  if (time_isr_tmp2 > 200)
  {
    Serial.println("start sucessfull!");
    if (!start) {
      start = true;
    }
    else
      start = false;
    Serial.println(start);
  }

}

void setup() {
  start = false;
  hongwai = false;
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, hongwaiInter, HIGH);
  attachInterrupt(1, setStart, HIGH);
  time_isr = millis();
  time_isr_Start = millis();
}

void loop() {
  if (start) {
    //
    zhixing(1);
  }

}
