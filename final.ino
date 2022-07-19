#include<Servo.h>
#include<NewPing.h>


#define trigger_pin A1
#define echo_pin A2

#define max_distance 200

NewPing sonar(trigger_pin , echo_pin , max_distance);
Servo servo;

#define EnA 10
#define In1 9
#define In2 8
#define In3 7
#define In4 6
#define EnB 5
#define servo_pin 11

void setup() {
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);

  servo.attach(servo_pin); 

}

void loop() {

  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  digitalWrite(In3,HIGH);
  digitalWrite(In4,LOW);


  analogWrite(EnA,255);
  analogWrite(EnB,255);

  delay(10000);

  digitalWrite(In1,LOW);
  digitalWrite(In2,HIGH);
  digitalWrite(In3,LOW);
  digitalWrite(In4,HIGH);



  analogWrite(EnA,255);
  analogWrite(EnB,255);

    delay(10000);


    
  

}
