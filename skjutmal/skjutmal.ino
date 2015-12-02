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

/* LED CONTROL */
int LED_PWR = 11;  //LED power
int led_status = 0;

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
  if(digitalRead(VT) == HIGH)
  {
    if(digitalRead(RAISE_DATA) == HIGH)
      raise_targets();
    if(digitalRead(LED_DATA) == HIGH)
      toggle_leds();
    delay(2000);  //Wait for VT to go low  
  }
}

void raise_targets()
{
  digitalWrite(SERVO_PWR,HIGH);
  delay(100);
  myservo.write(150);
  delay(800);
  myservo.write(70);
  digitalWrite(SERVO_PWR,LOW);
}

void toggle_leds()
{
  if(led_status == 0)
  {
    led_status = 1;
    digitalWrite(LED_PWR, led_status);
  }
  else if(led_status == 1)
  {
    led_status = 0;
    digitalWrite(LED_PWR, led_status);
  }
}
