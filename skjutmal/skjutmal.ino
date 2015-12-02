/* 
  Shooting target program
  
  The program has the following responsibilites:
  * Receive commands from remote control
  * Raise the targets
  * Turn lights on/off
  
*/

#include <Servo.h>

/* SERVO PINS */
int SERVO_PWR = 9;  //Toggle servo power
int SERVO_DATA = 10; //Servo Data Signal (PWM)
Servo myservo;
int servo_pos = 0;  //Position where servo should go

/* LED CONTROL */
int LED_PWR = 11;  //LED power

/* HT12D */
int VT = 0;  //Verified Transmission (trigger on this)
int RAISE_DATA = 4;  //D8 (HT12D)
int LED_DATA = 3;    //D9 (HT12D)

void setup()
{
  pinMode(SERVO_PWR,OUTPUT);
  digitalWrite(SERVO_PWR,LOW);
  
  pinMode(SERVO_DATA,OUTPUT);
  digitalWrite(SERVO_DATA,LOW);

  pinMode(LED_PWR,OUTPUT);
  digitalWrite(LED_PWR,LOW);
  
  pinMode(VT,INPUT);
  pinMode(RAISE_DATA,INPUT);
  pinMode(LED_DATA,INPUT);
  
  myservo.attach(SERVO_DATA);
}

void loop()
{
  
}
