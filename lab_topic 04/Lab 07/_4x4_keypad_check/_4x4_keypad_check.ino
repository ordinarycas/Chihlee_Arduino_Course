#define SERIAL_BAUDRATE 19200
// 定義矩陣鍵盤的針腳（A~H）與Arduino腳位的連接關係
#define A_PIN 9
#define B_PIN 8
#define C_PIN 7
#define D_PIN 6
#define E_PIN 5
#define F_PIN 4
#define G_PIN 3
#define H_PIN 2
#define COL 4 // 4直欄
#define ROW 4 // 4橫列

// 使用結構儲存Arduino腳位與矩陣鍵盤針腳的連接關係
typedef struct{
  int arduinoPin;
  char keypadPin;
}PinMapping;
PinMapping pins[COL+ROW] = {
  {A_PIN, 'A'}, {B_PIN, 'B'}, {C_PIN, 'C'}, {D_PIN, 'D'},
  {E_PIN, 'E'}, {F_PIN, 'F'}, {G_PIN, 'G'}, {H_PIN, 'H'},
};

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
}
void loop() {
  for(int i = 0; i < COL+ROW; i++){ // 逐一測試每個針腳
    pinMode(pins[i].arduinoPin, OUTPUT);
    digitalWrite(pins[i].arduinoPin, LOW); // 設為低電位
    for(int j = 0; j < COL+ROW; j++){
      if(pins[j].arduinoPin != pins[i].arduinoPin){
        pinMode(pins[j].arduinoPin, INPUT_PULLUP); // 啟用內建的上拉電阻

        // 若某鍵被按下，其狀態會是LOW
        if(digitalRead(pins[j].arduinoPin) == LOW){
          Serial.print(pins[i].keypadPin); // 輸出是哪兩個針腳的交叉處
          Serial.print(" and ");
          Serial.println(pins[j].keypadPin);
        }
      }
    }
    digitalWrite(pins[i].arduinoPin, HIGH);
    pinMode(pins[i].arduinoPin, INPUT);
  }
}

