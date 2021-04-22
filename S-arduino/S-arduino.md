## SEMINARIO ARDUINO

### Ejercicio 1

Para este ejercicio he usado 2 LED(uno rojo y otro verde), 2 resistencias(220 ohmios cada una), una placa de pruebas pequeña y un arduino Uno R3.

Para la creación del circuito he colocado en cada parte positiva de cada led una resistencia por su parte positiva, la parte negativa de las resistencias están conectadas a los pines 13(LED verde) y 12(LED verde). La parte negativa de los LED estan conectadas a tierra a tierra.


**Código**

En la función setup() defino el pin 13 y el 12 como OUTPUTS. En la función loop() fijo a LOW el pin 12(LED verde apagado), fijo el pin 13 a HIGH(LED rojo encendido) espero 1,5 segundos, apago el LED rojo 13(LOW) y enciendo el LED verde(HIGH). Vuelvo a esperar 1.5 segundos al final.

![imagen de la ejecucion](https://github.com/MIGUE1999/PDIH/blob/main/S1/ejecucion.png)


**Funcionamiento**

![imagen de la ejecucion](https://github.com/MIGUE1999/PDIH/blob/main/S1/ejecucion.png)





### Ejercicio 2

Para este ejercicio he usado 1 LED(rojo), 2 resistencias(10 Kiloohmios y 220 ohmios), un pulsador, una placa de pruebas pequeña y un arduino Uno R3.

Para la creación del circuito he colocado en cada parte positiva del led una resistencia (220 ohmios), la otra parte de la resistencia está conectada al pin 13. La parte negativa del LED está conectada a tierra. Por otra parte el pulsador está conectado a tierra, al pin 7 y a una resistencia(10 Kiloohmios) que a su vez esta conectada al pin de 5V del la placa. Esta sirve como resistencia de pull-up que hace que cuando no se esté pulsando el pulsador se quede en un estado alto(presencia de voltaje).


**Código**

En el código fijo el pin 13 como de salida y el 7 de entrada en la función setup(). En loop() compruebo si el pulsador está siendo pulsado y si es así enciendo el led poniendo a HIGH el pin 13. Si esto no ocurre dejo el LED apagado poniendo en LOW el pin 13.

![imagen de la ejecucion](https://github.com/MIGUE1999/PDIH/blob/main/S1/ejecucion.png)


**Funcionamiento**

![imagen de la ejecucion](https://github.com/MIGUE1999/PDIH/blob/main/S1/ejecucion.png)
