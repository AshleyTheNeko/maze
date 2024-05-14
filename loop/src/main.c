#include "loop_header.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>
#include <time.h>

static void init_curses(void)
{
    initscr();
    cbreak();
    noecho();
    nonl();
    nodelay(stdscr, TRUE);
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    start_color();
    init_pair(STAR_COLOR, COLOR_BLACK, COLOR_BLACK);
    init_pair(X_COLOR, COLOR_WHITE, COLOR_WHITE);
    init_pair(O_COLOR, COLOR_GREEN, COLOR_GREEN);
    init_pair(V_COLOR, COLOR_RED, COLOR_RED);
}

status_t parse_args(int ac, char **av, v2i_t *size, bool *perfect)
{
    if (ac < 3)
        return (EXIT_ERROR);
    if (ac > 4)
        return (EXIT_ERROR);
    size->x = atoi(av[1]);
    size->y = atoi(av[2]);
    if (size->y <= 0 || size->x <= 0)
        return (EXIT_ERROR);
    if (special_cases(size)) {
        write(2, "Size too small.\n", 17);
        return (EXIT_ERROR);
    }
    if (ac == 4)
        if (!strcmp(av[3], "perfect"))
            *perfect = true;
    return (EXIT_OK);
}

int main(int argc, char **argv)
{
    v2i_t size = {0};
    bool perfect = false;
    status_t ret_val = EXIT_OK;
    char **map = NULL;

    if (parse_args(argc, argv, &size, &perfect))
        return (EXIT_ERROR);
    init_curses();
    srand(time(NULL));
    while(ret_val == EXIT_OK) {
        ret_val = init_generation(&size, perfect, &map);
        if (ret_val == EXIT_OK)
            ret_val = solve_maze(
                (infos_t [1]){{.maze = map, .cols = size.x, .lines = size.y}});
        if (ret_val == EXIT_OK)
            ret_val = curse_final_loop(map, &size);
        free_map(map, &size);
    }
    endwin();
    return (ret_val);
}