const int motor=2;
const float stepcount=14;
const float wheeldia=20 ;
volatile int counter_0=0;
int in1=5;
int in2=6;
int count_1=2;
int count_2=1;
void ISR_COUNT0(){
  counter_0++ ;
}
int cmtosteps(float cm){
  int result;
  float circum=(wheeldia*3.14)/10;
  float cm_step=circum/stepcount;
  float f_result=cm / cm_step;
  result= (int) f_result;
  return result;
 
}
void moveforward(int steps){
  counter_0=0;
  while(counter_0 <= steps){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  digitalWrite(in1, LOW);
  delay(2000);
}

void movebackward(int steps){
  counter_0=0;
  while(counter_0 <= steps){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  digitalWrite(in2, LOW);
  delay(2000);
}
 void setup(){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(9, 80);
  digitalWrite(10, LOW);
  attachInterrupt(1, ISR_COUNT0, RISING);
  delay(2000);
  while(count_1 <= 10){
  moveforward(cmtosteps(18.00));
  count_1++;
  }
  while(count_2 <= 10){
  movebackward(cmtosteps(18.00));
  count_2++;
  }
   
  
}
void loop(){
 
}
  
  







  


