/*蓝牙测试*/
#include <Arduino.h>
#include <SoftwareSerial.h>
//蓝牙定义
char val;
const int BT_RX = 3;// Pin3为RX，接HC05的TXD，软串口不一定非是这两个数字脚都可以
const int BT_TX = 9;// Pin9为TX，接HC05的RXD

int led =13;
SoftwareSerial BT(BT_RX, BT_TX );
void setup() {
// put your setup code here, to run once:
BT.begin(9600);
//Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
if(BT.available()>0)
{
val=BT.read();
if(val=='a'){
digitalWrite(led,HIGH);
Serial.println("LED ON");
    }
else if(val=='b'){
digitalWrite(led,LOW);
Serial.println("LED OFF");
    }
  }
}
