#include <Servo.h>
#include <NewPing.h>

//Motor driver -L298N
#define ENA 11 //pwm
#define IN1 10
#define IN2 9
#define IN3 8
#define IN4 7
#define ENB 6 //pwm

// Ultrasonic sensor
#define Trig_pin 13
#define Echo_pin 12

boolean goesForward = false;

//servo sg90
#define Servo_pin 3

#define max_distance 200
int distance =100;

NewPing sonar(Trig_pin,Echo_pin,max_distance);
Servo servo;

void setup(){
      pinMode(ENA,OUTPUT);
      pinMode(IN1,OUTPUT);
      pinMode(IN2,OUTPUT);
      pinMode(IN3,OUTPUT);
      pinMode(IN4,OUTPUT);
      pinMode(ENB,OUTPUT);  

      servo.attach(Servo_pin);

      servo.write(96);
      delay(2000);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);  

      
}

void loop(){

      int distanceRight = 0;
      int distanceLeft = 0;
      delay(50);

      if(distance<=20){
        moveStop();
        delay(300);
        moveBackward();
        delay(400);
        moveStop();
        delay(300);
        distanceRight = lookRight();
        turnRight();
        delay(300);
        distanceLeft = lookLeft();
        turnLeft();
        delay(300);

        if(distance>=distanceLeft){
          turnRight();
          moveStop();  
        }
        else{
          turnLeft();
          moveStop();
        }
      }
      else{
        moveForward();  
      }
      distance =readPing();
      


  
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0){
    cm=250;  
  }
  return cm;
}

//0 //right
//180//left

int lookRight(){
  servo.write(0);
  delay(500);
  int distance =readPing();
  servo.write(96);
  return distance;
  delay(100);    
}

int lookLeft(){
  servo.write(180);
  delay(500);
  int distance =readPing();
  delay(100);
  servo.write(96);
  return distance;
  delay(100);
  
}


void moveForward(){
  if(!goesForward){

    goesForward=true;

    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW); 

    analogWrite(ENA,50);
    analogWrite(ENB,75);
    }
}

void moveBackward(){
    goesForward =false;
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);

    delay(500);

    analogWrite(ENA,50);
    analogWrite(ENB,75);
 }

 void moveStop(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);

    analogWrite(ENA,50);
    analogWrite(ENB,75);
  }

void turnLeft(){
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 

  analogWrite(ENA,50);
  analogWrite(ENB,125);
  
  delay(500);
  
  
 }

 void turnRight(){
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  analogWrite(ENB,75);
  analogWrite(ENA,125);
  
  
  delay(500);
}
