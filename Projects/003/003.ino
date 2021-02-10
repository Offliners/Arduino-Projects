const byte LEDs[] = {2, 3, 4, 5, 6 ,7, 8, 9, 10, 11, 12, 13};
const byte Size = sizeof(LEDs);
byte index = 0;

void setup() {
  for(byte i = 0; i < Size; i++)
    pinMode(LEDs[i], OUTPUT);
}

void loop() {
  for(byte i = 0; i < Size; i++)
    digitalWrite(LEDs[i], LOW);

  digitalWrite(LEDs[index], HIGH);
  index++;

  if(index == Size)
    index = 0;

  delay(100);
}
