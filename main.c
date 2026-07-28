#include <ncurses.h>
#include <stdlib.h>

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    
    int alive = 1;
    int ANCHO = 128;
    int ALTO = 32;
    int x = 0;
    int y = 0;
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
    }
    endwin();
}