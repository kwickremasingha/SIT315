#include <Servo.h>

int pos = 0 ;    // current position of servo
int direction = 0 ;  // direction state, +1, 0 or -1

Servo servo_3;

int mo1= 2;
int mo2= 4; 


void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(mo1, INPUT);
  pinMode(mo2, INPUT);
  
  PCICR |= 0b00000111;
  PCMSK2 |= 0b10011100;
  
  servo_3.attach(3);
  
 	
  
  
}

void loop()
{
  
  

  if (digitalRead (2))  // trigger from motion
    direction = 1 ;
  
  
  if (direction == 1)   // moving forward
  {
    
    if (pos < 360)
    {

  		
      pos ++ ;
      servo_3.write (pos) ;
      delay (10) ;   
    }
    else 
      direction = -1 ;   // change direction
  }
  else if (direction == -1)
  {
    if (pos > 0)
    {
      pos -- ;
      servo_3.write (pos) ;
      delay (10) ;
    }
    else
      direction = 0 ; // stopped
  }  
  
  
  
  
  if (digitalRead (4))  // trigger from motion
    direction = 1 ;

  if (direction == 1)   // moving forward
  {
    if (pos < 120)
    {
    
     
      pos ++ ;
      servo_3.write (pos) ;
      delay (10) ;   
    }
    else 
      direction = -1 ;   // change direction
  }
  else if (direction == -1)
  {
    if (pos > 0)
    {
      pos -- ;
      servo_3.write (pos) ;
      delay (10) ;
    }
    else
      direction = 0 ; // stopped
  } 
  
  
  
   Serial.print("Motion Detected = ");
   Serial.println(mo1);
  
   Serial.print("Motion Detected = ");
   Serial.println(mo2);
  

}

ISR(PCINT2_vect)
{
  mo1 = PIND & B00000100;
  mo2 = PIND & B00010000;
}