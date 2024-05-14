#include "common_macros.h"
#include "common_structs.h"
#include "loop_header.h"
#include <stdio.h>
#include <stdlib.h>

const v2i_t ALL_DIRECTIONS[] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

static int check_coordinates(infos_t *infos, int line, int col, char c)
{
    if (line < 0 || line > infos->lines - 1)
        return (ERROR);
    if (col < 0 || col > infos->cols - 1)
        return (ERROR);
    if (infos->maze[line][col] != c)
        return (ERROR);
    return (SUCCESS);
}

static int check_directions(infos_t *infos, int *i, int *j, char c)
{
    for (int index = 0; index < DIRECTIONS_SIZE; index++) {
        if (check_coordinates(infos, *i + ALL_DIRECTIONS[index].x,
        *j + ALL_DIRECTIONS[index].y, c)) {
            *i += ALL_DIRECTIONS[index].x;
            *j += ALL_DIRECTIONS[index].y;
            return (SUCCESS);
        }
    }
    return (ERROR);
}

static int check_end(infos_t *infos, int *i, int *j)
{
    if (check_directions(infos, i, j, '*') == ERROR) {
        infos->maze[*i][*j] = 'V';
        if (check_directions(infos, i, j, 'o') == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}

static int execute_algorithm(infos_t *infos, int i, int j)
{
    int r = 0;

    if (infos->maze[i][j] != '*')
        return (ERROR);
    while ((i != infos->lines - 1 || j != infos->cols - 1) && !r) {
        infos->maze[i][j] = 'o';
        r = display_map(infos->maze,
        (v2i_t [1]){{infos->cols, infos->lines}}, 20);
        if (check_end(infos, &i, &j) == ERROR)
            return (ERROR);
    }
    if (r)
        return (EXIT_ERROR);
    infos->maze[i][j] = 'o';
    return (SUCCESS);
}

int solve_maze(infos_t *infos)
{
    if (infos == NULL)
        return (EXIT_ERROR);
    if (execute_algorithm(infos, 0, 0) == EXIT_ERROR)
        return (SUCCESS);
    return (0);
}