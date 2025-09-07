
void setup() {
  Serial.begin(9600);  
  randomSeed(analogRead(A0));
}

void loop() {
  int count = random(18, 22); 
  for (int i = 0; i < count; i++) {
    int value = random(0, 80);
    Serial.print(value);
    if (i < count - 1) Serial.print(" "); 
  }
  Serial.println(); 
  delay(1000);        
}
