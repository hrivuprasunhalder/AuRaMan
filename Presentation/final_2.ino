volatile unsigned long counts = 0;                  
unsigned long cpm = 0;                      
unsigned long previousMillis = 0;                        
const int inputPin = 2;                          
unsigned long start = 0;                          

#define LOG_PERIOD 5000 

int mtr_AB_en= 3;
int mtr_AB_in1= 9;
int mtr_AB_in2= 4;

int mtr_CD_en= 5;
int mtr_CD_in1= 7;
int mtr_CD_in2= 8;
int i= 0;
                                        
 
void ISR_impulse() {
  counts++; 
}



void setup() {

  Serial.begin(9600);

  pinMode(13,INPUT);

  pinMode(mtr_AB_en,OUTPUT);
  pinMode(mtr_AB_in1,OUTPUT);
  pinMode(mtr_AB_in2,OUTPUT);

  pinMode(mtr_CD_en,OUTPUT);
  pinMode(mtr_CD_in1,OUTPUT);
  pinMode(mtr_CD_in2,OUTPUT); 

  pinMode(inputPin, INPUT);                                         
  interrupts();                                                   
  attachInterrupt(digitalPinToInterrupt(inputPin), ISR_impulse, FALLING);   

  start = millis();  
}

void loop() {

   unsigned long currentMillis = millis(); 
   
  if (currentMillis - previousMillis >= LOG_PERIOD) {
    
    previousMillis = currentMillis;
    
    cpm = counts;  
    counts = 0;    

   
    Serial.print(cpm); 
    Serial.print(" ");  
  }

  digitalWrite(mtr_AB_in1,LOW);
  digitalWrite(mtr_AB_in2,LOW);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,LOW);
  
  delay(5000);

  digitalWrite(mtr_AB_in1,LOW);
  digitalWrite(mtr_AB_in2,HIGH);
  analogWrite(mtr_AB_en,120);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,HIGH);
  analogWrite(mtr_CD_en,164);

  

  delay(100);
  

  

  int sv= digitalRead(13);

  if(sv==LOW){

     Serial.println();

     i= i+1;

     if(i%2==1){

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,HIGH);
        digitalWrite(mtr_CD_in2,LOW);

        delay(645);

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);
     
        delay(140); 

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,HIGH);
        digitalWrite(mtr_CD_in2,LOW);

        delay(645);
     }
    else if(i%2==0){
        digitalWrite(mtr_AB_in1,HIGH);
        digitalWrite(mtr_AB_in2,LOW);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);

        delay(685);

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);
     
        delay(140); 

        digitalWrite(mtr_AB_in1,HIGH);
        digitalWrite(mtr_AB_in2,LOW);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);

        delay(685);
   

    } 



  } 


}