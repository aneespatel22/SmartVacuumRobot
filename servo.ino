
//servo motor test code
#include<Servo.h>
Servo s1;

int pos=0;

void setup() {
 s1.attach(9);
}

void loop() {
    
   s1.write(0);
   delay(1000);
   s1.write(90);
   delay(1000);
   s1.write(180);
   delay(1000);
   s1.write(0);
   delay(1000);
  }
