#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 100000

 int x, y;
 int max_y = 24, max_x = 80;
 int next_x = 0;
 int directionx = 1;
 int next_y = 0;
 int directiony = 1;
 int xc = 10, yc = 1;
 int xc2 = 10, yc2 = 22;
 int ch = 0, ch2 = 0;

 int rows,cols;
 int comienza=10;

 int golesj1=0, golesj2=0;

 bool done=false;
 bool stopcont=false;


void dibuja_ventana_bienvenida(){
	noecho();
 	curs_set(FALSE);

  if (has_colors() == FALSE) {
    	endwin();
    	printf("Your terminal does not support color\n");
    	exit(1);
	}

    start_color();
	init_pair(3,COLOR_WHITE,COLOR_BLUE);
    clear();
	refresh();

	getmaxyx(stdscr, rows, cols);
	max_y=rows;
	max_x=cols;
	xc = cols/2;
	yc = 1;
 	xc2 = cols/2; 
	yc2 = rows-2;
	x = rows/2;
	y = cols/2;
	
	WINDOW *window = newwin(rows,cols,0,0);
	
	wbkgd(window, COLOR_PAIR(3));
	box(window, '*', '*'); 
	
	//24 filas 80 columnas
    mvwprintw(window, 1, 30, "BIENVENIDO A PONG");
	mvwprintw(window, 3, 3, "A continuación se van a detallar las instrucciones del juego:");
    mvwprintw(window, 5, 3, "JUGADOR 1");
	mvwprintw(window, 6, 3, "Tecla para moverse hacia la izquierda: O");
	mvwprintw(window, 7, 3, "Tecla para moverse hacia la derecha: P");
	mvwprintw(window, 9, 3, "JUGADOR 2");
	mvwprintw(window, 10, 3, "Tecla para moverse hacia la izquierda: A");
	mvwprintw(window, 11, 3, "Tecla para moverse hacia la derecha: S");
	mvwprintw(window, 13, 3, "Pulsa la barra espaciadora para sacar nueva bola al haber colado gol");
	
	wrefresh(window);

	while(comienza > 0){
		
		mvwprintw(window, 16, 20, "El juego comenzará en %i segundos", comienza);
		sleep(1);
		comienza--;
		wrefresh(window);
		
	}
	 
    endwin();
	
}


void movimientos_jug1(){
	ch = getch();
	if (ch == 'o' && xc > 0)
		xc -= 1;
	else if (ch == 'p' && xc < cols-6)
		xc += 1;
	else if (ch == 'q')	
		done=true;
		
}

void movimientos_jug2(){
	ch2 = getch();
	if (ch2 == 'a' && xc2 > 0 )
		xc2 -= 1;
	else if (ch2 == 's' && xc2 < cols-6 )
		xc2 += 1;
	else if (ch2 == 'q')	
		done=true;	
	
}


void fijar_bordes_juego(){
	 start_color();
	 init_pair(3,COLOR_WHITE,COLOR_BLUE);
     clear();
	 wbkgd(stdscr, COLOR_PAIR(3));
	 box(stdscr, '*', '*'); 

}

void nueva_pelota(){
	y=rows/2;
	x=cols/2;
	sleep(2);
	stopcont=true;
}

void golj2()
{
	clear();
	golesj2++;
	mvwprintw(stdscr, 10, 10, "J2: %i", golesj2);
	nueva_pelota();

}

void golj1()
{
	clear();
	golesj1++;
	mvwprintw(stdscr, 10, 10, "J1: %i", golesj1);
	nueva_pelota();
}



int main(int argc, char *argv[]) {
 
	initscr();
	
	dibuja_ventana_bienvenida();
	
	clear();
	noecho();
	cbreak();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	refresh();
	

	while(!done){
		
		//declaracion de posicion de pelota y jugadores
		clear();
		fijar_bordes_juego();
		mvprintw(y, x, "o");
		mvprintw(yc, xc, "------");
		mvprintw(yc2, xc2, "------");
		mvprintw(10, 10, "J1: %i",golesj1);
		mvprintw(20, 10, "J2: %i",golesj2);


		refresh();


		
		//movimientos jugador 1
		if(directiony<0){
			movimientos_jug1();
			usleep(DELAY);
		}else{
		//movimientos jugador 2
			movimientos_jug2();
			usleep(DELAY);
		}

		
		next_x = x + directionx;
		next_y = y + directiony;
		
		//Direccionamiento horizontal y rebote en paredes laterales
		if (next_x >= max_x || next_x < 0) {
			directionx*= -1;
		}else 
		{
 			x+= directionx;
 		}
		
		//verticales

		 if (next_y >= max_y) {
			golj1();
			refresh();
		}

		if(next_y < 0)
		{
 			golj2();
			refresh();
 		}
		

		//Direccionamiento vertical y rebote en paredes de arriba y abajo

		if ((y == yc && (x == xc || x == xc+1 || x == xc+2 || x == xc+3 || x == xc+4 || x == xc+5 || x == xc+6 || x == xc+7 || x == xc+8)) ||  ( y == yc2 && (x == xc2 || x == xc2+1 || x == xc2+2 || x == xc2+3 || x == xc2+4 || x == xc2+5 || x == xc2+6 || x == xc2+7 || x == xc2+8)) ) 
		{
			directiony *= -1;
			
		}else 
		{
			y += directiony; 
		}
		

		
		
	}


 	endwin();
}

