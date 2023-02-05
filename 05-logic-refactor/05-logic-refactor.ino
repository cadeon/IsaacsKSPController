#include <Keyboard.h>                                                     

int fullt = 0;                                       
int blip = 1;
int pthrot = 2;
int mthrot = 3;
int cutoff = 4;
int view = 5;
int linrot = 6;
int stage = 7;
int lckstage = 8;
int grab = 9;
int board = 10;
int shipnext = 11;
int shipback = 12;
int qckload = 24;
int rcs = 25;
int qcksave = 26;
int sas = 27;
int mtime = 28;
int ptime = 29;
int stime = 30;
int staging = 31;
int docking = 32;
int mapkey = 23;
int abortkey = 22;
int ui = 21;
int scrnshot = 20;
int lights = 19;
int gear = 18;
int brakes = 17;
int rate = 16;

int lightspos = 2;
int gearpos = 2;
int brakespos = 2;

bool ptstate = false;
bool mtstate = false;
bool blipping = false; //Are we currently in a blip?

void setup() 
{
pinMode(fullt, INPUT_PULLUP);                        
pinMode(blip, INPUT_PULLUP);                        
pinMode(pthrot, INPUT_PULLUP);
pinMode(mthrot, INPUT_PULLUP);
pinMode(cutoff, INPUT_PULLUP);
pinMode(view, INPUT_PULLUP);
pinMode(linrot, INPUT_PULLUP);
pinMode(stage, INPUT_PULLUP);
pinMode(lckstage, INPUT_PULLUP);
pinMode(grab, INPUT_PULLUP);
pinMode(board, INPUT_PULLUP);
pinMode(shipnext, INPUT_PULLUP);
pinMode(shipback, INPUT_PULLUP);
pinMode(qckload, INPUT_PULLUP);
pinMode(rcs, INPUT_PULLUP);
pinMode(qcksave, INPUT_PULLUP);
pinMode(sas, INPUT_PULLUP);
pinMode(mtime, INPUT_PULLUP);
pinMode(ptime, INPUT_PULLUP);
pinMode(stime, INPUT_PULLUP);
pinMode(staging, INPUT_PULLUP);
pinMode(docking, INPUT_PULLUP);
pinMode(mapkey, INPUT_PULLUP);
pinMode(abortkey, INPUT_PULLUP);
pinMode(ui, INPUT_PULLUP);
pinMode(scrnshot, INPUT_PULLUP);
pinMode(lights, INPUT_PULLUP);
pinMode(gear, INPUT_PULLUP);
pinMode(brakes, INPUT_PULLUP);
pinMode(rate, INPUT_PULLUP);
pinMode(A14, INPUT_PULLUP);
pinMode(A15, INPUT_PULLUP);
pinMode(A16, INPUT_PULLUP);
pinMode(A22, INPUT_PULLUP);
pinMode(A21, INPUT_PULLUP);
pinMode(A20, INPUT_PULLUP);

Keyboard.begin();

}

void loop()
{
    // Check if we've let go of the blip
    if blipping && (digitalRead(blip) == HIGH){
      // We're no longer blipping, send x
      Keyboard.write('x');
      // And set blipping to false
      blipping=false;
    }

  {Joystick.button(1, digitalRead(brakes));
  delay(50);}
  
  Joystick.Z(analogRead(A20));
  Joystick.Y(analogRead(A15));
  Joystick.X(analogRead(A16));
  Joystick.Zrotate(analogRead(A14));
  Joystick.sliderLeft(analogRead(A22));
  Joystick.sliderRight(analogRead(A21));
  
  
  if (digitalRead(fullt) == LOW)                       
  {Keyboard.write('z');                              
    delay(250);}

  if (digitalRead(blip) == LOW) && blipping == false                     
  { Keyboard.write('z');
    blipping=true;}

  int mtreading = digitalRead(mthrot);

  if (mtreading == LOW && ! mtstate)
  {Keyboard.press(KEY_LEFT_CTRL);
   mtstate = true;}

  if (mtreading == HIGH && mtstate)
  {Keyboard.release(KEY_LEFT_CTRL);
   mtstate = false;}

  int ptreading = digitalRead(pthrot);

  if (ptreading == LOW && ! ptstate)
  {Keyboard.press(KEY_LEFT_SHIFT);
   ptstate = true;}

  if (ptreading == HIGH && ptstate)
  {Keyboard.release(KEY_LEFT_SHIFT);
   ptstate = false;}

  if (digitalRead(cutoff) == LOW)                     
  {Keyboard.write('x');
   delay(250);}

  if (digitalRead(view) == LOW)                       
  {Keyboard.write('v');                              
   delay(250);}

  if (digitalRead(linrot) == LOW)                     
  {Keyboard.write('h');                              
   delay(250);}

  if (digitalRead(stage) == LOW)                     
  {Keyboard.press(KEY_SPACE);   
   delay(50);
   Keyboard.release(KEY_SPACE);
   delay(1000);}

  if (digitalRead(lckstage) == LOW)                     
  {Keyboard.set_modifier(MODIFIERKEY_ALT);                 
   Keyboard.send_now();
   Keyboard.write('l');
   delay(50);
   Keyboard.set_modifier(0);
   Keyboard.send_now();
   delay(250);}

  if (digitalRead(board) == LOW)                       
  {Keyboard.write('f');                              
   delay(50);}

  if (digitalRead(grab) == LOW)                      
  {Keyboard.write('b');                              
   delay(250);}

  if (digitalRead(shipnext) == LOW)                     
  {Keyboard.write(']');                               
   delay(250);}

  if (digitalRead(shipback) == LOW)                     
  {Keyboard.write('[');                            
   delay(250);}

  if (digitalRead(qckload) == LOW)                     
  {Keyboard.set_modifier(MODIFIERKEY_ALT);                 
   Keyboard.send_now();
   Keyboard.press(KEY_F9);
   delay(50);
   Keyboard.release(KEY_F9);
   Keyboard.set_modifier(0);
   Keyboard.send_now();
   delay(250);}
   
  if (digitalRead(qcksave) == LOW)                     
  {Keyboard.press(KEY_F5);
   delay(100);
   Keyboard.release(KEY_F5);
   delay(250);}

  if (digitalRead(mtime) == LOW)                       
  {Keyboard.write(',');                              
   delay(250);}

  if (digitalRead(ptime) == LOW)                       
  {Keyboard.write('.');                              
   delay(250);}

  if (digitalRead(stime) == LOW)                       
  {Keyboard.write('/');                              
   delay(250);}

  if (digitalRead(rcs) == LOW)                       
  {Keyboard.write('r');                              
   delay(250);}

  if (digitalRead(sas) == LOW)                       
  {Keyboard.write('t');                              
   delay(250);}

  if (digitalRead(staging) == LOW)                     
  {Keyboard.press(KEY_INSERT);                          
   delay(100);
   Keyboard.release(KEY_INSERT);
   delay(250);}

  if (digitalRead(docking) == LOW)                     
  {Keyboard.press(KEY_DELETE);                          
   delay(100);
   Keyboard.release(KEY_DELETE);
   delay(250);}

  if (digitalRead(mapkey) == LOW)                       
  {Keyboard.write('m');                              
   delay(250);}

  if (digitalRead(abortkey) == LOW)                     
  {Keyboard.press(KEY_BACKSPACE);                          
   delay(100);
   Keyboard.release(KEY_BACKSPACE);
   delay(250);}

  if (digitalRead(ui) == LOW)                     
  {Keyboard.press(KEY_F2);
   delay(100);
   Keyboard.release(KEY_F2);
   delay(250);}

  if (digitalRead(scrnshot) == LOW)                     
  {Keyboard.press(KEY_F1);
   delay(100);
   Keyboard.release(KEY_F1);
   delay(250);}

  if (digitalRead(rate) == LOW)                     
  {Keyboard.press( KEY_CAPS_LOCK);
   delay(100);
   Keyboard.release( KEY_CAPS_LOCK);
   delay(250);}
   
  if (digitalRead(lights) == LOW)                     
  {Keyboard.write('u');                               
   delay(250);}
  
  if (digitalRead(gear) == LOW)                    
  {Keyboard.write('g');                              
   delay(250);}
    
//if (digitalRead(brakes) == LOW)                     
//{Keyboard.press('b');}
//else
//{Keyboard.release('b');}
  
}
