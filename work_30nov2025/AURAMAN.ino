#include<Servo.h>
Servo serv;

int servpin= 6;

int trig= 12;
int echo= 13;
long duration,distance;

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

  

  delay(500);
  

  digitalWrite(mtr_AB_in1,LOW);
  digitalWrite(mtr_AB_in2,LOW);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,LOW);

  serv.write(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration= pulseIn(echo, HIGH);
  distance= (duration*.0343)/2;
  
  Serial.print("Distance(front): ");
  Serial.print(distance);
  Serial.println( "cm");

  delay(1000);


  serv.write(112);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration= pulseIn(echo, HIGH);
  distance= (duration*.0343)/2;
  
  Serial.print("Distance(right): ");
  Serial.print(distance);
  Serial.println( "cm");

  delay(1000);


}
