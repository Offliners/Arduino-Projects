const byte LEDs[4] = {8, 9, 10, 11};

void setup() {
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  for(byte i = 0; i < 4; i++)
    pinMode(LEDs[i], OUTPUT);
}

void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);

  for(byte i = 0; i < 4; i++)
    digitalWrite(LEDs[i], LOW);
  
  if(x > 800)
    digitalWrite(LEDs[1], HIGH);
   
  if(x < 200)
    digitalWrite(LEDs[3], HIGH);

  if(y > 1000)
    digitalWrite(LEDs[2], HIGH);

  if(y < 400)
    digitalWrite(LEDs[0], HIGH);

  delay(50);
}
