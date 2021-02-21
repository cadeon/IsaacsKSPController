int latchpin = 8;
int datapin = 11;
int clockpin = 12;
boolean registers[10];

void setup() {
  pinMode(latchpin,OUTPUT);
  pinMode(datapin,OUTPUT);
  pinMode(clockpin,OUTPUT);
  writereg();
}

void loop() {
  leds_go_up();
  delay(250);
  leds_go_down();
  delay(250);
}

void writereg() {
  digitalWrite(latchpin, LOW);
  for (int i=10; i>=0; i--){
  digitalWrite(clockpin,LOW);
  digitalWrite(datapin,registers[i]);
  digitalWrite(clockpin,HIGH);
  }
  digitalWrite(latchpin,HIGH);
}

void leds_go_down(){
  for(int i=0; i<10; i++){
  registers[(i)]=HIGH;
  writereg();
  delay(15);
  registers[(i)]=LOW;
  writereg();
  delay(15);
  }
}

void leds_go_up(){
  for (int i = 10; i >= 0; i--)
  {
    registers[(i)]=HIGH;
    delay(15);
    writereg();
    registers[(i)]=LOW;
    delay(15);
    writereg();
  }
}
