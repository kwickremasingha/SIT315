const int ledpin=13;
const int soundinputpin=A2;
const int threshold=200; // Active threshold for sound sensor to capture


void setup()
{
  
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(soundinputpin,INPUT);

}
void loop() {
  
  int soundsens=analogRead(soundinputpin); // read AO data from sensor
  
  if (soundsens>=threshold) {
    digitalWrite(ledpin, HIGH); // turn led on
    Serial.print("LED ON = ");
    Serial.println(soundsens);
    delay(2000);
  }
  else{
    digitalWrite(ledpin, LOW);

    
  }
}
