const byte dataPin = 2;
const byte latchPin = 3;
const byte clockPin = 4;
byte index = 0;
byte updown = 0;

const byte LEDs[8] = {
  B10000000,
  B11000000,
  B11100000,
  B11110000,
  B11111000,
  B11111100,
  B11111110,
  B11111111,
};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs[index]);
  digitalWrite(latchPin, HIGH);
  delay(500);

  if(index == 7)
    updown = 1;
  else if(index == 0)
    updown = 0;

  if(updown == 1)
    index--;
  else
    index++;
}
