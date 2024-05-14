#include <curses.h>
#include "common_structs.h"
#include "loop_header.h"
#include <unistd.h>
#include <stdbool.h>

static void change_color(char ch, bool on)
{
    enum map_colors color;

    switch (ch) {
    case 'X':
        color = X_COLOR;
        break;
    case '*':
        color = STAR_COLOR;
        break;
    case 'o':
        color = O_COLOR;
        break;
    case 'V':
        color = V_COLOR;
        break;
    }
    if (on)
        attron(COLOR_PAIR(color));
    else
        attroff(COLOR_PAIR(color));
}

static int check_too_small(int height, int width, v2i_t *size)
{
    char const *message = "Terminal too small.";

    if (height < size->y || width < size->x) {
        clear();
        mvwprintw(
            stdscr,
            height / 2,
            width / 2 - (20 / 2),
            message
        );
        refresh();
        usleep(10000);
        return (1);
    }
    return (0);
}

static void print_sstr(char **map, v2i_t *size, unsigned int height,
unsigned int width)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < size->y; i++) {
        y = height / 2 - size->y / 2 + i;
        for (int j = 0; j < size->x; j++) {
            x = width / 2 - size->x / 2 + j;
            change_color(map[i][j], true);
            mvaddch(
                y,
                x,
                ' '
            );
            change_color(map[i][j], false);
        }
    }
}

int display_map(char **map, v2i_t *size, int ms_wait)
{
    unsigned int height = 0;
    unsigned int width = 0;
    char ch = 0;

    do {
        getmaxyx(stdscr, height, width);
        ch = getch();
        if (ch == 'q')
            return (1);
    } while (ch != ERR || check_too_small(height, width, size));
    clear();
    print_sstr(map, size, height, width);
    refresh();
    usleep(ms_wait * 1000);
    return (0);
}

int curse_final_loop(char **map, v2i_t *size)
{
    unsigned int height = 0;
    unsigned int width = 0;
    char ch;

    for (int i = 0; i < 6; i++) {
        ch = getch();
        if (ch == 'q')
            return (1);
        getmaxyx(stdscr, height, width);
        if (!check_too_small(height, width, size)) {
            clear();
            print_sstr(map, size, height, width);
            refresh();
            usleep(100000);
        }
    }
    return (0);
}