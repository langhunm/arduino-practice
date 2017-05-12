/*
   向从机定时发送样式指令
   控制从机开始停止

   检测从从机是否在线

*/

#include <Wire.h>
#define START_PIN     2
#define CHANGE_PIN     3

int current_style;
bool changed;
bool start;

void sends(int s)
{ Wire.beginTransmission(s); // transmit to device #8
  Wire.write(s);   
  Serial.println("aa:w");// sends one byte
  Wire.endTransmission(false);
}
bool s_is_avliable(int s) {
  sends(s);

  return true;
}
void setstart() {}
void setchange() {}
void setup() {

  pinMode(START_PIN, INPUT_PULLUP);
  pinMode(CHANGE_PIN, INPUT_PULLUP);
  attachInterrupt(0, setstart, HIGH);
  attachInterrupt(1, setchange, HIGH);
  Serial.begin(19200);

  Wire.begin();


  current_style = 1;
  start = false;
  changed = false;

}

void loop() {
  //  if (s_is_avliable(1))
  //  {
  //    Serial.println("avliable!");
  //  }
  sends(10);
  delay(1000);

  if (start) {
    current_style = current_style + 1;
    delay(800);
  }

}
