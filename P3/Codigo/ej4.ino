int sensorState = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);

}

void loop()
{
  sensorState = digitalRead(2);
  if(sensorState == HIGH){
  	digitalWrite(13,HIGH);
  } else{
  	digitalWrite(13,LOW);
  }
  
  delay(10); // Wait for 10 millisecond(s)
 }