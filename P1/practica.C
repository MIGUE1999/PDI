#include <stdio.h>
#include <dos.h>

#define BYTE unsigned char
BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;
unsigned char TEXTCOLOR=0x0;
unsigned char BACKGROUNDCOLOR=0x1;
//PRACTICA 1

//pausa hasta que se toca una tecla cualquiera
void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}


int mi_getchar(){
	 union REGS inregs, outregs;
	 int caracter;

	 inregs.h.ah = 1;
	 int86(0x21, &inregs, &outregs);

	 caracter = outregs.h.al;
	 return caracter;
}

void mi_putchar(char c){
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(0x21, &inregs, &outregs);
}


//coloca el cursor en una posición determinada
void gotoxy(){
   union REGS inregs, outregs;   
   inregs.h.ah=2;
   inregs.h.dh= 0x00;
   inregs.h.dl= 0x00;
   inregs.h.bh= 0;
   int86(0x10,&inregs,&outregs);

}

//fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
void setcursortype(int tipo_cursor){
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}


//fija el modo de video deseado
void setvideomode(BYTE modo){
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}

//obtiene el modo de video actual

int getvideomode(){
   
   union REGS inregs, outregs;   
   
   inregs.h.ah=0xf;

   int86(0x10,&inregs,&outregs);

 //  unsigned char modosalida;
   //modosalida = outregs.h.al;
   //int ncol= outregs.h.ah;
   
   return outregs.h.al;
}


//modifica el color de primer plano con que se mostrarán los caracteres
void textcolor(unsigned char ctexto){
   TEXTCOLOR=ctexto;

}


//modifica el color de fondo con que se mostrarán los caracteres
void textbackground(unsigned char cfondo){
   BACKGROUNDCOLOR=cfondo;
}

//borra toda la pantalla
void clrscr(){
   
   union REGS inregs, outregs;   
   
   inregs.h.ah=0x6;
   inregs.h.al= 0x20;
   inregs.h.bh= 0x0;
   inregs.h.ch= 0x00;
   inregs.h.cl = 0x00;
   inregs.h.dh= 0x20;
   inregs.h.dl= 0x50;

   int86(0x10,&inregs,&outregs);	
}

//Escribe un carácter en pantalla con el color indicado actualmente
void cputchar(char letra){
	
	union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = letra;
	inregs.h.bl = BACKGROUNDCOLOR << 4 | TEXTCOLOR;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;

}

//obtiene un carácter de teclado y lo muestra en pantalla
void getche(){
   
   int tmp;
   printf("\nPulsa una tecla...  ");
	tmp = mi_getchar();

	printf("\nHas pulsado: ");
    mi_putchar( (char)tmp );

}



int main(){
   //gotoxy
   /*
   gotoxy();

    //setcursortype
   
    printf("\nCursor invisible: ");
   	setcursortype(0);
   	mi_pausa();
   	printf("\nCursor grueso: ");
   	setcursortype(2);
   	mi_pausa();
   	printf("\nCursor normal: ");
   	setcursortype(1);
   	mi_pausa();
   
  
  //setvideomode
  
    
   printf("setvideomode");
    setvideomode(MODOTEXTO); //Grafico
	

   //unsigned char modo = getvideomode();
   printf("borratodo");

	clrscr();

   cputchar();

	getche();
*/
   int mode= getvideomode();
   printf("Modo: %i",mode);
   return 0;
}
