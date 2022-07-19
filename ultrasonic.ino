#include<NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10

#define MAX_DISTANCE 400

NewPing sen(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
float duration,distance;

void setup() {
  Serial.begin(9600);

  
}

void loop() {
  distance = sen.ping_cm();

  Serial.print("Distance =");

  if(distance >=400 || distance <=2){
      Serial.println("out of range");
  }else{
      Serial.println(distance);
      Serial.println("cm");
    }
    delay(500);
}
