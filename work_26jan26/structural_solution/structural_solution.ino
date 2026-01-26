int mtr_AB_en= 3;
int mtr_AB_in1= 2;
int mtr_AB_in2= 4;

int mtr_CD_en= 5;
int mtr_CD_in1= 7;
int mtr_CD_in2= 8;
int i= 0;


void setup() {

  pinMode(13,INPUT);

  pinMode(mtr_AB_en,OUTPUT);
  pinMode(mtr_AB_in1,OUTPUT);
  pinMode(mtr_AB_in2,OUTPUT);

  pinMode(mtr_CD_en,OUTPUT);
  pinMode(mtr_CD_in1,OUTPUT);
  pinMode(mtr_CD_in2,OUTPUT);  


  
}

void loop() {

  digitalWrite(mtr_AB_in1,LOW);
  digitalWrite(mtr_AB_in2,HIGH);
  analogWrite(mtr_AB_en,120);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,HIGH);
  analogWrite(mtr_CD_en,164);

  

  delay(100);
  

  digitalWrite(mtr_AB_in1,LOW);
  digitalWrite(mtr_AB_in2,LOW);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,LOW);


  int sv= digitalRead(13);

  delay(3000);


  if(sv==LOW){


     i= i+1;

     if(i%2==1){

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,HIGH);
        digitalWrite(mtr_CD_in2,LOW);

        delay(555);

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);
     
        delay(140); 

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,HIGH);
        digitalWrite(mtr_CD_in2,LOW);

        delay(555);
     }
    else if(i%2==0){
        digitalWrite(mtr_AB_in1,HIGH);
        digitalWrite(mtr_AB_in2,LOW);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);

        delay(580);

        digitalWrite(mtr_AB_in1,LOW);
        digitalWrite(mtr_AB_in2,HIGH);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);
     
        delay(140); 

        digitalWrite(mtr_AB_in1,HIGH);
        digitalWrite(mtr_AB_in2,LOW);

        digitalWrite(mtr_CD_in1,LOW);
        digitalWrite(mtr_CD_in2,HIGH);

        delay(580);
   

    } 



  } 


}