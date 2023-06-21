#define OUT1 8
#define OUT2 9
#define Interrupt 2
#define InterruptOut 3
#define controlTime 10 //ms



struct Task{
  int id;
  unsigned long lastProceed;
  int delayTime;
  int outputPin;
  int stts;
  void (*homework)(struct Task*);
  int counter;
  
};

struct Messanger{
  
};


enum State{
  Idle,
  Processing,
  Blocked
};

struct TaskControlBlock{
  int currentTaskId;
  enum State state;
  
  
};

struct TaskControlBlock* TCB;
struct Task* Task1;
struct Task* Task2;


void Homework(struct Task* task){
  if(millis() - task->lastProceed >= task->delayTime - controlTime){
    task->stts = !task->stts;
    TCB->state = Processing;
    /*while(task->counter < 50){
      Serial.println(task->counter);
      delay(10);//
      task->counter += 1;
    }*/
    Serial.println(task->counter);
    digitalWrite(task->outputPin,task->stts);
    task->counter += 1;
    if(task->counter >= 50){
      task->counter = 0;
    }
    task->lastProceed = millis();
    //Serial.println(task->id);
    //Serial.println(" has finished returning to Idle state");
    TCB->state = Idle;
    digitalWrite(InterruptOut,HIGH);
  }
  else{
    //Serial.print(task->id);
    //Serial.println(" has to wait");
    TCB->state = Idle;
    digitalWrite(InterruptOut,HIGH);
  }
  
}


void changeTask(){
  
  digitalWrite(InterruptOut,LOW);
  if(TCB->state == Processing){
    
    Serial.println("An Interrupt Occured when processing returning to Idle state");
    TCB->state = Idle;
  }
   switch(TCB->currentTaskId){
     case 0:
       TCB->currentTaskId = 1;
       break;
     case 1:
       TCB->currentTaskId = 0;
       break;
    }
  
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(OUT1,OUTPUT);
  pinMode(OUT2,OUTPUT);
  pinMode(Interrupt,INPUT);
  pinMode(InterruptOut,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Interrupt),changeTask,RISING);
  TCB = (struct TaskControlBlock*)malloc(sizeof(struct TaskControlBlock));
  TCB->currentTaskId = 0;
  TCB->state = Idle;

  //Task1

  Task1 = (struct Task*)malloc(sizeof(struct Task));
  Task1->id = 0;
  Task1->delayTime = 1000;
  Task1->lastProceed = -Task1->delayTime;
  Task1->outputPin = OUT1;
  Task1->stts = 0; // LED is off
  Task1->homework = &Homework;
  Task1->counter =0;
  //Task2

  Task2 = (struct Task*)malloc(sizeof(struct Task));
  Task2->id = 1;
  Task2->delayTime = 2000;
  Task2->lastProceed = -Task2->delayTime;
  Task2->outputPin = OUT2;
  Task2->stts = 0;
  Task2->homework = &Homework;
  Task2->counter = 0;

  
  
  Serial.begin(9600);
  Serial.println("basla");
  Task1->homework(Task1);

}

void loop() {
  // put your main code here, to run repeatedly:

  
  if(TCB->state == Idle){
    switch(TCB->currentTaskId){
      case 0:
        Task1->homework(Task1);
        break;

      case 1:
        Task2->homework(Task2);
        break;
    }
  }

}
