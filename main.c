#include <ncurses.h>
#include <stdlib.h>
struct Punto {
    int x;
    int y;
};
  
int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    
    int alive = 1;
    int ANCHO = 128;
    int ALTO = 32;

    struct Punto serpiente[256];
    int longitud = 1;
    int dx = 0;
    int dy = 0;
    serpiente[0].x = ANCHO / 2;
    serpiente[0].y = ALTO / 2;

    while (alive != 0) {
        clear();

        for (int y = 0; y < ALTO; y++) {
            for (int x = 0; x < ANCHO; x++) {
                if (y == 0 ) {
                    if (x == 0 || x == 128) {
                        mvprintw(y, x, "+");
                    } else {
                        mvprintw(y, x, "-");
                    }
                } else if (y == 32) {
                    if (x == 0 || x == 128) {
                        mvprintw(y, x, "+");
                    } else {
                        mvprintw(y, x, "-");
                    }
                } else {
                    if (x == 0 || x == 128) {
                        mvprintw(y, x, "|");
                    }
                }
            }
        }

        int tecla = getch();

        switch (tecla) {
            case KEY_UP:
                dy = -1;
                break;
            
            case KEY_DOWN:
                dy= 1;
                break;
            
            case KEY_LEFT:
                dx= -1;
                break;
            
            case KEY_RIGHT:
                dx = 1;
                break
            

        for (int i = longitud; i > 0 ; i--) {
            serpiente[i].y = serpiente[i - 1].y;
            serpiente[i].x = serpiente[i - 1].x;
        }

        serpiente[0].x = serpiente[0].x + dx;
        serpiente[0].y = serpiente[0].y + dy;

        for (int i = 0; i < longitud; i++) {
            mvprintw(serpiente[i].y, serpiente[i].x, "0");
        }
    }
    endwin();
}