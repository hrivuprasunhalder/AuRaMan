void setup() {

  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  
  
}

void loop() {

  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  analogWrite(3,180);

  delay(10);

}
