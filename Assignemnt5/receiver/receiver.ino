//#define deltaT 1000 //micro seconds
#define input 2
#define maxOut 255.00
#include <math.h>



long deltaT = 10000;
unsigned long currTime = 0.0;

long resolutionMult = 0;


 
void InterruptHandler(){
  if(digitalRead(input) == HIGH) CatchOne();
  else ReleaseOne();
}
void CatchOne(){
  currTime = micros()*1000; //at micro second resolution
  
}

void ReleaseOne(){

    unsigned long t = (micros()*1000 - currTime)/1000; //at microsecond resolution
    unsigned long x = 0;
    if(t > 1000){
      long s = t;
      resolutionMult = map(s,1000,s,0,100);
       x = (t *resolutionMult) / deltaT;
    }
    unsigned long res = ((t-x)*maxOut)/deltaT;

    Serial.print((char)round(res));
   
  
}



void setup() {
  // put your setup code here, to run once:

  pinMode(input,INPUT);
  attachInterrupt(digitalPinToInterrupt(input),InterruptHandler,CHANGE);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
