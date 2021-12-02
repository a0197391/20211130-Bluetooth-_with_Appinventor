#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("Rong007");//請改名
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if(BTdata=="P1 get1"){
      digitalWrite(16,HIGH);
      }
    if(BTdata=="P1 get1P1 get2"){
      digitalWrite(16,HIGH);
      delay(100);
      digitalWrite(16,LOW);
      delay(100);
      digitalWrite(17,HIGH);
      delay(100);
      digitalWrite(17,LOW);
      delay(100);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
    }
     if(BTdata=="P2 get1"){
      digitalWrite(18,HIGH);
      }
      if(BTdata=="P2 get1P2 get2"){
      digitalWrite(18,HIGH);
      delay(100);
      digitalWrite(18,LOW);
      delay(100);
      digitalWrite(19,HIGH);
      delay(100);
      digitalWrite(19,LOW);
      delay(100);
      digitalWrite(18,HIGH);
      digitalWrite(19,HIGH);
      }
      if(BTdata=="dark"){
      digitalWrite(16,LOW);
      digitalWrite(17,LOW);
      digitalWrite(18,LOW);
      digitalWrite(19,LOW);
      }
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
