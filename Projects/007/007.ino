#include <Unistep2.h>

Unistep2 stepper(8, 9, 10, 11, 4096, 1000);

void setup(){
  Serial.begin(9600);
  Serial.println(F(" Enter absolute position between 0 and 4096"));
}

void loop(){
  stepper.run();

  while ( Serial.available() > 0 && stepper.stepsToGo() == 0 ) 
  {
    int stepPos = Serial.parseInt();

    if (Serial.read() == '\n') {
      Serial.print("Movement command: ");
      Serial.print(stepper.currentPosition());
      Serial.print(" --> ");
      Serial.println(stepPos);
      stepper.moveTo(stepPos);
    }
  }
}
