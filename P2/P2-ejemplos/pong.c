#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
 int x = 0, y = 0;
 int max_y = 20, max_x = 20;
 int next_x = 0;
 int direction = 1;
 int rows,cols;
 int comienza=10;

 initscr();
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
	WINDOW *window = newwin(rows,cols,0,0);


	wbkgd(window, COLOR_PAIR(3));
	box(window, '*', '*'); 
	
	//24 filas 80 columnas
    mvwprintw(window, 1, 30, "BIENVENIDO A PONG");
	mvwprintw(window, 3, 3, "A continuación se van a detallar las instrucciones del juego:");
    mvwprintw(window, 5, 3, "JUGADOR 1");
	mvwprintw(window, 6, 3, "Tecla para moverse hacia arriba: W");
	mvwprintw(window, 7, 3, "Tecla para moverse hacia abajo: S");
	mvwprintw(window, 9, 3, "JUGADOR 2");
	mvwprintw(window, 10, 3, "Tecla para moverse hacia arriba: O");
	mvwprintw(window, 11, 3, "Tecla para moverse hacia abajo: L");
	mvwprintw(window, 13, 3, "Pulsa la barra espaciadora para sacar nueva bola al haber colado gol");
	
	wrefresh(window);
	while(comienza > 0){
		mvwprintw(window, 16, 20, "El juego comenzará en %i segundos ",comienza);
		sleep(1);
		comienza--;
		wrefresh(window);
		
	}
	
//	getch(); 
    endwin();
/*
	while(1) {
		clear();
		mvprintw(y, x, "o");
		refresh();

		usleep(DELAY);

		next_x = x + direction;

		if (next_x >= max_x || next_x < 0) {
			direction*= -1;
		} else {
			x+= direction;
		}
	}
*/
 	endwin();
}