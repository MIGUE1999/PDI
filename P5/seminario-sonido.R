library(tuneR)
library(seewave)
library(audio)

#Ejercicio 1
perro <- readWave('/home/migue/Escritorio/universidad/CUARTO/SEGUNDOCUATRIMESTRE/PDIH/PRACTICAS/S0/PDIH/P5/S-varios-sonidos/S-varios-sonidos/perro.wav')
perro
gato <- readMP3('/home/migue/Escritorio/universidad/CUARTO/SEGUNDOCUATRIMESTRE/PDIH/PRACTICAS/S0/PDIH/P5/S-varios-sonidos/S-varios-sonidos/gato.mp3')
gato



#Ejercicio 2
plot( extractWave(perro, from = 1, to = 159732))
plot( extractWave(gato, from = 1, to = 393984))

#Ejercicio 3
str(perro)
str(gato)

#Ejercicio 4 
sonidounion  <- pastew(perro, gato, output="Wave")

#Ejercicio 5 
plot( extractWave(sonidounion, from = 1, to = 553716) )

#Ejercicio 6
filtro <- bwfilter(sonidounion, n=1, from = 10000, to = 20000, bandpass = TRUE, listen = FALSE, output = "Wave")
plot(extractWave(filtro, from = 1, to = 553235764))

#Ejercicio 7
writeWave(filtro, file.path('/home/migue/Escritorio/universidad/CUARTO/SEGUNDOCUATRIMESTRE/PDIH/PRACTICAS/S0/PDIH/P5/S-varios-sonidos/S-varios-sonidos/mezcla.wav'))

#Ejercicio 8

hola <-  readWave('/home/migue/Escritorio/universidad/CUARTO/SEGUNDOCUATRIMESTRE/PDIH/PRACTICAS/S0/PDIH/P5/S-varios-sonidos/S-varios-sonidos/hola.wav')

eco <- echo(hola,f=22050,amp=c(0.8,0.4,0.2),delay=c(1,2,3),output="Wave")
eco@left <- 10000 * eco@left

alreves <- revw(eco, output="Wave")
listen(alreves)

writeWave(alreves, file.path("/home/migue/Escritorio/universidad/CUARTO/SEGUNDOCUATRIMESTRE/PDIH/PRACTICAS/S0/PDIH/P5/S-varios-sonidos/S-varios-sonidos/alreves.wav"))