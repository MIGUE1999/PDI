int ledPin = 13;
char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", //A-I
".--", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", //J-R
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."       //S-Z
};
char* numbers [ ] = {"-----", ".----", " ..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
int dotDelay = 100;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}
void loop()
{
char ch;
if (Serial.available()) // ¿hay algo que leer del USB?
{
ch = Serial.read(); // leer una letra
if (ch >= 'a' && ch <= 'z')
{
flashSequence(letters[ch - 'a']);
}
else if (ch >= 'A' && ch <= 'Z')
{
flashSequence(letters[ch - 'A']);
}
else if (ch >= '0' && ch <= '9')
{
flashSequence(numbers[ch - '0']);
}
else if (ch == ' ')
{
delay(dotDelay * 4); // espacio entre palabras
}
}
}
void flashSequence(char* sequence)
{
int i = 0;
while (sequence[i] != NULL)
{
flashDotOrDash(sequence[i]);
i++;
}
delay(dotDelay * 3 ) ; // espacio entre letras
}
void flashDotOrDash(char dotOrDash)
{
 tone(ledPin,1200,100);
digitalWrite(ledPin, HIGH);
 
if (dotOrDash == '.')
{
delay(dotDelay);
}
else // debe ser una -
{
delay(dotDelay * 3 ) ;
}
digitalWrite(ledPin, LOW);
delay(dotDelay); // espacio entre destellos
}
