void setup()
{
  pinMode(13, OUTPUT);	//LED rojo
  pinMode(12, OUTPUT); //LED naranja
  pinMode(11, OUTPUT);	//LED verde
  pinMode(7, INPUT);	//pulsador
}


void pulsador(){
if(digitalRead(7)==LOW){
       digitalWrite(13, HIGH);
       digitalWrite(12, LOW);
       digitalWrite(11, LOW);
       delay(1500);
    }

}

void loop()
{
  
  	digitalWrite(12, LOW);
  	pulsador();
    digitalWrite(11, LOW);
    pulsador();  
    digitalWrite(13, HIGH);
  	pulsador();
    delay(1500); // Wait for 1500 millisecond(s)
    pulsador();
    
    digitalWrite(13, LOW);
    pulsador();  
    digitalWrite(12, HIGH);
    pulsador();  
    delay(1500); // Wait for 1500 millisecond(s)
    pulsador();
    
    digitalWrite(12, LOW);
    pulsador();  
    digitalWrite(11, HIGH);
    pulsador();  
    delay(1500); // Wait for 1500 millisecond(s)
  	pulsador();
  
}
