const int ledpin=13;
const int soundinputpin=2;
const int threshold=600; // Active threshold for sound sensor to capture
int pirPin = 3;                 // PIR input pin 
int pirStat = 0;                   // PIR status

void setup()
{
  
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(pirPin, INPUT); 
pinMode(soundinputpin,INPUT);

  attachInterrupt(digitalPinToInterrupt(soundinputpin), button_ISR, CHANGE); //Digital pin 2
  attachInterrupt(digitalPinToInterrupt(pirPin), button_ISR, CHANGE); //digital pin 3
}
void loop() {
  
  int soundsens=analogRead(soundinputpin); // read data from sensor
  
  if (soundsens>=threshold) {
    
    digitalWrite(ledpin, HIGH); // turn led on
    Serial.print("LED ON = ");
    Serial.println(soundsens);
    delay(2000);
    
  }
  else{
    
    digitalWrite(ledpin, LOW);
 
  }

    pirStat = digitalRead(pirPin); 
     if (pirStat == HIGH) {            // if motion detected
       digitalWrite(ledpin, HIGH);  // turn LED ON
       Serial.println("Motion Detected!"); 
     } 
     else {
       digitalWrite(ledpin, LOW); // turn LED OFF if there is no motion
     }
}
  void button_ISR()
{
  
  int ledToggle = !ledToggle;
  digitalWrite(ledpin, ledToggle);
}
