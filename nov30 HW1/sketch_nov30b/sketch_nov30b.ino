#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("Rong007");//請改名
  pinMode(18,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if(BTdata=="SendLED OFF"){
      digitalWrite(18,LOW);
      }
       if(BTdata=="SendLED ON"){
      digitalWrite(18,HIGH);
      }
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
