/*
   程序原理：
   初始化
   等待开始
   循环执行
   有消息事件 处理消息事件 处理完后继续执行

   目前问题：消息发不过来

*/
#include <Wire.h>

bool start;
bool hongwai;
int style;


void setup() {
  // set up Serial
  Serial.begin(4800);
  Wire.begin(1);//设置i2c
  Wire.onReceive(receiveEvent); // register event
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH); // turn on led
  delay(800);
  digitalWrite(11, LOW); // turn on led
  delay(800);
}

void receiveEvent()
{
  int av = Wire.available();
  Serial.print("av is:");
  Serial.println(av);
  digitalWrite(13, HIGH); // turn on led
  delay(100); // delay for 500 ms
  digitalWrite(13, LOW); // turn off led
  //  delay(100); // delay for 500 ms

  byte c = Wire.read();
  Serial.print("c is:");
  Serial.println(c);
}
