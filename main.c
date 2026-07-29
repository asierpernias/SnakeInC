#include <curses.h>
#include <stdlib.h>
#include <stdio.h>

struct Punto
{
    int x;
    int y;
};

#define HIGHSCORE_FILE "highscore.txt"

int cargar_document()
{
    int valor = 0;
    FILE *f = fopen(HIGHSCORE_FILE, "r");
    if (f != NULL)
    {
        fscanf(f, "%d", &valor);
        fclose(f);
    }
    return valor;
}

void guardar_maxima(int valor)
{
    FILE *f = fopen(HIGHSCORE_FILE, "w");
    if (f != NULL)
    {
        fprintf(f, "%d", valor);
        fclose(f);
    }
}

int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_CYAN, COLOR_BLACK);
        init_pair(4, COLOR_YELLOW, COLOR_BLACK);
        init_pair(5, COLOR_WHITE, COLOR_BLACK);
    }

    int alive;
    int ANCHO = 100;
    int ALTO = 40;
    int manzanas;

    struct Punto serpiente[256];
    struct Punto manzana;
    int longitud;
    int dx;
    int dy;

    int highscore_guardado = cargar_document();
    int highscore = highscore_guardado;
    int score;
    int velocidad;

inicio:

    alive = 1;
    manzanas = 1;
    longitud = 10;
    dx = 1;
    dy = 0;
    velocidad = 100;

    serpiente[0].x = ANCHO / 2;
    serpiente[0].y = ALTO / 2;

    manzana.x = rand() % (ANCHO - 2) + 1;
    manzana.y = rand() % (ALTO - 2) + 1;

    timeout(velocidad);

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

        attron(COLOR_PAIR(2));
        mvprintw(manzana.y, manzana.x, "*");
        attroff(COLOR_PAIR(2));

        if (manzanas == 0)
        {
            manzana.x = rand() % (ANCHO - 2) + 1;
            manzana.y = rand() % (ALTO - 2) + 1;
            attron(COLOR_PAIR(2));
            mvprintw(manzana.y, manzana.x, "*");
            attroff(COLOR_PAIR(2));
            manzanas = 1;
        }

        attron(COLOR_PAIR(3));
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
        attroff(COLOR_PAIR(3));

        for (int i = longitud; i > 0; i--)
        {
            serpiente[i] = serpiente[i - 1];
        }

        serpiente[0].x += dx;
        serpiente[0].y += dy;

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

        attron(COLOR_PAIR(1));
        for (int i = 0; i < longitud; i++)
        {
            mvprintw(serpiente[i].y, serpiente[i].x, "0");
        }
        attroff(COLOR_PAIR(1));

        score = longitud - 10;
        if (score > highscore)
        {
            highscore = score;
        }

        velocidad = 100 - score * 3;
        if (velocidad < 30)
        {
            velocidad = 30;
        }
        timeout(velocidad);

        attron(COLOR_PAIR(4));
        mvprintw(ALTO + 1, 2, "  _____ _   _          _  ________");
        mvprintw(ALTO + 2, 2, " / ____| \\ | |   /\\   | |/ /  ____|");
        mvprintw(ALTO + 3, 2, "| (___ |  \\| |  /  \\  | ' /| |__");
        mvprintw(ALTO + 4, 2, " \\___ \\| . ` | / /\\ \\ |  < |  __|");
        mvprintw(ALTO + 5, 2, " ____) | |\\  |/ ____ \\| . \\| |____");
        mvprintw(ALTO + 6, 2, "|_____/|_| \\_/_/    \\_\\_|\\__\\______|");
        attroff(COLOR_PAIR(4));

        attron(COLOR_PAIR(5));
        mvprintw(ALTO + 8, 2, "Score: %d", score);
        mvprintw(ALTO + 9, 2, "Highscore: %d", highscore);
        mvprintw(ALTO + 10, 2, "Speed: %d", 101 - velocidad);
        attroff(COLOR_PAIR(5));

        refresh();
    }

    if (highscore > highscore_guardado)
    {
        guardar_maxima(highscore);
        highscore_guardado = highscore;
    }

    clear();
    int centrox = ANCHO / 2;
    int centroy = ALTO / 2;

    attron(A_BOLD);
    attron(COLOR_PAIR(5));
    mvprintw(centroy - 3, centrox, "GAME OVER");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(5));

    mvprintw(centroy, centrox, "Score: %d", longitud - 10);
    mvprintw(centroy + 1, centrox, "Highscore: %d", highscore);
    mvprintw(centroy + 3, centrox, "Press ENTER to retry / SPACE to finish");
    refresh();
    timeout(-1);

    int click = getch();

    switch (click)
    {
    case '\n':
    case KEY_ENTER:
        goto inicio;
    case ' ':
        endwin();
        return 0;
    }

    endwin();
    return 0;
}