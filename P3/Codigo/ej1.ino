void setup()
{
  pinMode(13, OUTPUT);	//LED rojo
  pinMode(12, OUTPUT); //LED naranja
  pinMode(11, OUTPUT);	//LED verde
  
}

void loop()
{
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(13, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(1500); // Wait for 1500 millisecond(s)
}
