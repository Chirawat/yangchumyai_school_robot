#include <popx2.h>  

#define A0_REF 570
#define A1_REF 485
#define A2_REF 560
#define A3_REF 520

void readSensor(){
  glcd(0,0,"A0=%d",analog(0));
  glcd(1,0,"A1=%d",analog(1));
  glcd(2,0,"A2=%d",analog(2));
  glcd(3,0,"A3=%d",analog(3));
}



void trackLine(){
  if(analog(1) < A0_REF && analog(2) < A2_REF){
    fd(25);
  }
  else if(analog(1) < A1_REF){  
    sl(15);
  }
  else if(analog(2) < A2_REF){ 
    sr(15);
  }
  else {
    fd(25);
  }
}

void FF(){
  while(analog(0) > A0_REF || analog(3) > A3_REF){
    trackLine();
  }
  beep();
  ao();
}

void FL(){
  sl(25);
  while(analog(1) > A1_REF) 
    delay(10);
  ao();
}

void FR(){
  sr(25);
  while(analog(2) > A2_REF) 
    delay(10);
  ao();
}

void setup() {
  setTextSize(2);
  glcd(0,0,"Press OK");
  sw_ok_press();
  glcdClear();


  FF();
  FF();
  FF();
  FL();
  FF();
  FL();
  FF();
  FF();
  
  FL();
  FF();
  FF();
  FL();
  FF();
 
  FF();
  FF();
  FF();
  FL();
  FF();
  FL();
  FF();
  FF();
  FF();
  FF();


}

void loop() {
}
