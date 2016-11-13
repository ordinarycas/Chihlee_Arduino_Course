int potpin=0;  //定義類比介面A0
int ledpin=13; //定義數位介面13
int val=0;     //將定義變數val,並賦初值0
void setup(){
  pinMode(ledpin,OUTPUT); //定義數位介面為輸出介面
  Serial.begin(9600);     //設置串列傳輸速率為9600
}
void loop(){
  digitalWrite(ledpin,HIGH); //點亮數位介面13 的LED
  delay(500); //延時0.5 秒
  digitalWrite(ledpin,LOW);  //熄滅數位介面13 的LED
  delay(500); //延時0.5 秒
  val=analogRead(potpin); //讀取類比介面0 的值，並將其賦給val
  Serial.println(val); //顯示出val 的值
}

