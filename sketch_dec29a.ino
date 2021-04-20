#define BlueLedPin 10
#define RedLedPin 9
#define GreenLedPin 6

#define BtnRed 4
#define BtnBlue 2
#define BtnGreen 3

#define LED_NUM 3
int leds[LED_NUM]= {BlueLedPin,RedLedPin,GreenLedPin};
int Btns[LED_NUM]= {BtnBlue,BtnRed,BtnGreen};

int CounterR;
int CounterB;
int CounterG;
int Counts[LED_NUM]= {CounterB,CounterR,CounterG};
void setup() {
 for(int k = 0 ; k < LED_NUM ; k++){ 
    pinMode(leds[k], OUTPUT);
    pinMode(Btns[k], INPUT_PULLUP);
    digitalWrite(leds[k], LOW);
  }
  Counts[LED_NUM]=0;
}

void loop() {
   for(int k=0 ; k< LED_NUM ; k++){
      if(digitalRead(Btns[k])==LOW){
       Counts[k]++;
       while(digitalRead(Btns[k])==LOW); 
      }
   }
   for(int k=0 ; k< LED_NUM ; k++){
    if(Counts[k] % 2 == 1){
      digitalWrite(leds[k],HIGH);
    } else {
      digitalWrite(leds[k],LOW);
    }
   } 
}
