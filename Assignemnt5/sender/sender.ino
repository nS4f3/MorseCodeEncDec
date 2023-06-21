#define deltaT 10000 //micro seconds
#define output 8
#define maxOut 255.00




const char *message = "Hello world how the things going on for me it is perfect lets say :D!\n";

bool sended = false;
void setup() {
  // put your setup code here, to run once:

  
  pinMode(output,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(!sended){
    for(int b_index = 0; b_index < strlen(message);b_index++){
    double msg = (double) message[b_index];
    int mc_delay = (int)(((double)msg/maxOut)*deltaT);
    Serial.println(mc_delay);
    digitalWrite(output,HIGH);
    delayMicroseconds(mc_delay);
    digitalWrite(output,LOW);
    delayMicroseconds(deltaT - mc_delay); // to complete the clock cycle
  }
  sended = true;
  }

}
