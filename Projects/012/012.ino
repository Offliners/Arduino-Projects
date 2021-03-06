#include <Servo.h>
  
Servo servo1;
Servo servo2;

const byte ctrlX = A0;
const byte ctrlY = A1;
int servoValue, x, y;
  
void setup() {
  servo1.attach(2);
  servo2.attach(3);
}
  
void loop() {
  x = analogRead(ctrlX);
  servoValue = map(x, 0, 1023, 0, 180);
  servo1.write(servoValue);

  y = analogRead(ctrlY);
  servoValue = map(y, 0, 1023, 0, 180);
  servo2.write(servoValue);
  
  delay(50);  
}
