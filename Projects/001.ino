byte sevenSegment[10][7] = {
//a, b, c, d, e, f, g
 {1, 1, 1, 1, 1, 1, 0},   // 0
 {0, 1, 1, 0, 0, 0, 0},   // 1
 {1, 1, 0, 1, 1, 0, 1},   // 2
 {1, 1, 1, 1, 0, 0, 1},   // 3
 {0, 1, 1, 0, 0, 1, 1},   // 4
 {1, 0, 1, 1, 0, 1, 1},   // 5
 {1, 0, 1, 1, 1, 1, 1},   // 6
 {1, 1, 1, 0, 0, 0, 0},   // 7
 {1, 1, 1, 1, 1, 1, 1},   // 8
 {1, 1, 1, 0, 0, 1, 1}    // 9
};

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);
}

void loop(){
  for(byte i = 0; i < 10; i++)
  {
    delay(1000);
    sevenSegWork(i);
    delay(1000);
  }
}

void sevenSegWork(byte digit){
  byte pin = 2;

  for(byte i = 0; i < 7; i++)
  {
    digitalWrite(pin, sevenSegment[digit][i]);
    pin++; 
  }
}
