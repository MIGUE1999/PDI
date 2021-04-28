byte ledPin[] = {10, 11, 12, 13};
 
int ledDelay = 300 ;
 
int direccion = 1;
 
int LEDActual = 0;
 

 

void cambioLED() {
 
  for(int x=0; x<4 ; x++){
 
    digitalWrite(ledPin[x],LOW);
 
  }
 
  digitalWrite(ledPin[LEDActual],HIGH);
 
  LEDActual += direccion;
 
  if (LEDActual == 3) {
 
    direccion = -1;
 
  }
 
  if (LEDActual == 0) {
 
    direccion = 1;
 
  }
 
}
 
void setup() {
 
	 for(int x=0; x<4 ; x++){
	 
		pinMode(ledPin[x], OUTPUT);
	 
	 }

}
 
 
 
void loop() {
 
  cambioLED();
 
  delay(100);
 
}
 
 
 

