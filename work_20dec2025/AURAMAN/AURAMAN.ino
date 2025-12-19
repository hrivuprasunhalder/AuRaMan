#include<Servo.h>
Servo serv;

int servpin= 6;

int trig= 12;
int echo= 13;
long durationf,distancef,durationr,distancer,refdistancer=30,error;
long tol= 3; //cm

int mtr_AB_en= 3;
int mtr_AB_in1= 2;
int mtr_AB_in2= 4;

int mtr_CD_en= 5;
int mtr_CD_in1= 7;
int mtr_CD_in2= 8;


void setup() {

  Serial.begin(9600);

  serv.attach(servpin);

  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);

  pinMode(mtr_AB_en,OUTPUT);
  pinMode(mtr_AB_in1,OUTPUT);
  pinMode(mtr_AB_in2,OUTPUT);

  pinMode(mtr_CD_en,OUTPUT);
  pinMode(mtr_CD_in1,OUTPUT);
  pinMode(mtr_CD_in2,OUTPUT);  
  
}

void loop() {

  digitalWrite(mtr_AB_in1,HIGH);
  digitalWrite(mtr_AB_in2,LOW);
  analogWrite(mtr_AB_en,120);

  digitalWrite(mtr_CD_in1,HIGH);
  digitalWrite(mtr_CD_in2,LOW);
  analogWrite(mtr_CD_en,120);

  

  delay(200);
  

  digitalWrite(mtr_AB_in1,LOW);
  digitalWrite(mtr_AB_in2,LOW);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,LOW);


  serv.write(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  durationf= pulseIn(echo, HIGH);
  distancef= (durationf*.0343)/2;

  delay(1000);

  serv.write(112);
  for (int i=1;i<=10;i++){
      digitalWrite(trig,LOW);
      delayMicroseconds(2);
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      durationr= pulseIn(echo, HIGH);
      distancer= (durationr*.0343)/2;
      error= (distancer- refdistancer);
      if (abs(error)<=tol){
        break;
      }
      else if(error<0){
        digitalWrite(mtr_AB_in1,HIGH);
        digitalWrite(mtr_AB_in2,LOW);
        analogWrite(mtr_AB_en,80);

        digitalWrite(mtr_CD_in1,LOW); //left
        digitalWrite(mtr_CD_in2,LOW);
      
        delay(10);
        continue;

      }
      else if(error>0){
        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,LOW);
        
        digitalWrite(mtr_CD_in1,HIGH);//right
        digitalWrite(mtr_CD_in2,LOW);
        analogWrite(mtr_CD_en,80);

        delay(10);
        continue;

      }

  }
  delay(1000);
  
  
  


}