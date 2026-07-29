#include <curses.h>
#include <stdlib.h>

struct Punto
{
    int x;
    int y;
};

int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);

    int alive = 1;
    int ANCHO = 100;
    int ALTO = 40;
    int manzanas = 0;

    struct Punto serpiente[256];
    struct Punto manzana;
    int longitud = 10;
    int dx = 1;
    int dy = 0;
    serpiente[0].x = ANCHO / 2;
    serpiente[0].y = ALTO / 2;

    manzana.x = rand() % (ANCHO - 2) + 1;
    manzana.y = rand() % (ALTO - 2) + 1;
    manzanas = 1;

    while (alive != 0)
    {
        int tecla = getch();

        switch (tecla)
        {
        case KEY_UP:
            dy = -1;
            dx = 0;
            break;
        case KEY_DOWN:
            dy = 1;
            dx = 0;
            break;
        case KEY_LEFT:
            dx = -1;
            dy = 0;
            break;
        case KEY_RIGHT:
            dx = 1;
            dy = 0;
            break;
        }

        clear();

        mvprintw(manzana.y, manzana.x, "*");

        if (manzanas == 0)
        {
            manzana.x = rand() % (ANCHO - 2) + 1;
            manzana.y = rand() % (ALTO - 2) + 1;
            mvprintw(manzana.y, manzana.x, "*");
            manzanas = 1;
        }

        for (int y = 0; y < ALTO; y++)
        {
            for (int x = 0; x < ANCHO; x++)
            {
                if (y == 0)
                {
                    if (x == 0 || x == ANCHO - 1)
                        mvprintw(y, x, "+");
                    else
                        mvprintw(y, x, "-");
                }
                else if (y == ALTO - 1)
                {
                    if (x == 0 || x == ANCHO - 1)
                        mvprintw(y, x, "+");
                    else
                        mvprintw(y, x, "-");
                }
                else
                {
                    if (x == 0 || x == ANCHO - 1)
                        mvprintw(y, x, "|");
                }
            }
        }

        for (int i = longitud; i > 0; i--)
        {
            serpiente[i].y = serpiente[i - 1].y;
            serpiente[i].x = serpiente[i - 1].x;
        }

        serpiente[0].x = serpiente[0].x + dx;
        serpiente[0].y = serpiente[0].y + dy;

        if (serpiente[0].x <= 0 || serpiente[0].x >= ANCHO - 1 ||
            serpiente[0].y <= 0 || serpiente[0].y >= ALTO - 1)
        {
            alive = 0;
        }

        for (int i = 1; i < longitud; i++)
        {
            if (serpiente[0].x == serpiente[i].x &&
                serpiente[0].y == serpiente[i].y)
            {
                alive = 0;
            }
        }

        if (serpiente[0].x == manzana.x && serpiente[0].y == manzana.y)
        {
            longitud++;
            manzanas = 0;
        }

        for (int i = 0; i < longitud; i++)
        {
            mvprintw(serpiente[i].y, serpiente[i].x, "0");
        }
        mvprintw(1, 2, "  _____ _   _          _  ________");
        mvprintw(2, 2, " / ____| \\ | |   /\\   | |/ /  ____|");
        mvprintw(3, 2, "| (___ |  \\| |  /  \\  | ' /| |__  ");
        mvprintw(4, 2, " \\___ \\| . ` | / /\\ \\ |  < |  __|  ");
        mvprintw(5, 2, " ____) | |\\  |/ ____ \\| . \\| |____");
        mvprintw(6, 2, "|_____/|_| \\_/_/    \\_\\_|\\__\\______|");
        mvprintw(8, 2, "Puntuation: %d", longitud - 10);
        refresh();
    }

    clear();
    int centrox = ANCHO / 2;
    int centroy = ALTO / 2;
    attron(A_BOLD);
    mvprintw(centroy -3 , centrox, "GAME OVER");
    attroff(A_BOLD);
    mvprintw(centroy, centrox, "Puntaje: %d", longitud - 10);
    refresh();
    getch();

    napms(6000);

    endwin();
    return 0;
}