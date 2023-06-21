

#define SECOND 1000 //ms
#define INP 2

int hour = 10;
int mim = 00;
int sec = 00;
unsigned long current;



void setup() {
  // put your setup code here, to run once:
  pinMode(INP, INPUT);
  attachInterrupt(digitalPinToInterrupt(INP), printTime, RISING);
  Serial.begin(9600);
  current = millis();

}



void printTime() {
  Serial.print(hour);
  Serial.print(":");
  if (mim < 10) {
    Serial.print("0");
    Serial.print(mim);
    Serial.print(":");

  }
  else {
    Serial.print(mim);
    Serial.print(":");
  }
  if (sec < 10) {
    Serial.print("0");
    Serial.println(sec);

  }
  else {
    Serial.println(sec);

  }
}
void loop() {
  // put your main code here, to run repeatedly:


  
  if (millis() - current >= SECOND) {
    current = millis();
    sec ++;
    if (sec == 60) {
      mim++;
      sec = 0;
    }
    if (mim == 60) {
      hour ++;
      mim = 0;
    }
  }

  if(Serial.available()){
    String inputStr = Serial.readString();
    char buf[9];
    inputStr.toCharArray(buf,9);
    char *p = buf;
    char *str;
    int hr = 0;
    int m = 0;
 

    while((str = strtok_r(p,":",&p)) != NULL){
      
      if(hr == 0){
       
        hour = atoi(str);
        hr = 1;
      }
      else if(m == 0){
        
        mim = atoi(str);
        m = 1;
      }
      else{
        
        sec = atoi(str);
      }
    }
  }



}
