void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  if(digitalRead(7)==LOW){
  	 digitalWrite(13, HIGH);
  }
  else{
  	digitalWrite(13, LOW);
  }
 
 
  
 
}