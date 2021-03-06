const int analogInPin = A0;
const int analogOutPin = 9;

int sensor = 0;
int output = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensor = analogRead(analogInPin);
  output = map(sensor, 0, 1023, 0, 255);
  analogWrite(analogOutPin, output);

  // Print to the monitor
  Serial.print("Sensor = ");
  Serial.print(sensor);
  Serial.print("\t");
  Serial.print("Output = ");
  Serial.print(output);
  Serial.print("\n");

  delay(100);
}
