int mtr_AB_en= 3;
int mtr_AB_in1= 2;
int mtr_AB_in2= 4;

int mtr_CD_en= 5;
int mtr_CD_in1= 7;
int mtr_CD_in2= 8;


void setup() {

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
  analogWrite(mtr_AB_en,85);

  digitalWrite(mtr_CD_in1,LOW);
  digitalWrite(mtr_CD_in2,HIGH);
  analogWrite(mtr_CD_en,85);

  

  delay(10);

}
