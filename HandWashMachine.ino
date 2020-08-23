#define PUMP 3
#define VAN_12V 5
#define IR  A3
#define VAN_5V A2
#define LED_VAN A1
#define LED_PUMP A0
void ledBlink()
{
  digitalWrite(LED_PUMP,1);
  digitalWrite(13,1); 
  delay(25);
  digitalWrite(LED_PUMP,0);
  digitalWrite(13,0);  
  delay(25);
}
void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,1);
  pinMode(PUMP,OUTPUT);
  digitalWrite(PUMP,0);
  pinMode(VAN_12V,OUTPUT);
  pinMode(VAN_5V,OUTPUT);
  pinMode(LED_VAN,OUTPUT);
  pinMode(LED_PUMP,OUTPUT);
  pinMode(IR,INPUT_PULLUP);
  
}
//unsigned long timeStart,timeDelay,timeStop;
bool stateIR,laststateIR;
void loop() {
//  while(1)
//  {
//    digitalWrite(PUMP,0);
//      digitalWrite(VAN_5V,0);
//  }

 while(digitalRead(IR)==0){
  delay(2000);
  if(digitalRead(IR)==0){
    for(int i=0;i<10;i++)
      {
        digitalWrite(PUMP,1);
        ledBlink();       
      }
      digitalWrite(PUMP,0);
  }
  else {
    digitalWrite(PUMP,0);
    break;
  }
 }
 while (1){
  if(digitalRead(IR)==0)
  {
    laststateIR=stateIR;
    stateIR=1;
    digitalWrite(LED_PUMP,1);
    delay(200);
    if(digitalRead(IR)==0)
    {
      for(int i=0;i<2;i++)
      {
        digitalWrite(PUMP,1);
        ledBlink();       
      }
      digitalWrite(PUMP,0);
      while(digitalRead(IR)==0&&laststateIR==0)
      {
        digitalWrite(LED_PUMP,0);
//        ledBlink();
      }
//      delay(50);
      laststateIR=stateIR;
    }
    
  }
  else
  {
    stateIR=0;
    digitalWrite(PUMP,0);
    digitalWrite(LED_PUMP,0);
    digitalWrite(13,1);
  }

  }
}
