
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); 

void setup() {
  BTSerial.begin(9600);  
  randomSeed(analogRead(A0));
}

void loop() {
  int count = random(18, 22); 
  for (int i = 0; i < count; i++) {
    int value = random(0, 80);
    BTSerial.print(value);
    if (i < count - 1) BTSerial.print(" ");
  }
  BTSerial.println(); 
  delay(1000);        
}
