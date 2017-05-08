/*
   程序原理：
   初始化 控制对象数组
   遍历 程序控制对象数组
   中断处理按键 更新控制对象数

   触发中断 更改控制对象
*/


#include <Wire.h>
#define LED_STRIP_NUM 28


class Ctrl_Single
{
  public:
    bool change;
  private:
    bool start;
    bool hongwai;
    int style;
  public:
    void setStart(bool x)
    {
      start = x;
    }
    void setHongwai(bool x)
    {
      hongwai = x;
    }
    void setStyle(int x)
    {
      style = x;
    }
    bool getStart()
    {
      return start;
    }
    bool getHongwai()
    {
      return hongwai;
    }
    int getStyle()
    {
      return style;
    }
};


void sent(int zhuji, bool a, bool b, int c) {

  Wire.beginTransmission(zhuji); // transmit to device #8
  Wire.write(a);        // sends five bytes
  Wire.write(b);      // sends one byte
  Wire.write(c);
  Wire.endTransmission();    // stop transmitting
}

void sent_test(bool a)
{
  Wire.beginTransmission(1);
  Wire.write(a);
  Wire.endTransmission();
}
void sent_test1(bool a, bool b)
{
  Wire.beginTransmission(1);
  Wire.write(a);
  Wire.write(b);
  Wire.endTransmission();
}

Ctrl_Single led_strip[LED_STRIP_NUM];

void change() {
  int ctl_length = sizeof(led_strip) / sizeof(*led_strip);
  Serial.println(ctl_length);
  int i;
  for (i = 0; i < ctl_length; i++)
  {
    led_strip[i].change = true;
    led_strip[i].setStart(true);
  }
}

void setup() {
  //chu shi hua kongzuiduixiangzu
  int i;
  for (i = 0; i < LED_STRIP_NUM; i++) {
    led_strip[i].change = true;
    led_strip[i].setStart(true);
    led_strip[i].setHongwai(false);
    led_strip[i].setStyle(1);
  }
  //chushihua i2c tongxin
  Wire.begin();

  Serial.begin(9600);
  Serial.println("init finsh!");

  //外部中断初始化
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, change, HIGH);
}



void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (i = 0; i < LED_STRIP_NUM; i++) {
    if (led_strip[i].change) {
      //fa song ming ling zhuangtai dao cong ji
      //      sent(i, led_strip[i].getStart(), led_strip[i].getHongwai(), led_strip[i].getStyle());
      if (i == 1)
      {
        //        sent_test(true);
        //        Serial.println("foraaaaaaaa");
        //        sent_test(false);
        //        Serial.println("forbbbbbbb");
        //        Serial.print("byte:");
        //        Serial.println(sizeof(byte));
        sent(i, led_strip[i].getStart(), led_strip[i].getHongwai(), led_strip[i].getStyle());
        led_strip[i].change = false;
        Serial.println(led_strip[i].change);
      }
      //update status
      led_strip[i].change = false;
//      Serial.println("for");
    }
//    Serial.println(led_strip[i].change);
  }
//  sent(1, led_strip[1].getStart(), led_strip[1].getHongwai(), led_strip[i].getStyle());
//  delay(300);

}
