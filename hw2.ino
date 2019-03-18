#include"SevSeg.h"
SevSeg sevseg;
byte Min=1;
byte Hour=0;
void setup() {
  pinMode(6,INPUT);
  byte numDigits=4;
  byte digitPins[]={2,3,4,5};
  byte segmentPins[]={8,9,10,11,12,13,14,15};
  sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
 sevseg.setBrightness(90);

}

void loop() {  
 if(digitalRead(6)==HIGH)
    Hour=Min=0;
  sevseg.setNumber(Hour * 100 + Min, 4);
  Min++;
  if(Min==60)
  {
      Min=0;
      if(Hour==23)
          Hour=0;
       else
          Hour++;
  }
delay(300);


}
