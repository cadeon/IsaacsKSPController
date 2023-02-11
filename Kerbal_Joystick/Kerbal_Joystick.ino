
int brakes = 17;

void setup() {
  // put your setup code here, to run once:
pinMode(brakes, INPUT_PULLUP);
pinMode(A14, INPUT_PULLUP);
pinMode(A15, INPUT_PULLUP);
pinMode(A16, INPUT_PULLUP);
pinMode(A22, INPUT_PULLUP);
pinMode(A21, INPUT_PULLUP);
pinMode(A20, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  {
  Joystick.button(1, digitalRead(brakes));
  delay(50);
  }
  
  {
  Joystick.Z(analogRead(A20));
  Joystick.Y(analogRead(A14));
  Joystick.X(analogRead(A16));
  Joystick.Zrotate(analogRead(A15));
  Joystick.sliderLeft(analogRead(A22));
  Joystick.sliderRight(analogRead(A21));
  delay(50);
  }

}
