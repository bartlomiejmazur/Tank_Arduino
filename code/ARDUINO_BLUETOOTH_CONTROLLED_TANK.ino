//Arduino Bluetooth Controlled Tank



#include<AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor4(4); 

char command; 
void setup() {
 
Serial.begin(9600);
}

void loop() {
  
if(Serial.available()>0)
{
  command = Serial.read();
  delay(2);

  switch(command)
  {
    case 'F':
    forward();
    break;
    case'B':
    backward();
    break;
    case 'L':
    left();
    break;
    case'R':
    right();
    break;
    case'G':
    forwardleft();
    break;
    case'I':
    forwardright();
    break;
    case'H':
    backwardleft();
    break;
    case'J':
    backwardright();
    break;
    
  }
 }
}

void forward()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void backward()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void forwardleft()
{
  motor1.setSpeed(250);
  motor1.run(FORWARD);
  motor4.setSpeed(10);
  motor4.run(FORWARD);
}

void forwardright()
{
  motor1.setSpeed(10);
  motor1.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void backwardleft()
{
  motor1.setSpeed(10);
  motor1.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void backwardright()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor4.setSpeed(10);
  motor4.run(BACKWARD);
}

void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE);
}
