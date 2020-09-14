#include <curses.h>
WINDOW *ventana; WINDOW *ventana1; WINDOW *ventana2; WINDOW *ventana3; WINDOW *ventana4;
int main(){
int MaxY, MaxX;
int key;
int contador=1;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors()){
        endwin();
        return 1;
    } 
    cbreak();
    noecho();
    key=getch();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    ventana = newwin(MaxY, MaxX, 0, 0);
    ventana1 = newwin(MaxY / 2, MaxX / 2, 0, 0);
    ventana2 = newwin(MaxY / 2, MaxX / 2, 0, MaxX / 2);
    ventana3 = newwin(MaxY / 2, MaxX / 2, MaxY / 2, 0);
    ventana4 = newwin(MaxY / 2, MaxX / 2, MaxY / 2, MaxX / 2);
    wbkgd(ventana, COLOR_PAIR(1));
    wbkgd(ventana1, COLOR_PAIR(1));
    wbkgd(ventana2, COLOR_PAIR(1));
    wbkgd(ventana3, COLOR_PAIR(1));
    wbkgd(ventana4, COLOR_PAIR(1));
    refresh();
     touchwin(ventana);
    wrefresh(ventana);
    box(ventana1, 0, 0);
    touchwin(ventana1);
    wrefresh(ventana1);
    box(ventana2, 0, 0);
    do{
   
   	key=getch();
   	if (key==27){
   		
   	}else if (contador==1){
   		wclear(ventana1);
    	wrefresh(ventana1);
    	touchwin(ventana2);
    	wrefresh(ventana2);
    	box(ventana1, 0, 0);
    	box(ventana3, 0, 0);
    	contador++;	
   	}else if (contador==2){
   		wclear(ventana2);
    	wrefresh(ventana2);
    	touchwin(ventana3);
    	wrefresh(ventana3);
    	box(ventana2, 0, 0);
    	box(ventana3, 0, 0);
    	box(ventana4, 0, 0);
    	contador++;
   	}else if (contador==3){
   		wclear(ventana3);
    	wrefresh(ventana3);
    	touchwin(ventana4);
    	wrefresh(ventana4);
    	box(ventana3, 0, 0);
    	box(ventana4, 0, 0);
    	contador++;	
   	}else if (contador==4){
   		wclear(ventana4);
    	wrefresh(ventana4);
    	touchwin(ventana1);
    	wrefresh(ventana1);
    	contador=1;
   	}
}while(key!=27);

    endwin();
    return 0;
} 