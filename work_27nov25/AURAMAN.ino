int mtr_A_en= 3;
int mtr_A_in1= 2;
int mtr_A_in2= 4;

int mtr_B_en= 5;
int mtr_B_in1= 7;
int mtr_B_in2= 8;

int mtr_C_en= 6;
int mtr_C_in1= 9;
int mtr_C_in2= 10;

int mtr_D_en= 11;
int mtr_D_in1= 12;
int mtr_D_in2= 13;

void setup() {

  pinMode(mtr_A_en,OUTPUT);
  pinMode(mtr_A_in1,OUTPUT);
  pinMode(mtr_A_in2,OUTPUT);

  pinMode(mtr_B_en,OUTPUT);
  pinMode(mtr_B_in1,OUTPUT);
  pinMode(mtr_B_in2,OUTPUT);  

  pinMode(mtr_C_en,OUTPUT);
  pinMode(mtr_C_in1,OUTPUT);
  pinMode(mtr_C_in2,OUTPUT);  

  pinMode(mtr_D_en,OUTPUT);
  pinMode(mtr_D_in1,OUTPUT);
  pinMode(mtr_D_in2,OUTPUT);  
  
}

void loop() {

  digitalWrite(mtr_A_in1,LOW);
  digitalWrite(mtr_A_in2,HIGH);
  analogWrite(mtr_A_en,90);

  digitalWrite(mtr_B_in1,LOW);
  digitalWrite(mtr_B_in2,HIGH);
  analogWrite(mtr_B_en,90);

  digitalWrite(mtr_C_in1,HIGH);
  digitalWrite(mtr_C_in2,LOW);
  analogWrite(mtr_C_en,90);

  digitalWrite(mtr_D_in1,HIGH);
  digitalWrite(mtr_D_in2,LOW);
  analogWrite(mtr_D_en,90);

  delay(10);

}
