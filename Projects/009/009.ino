#include <Stepper.h>

#define STEPS 32
#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8
#define joystick  A0

Stepper stepper(STEPS, IN4, IN2, IN3, IN1);

void setup(){
  
}
 
void loop(){
  int x = analogRead(joystick);

  if(x > 500 && x < 523)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else
  {
    while(x >= 523)
    {
      int speed_ = map(x, 523, 1023, 5, 500);
      stepper.setSpeed(speed_);
      stepper.step(1);
      x = analogRead(joystick);
    }
 
    while (x <= 500)
    {
      int speed_ = map(x, 500, 0, 5, 500);
      stepper.setSpeed(speed_);
      stepper.step(-1);
      x = analogRead(joystick);
    }
  }

  delay(100);
}
