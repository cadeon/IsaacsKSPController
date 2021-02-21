int latchPin=8;
int dataPin=11;
int clockPin=12;

byte ledBar=0x03;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,ledBar);
delay(1000);
digitalWrite(latchPin,HIGH);
}
