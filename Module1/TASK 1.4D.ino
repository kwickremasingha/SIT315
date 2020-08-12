

const int buzzer = 7; 
int ledPin= 13;
unsigned long time;

int mo1= 2;
int mo2= 4; 


void setup()
{
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT); 

  pinMode(mo1, INPUT);
  pinMode(mo2, INPUT);
  
  //PCICR |= 0b00000111;
  //PCMSK2 |= 0b10011100;
  

    // initialize timer1 

  noInterrupts();           // disable all interrupts

  TCCR1A = 0;

  TCCR1B = 0;

  TCNT1  = 0;
  
  
  OCR1A = 31250;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS12);    // 256 prescaler 

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt

  interrupts();             // enable all interrupts
 	
  
  
}


ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine

{

  digitalWrite(buzzer, digitalRead(buzzer) ^ 10);   // toggle LED pin
  Serial.print("Timer Interrupt = ");
  Serial.println(buzzer);
  
}
void loop()
{
  
  if(digitalRead(2)){
  
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
   Serial.print("Motion Detected = ");
   Serial.println(mo1);
    
  }
  
  
  if(digitalRead(4)){
   
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
   Serial.print("Motion Detected = ");
   Serial.println(mo2);
    
  }
  

}

ISR(PCINT2_vect)
{
  mo1 = PIND & B00000100;
  mo2 = PIND & B00010000;
}