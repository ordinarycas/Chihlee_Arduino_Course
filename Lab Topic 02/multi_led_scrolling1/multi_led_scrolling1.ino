// 跑馬燈範例程式
const byte startPin = 2;  // 宣告儲存起始腳位的常數
const byte endPin = 6;   // 宣告儲存結束腳位的常數
byte lightPin = startPin;  // 儲存目前點亮的腳位的變數

void setup() {
  for (byte i = startPin; i <= endPin; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  for (byte i=startPin; i<=endPin; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(lightPin, HIGH);
  if (lightPin < endPin) {
    lightPin ++;
  } 
  else {
    lightPin = startPin;
  }
  delay(100);
}

