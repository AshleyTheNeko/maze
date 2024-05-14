#include "dante_solve.h"
#include "common_macros.h"
#include "common_structs.h"
#include <stdio.h>
#include <stdlib.h>

const v2i_t ALL_DIRECTIONS[] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

int check_coordinates(infos_t *infos, int line, int col, char c)
{
    if (line < 0 || line > infos->lines - 1)
        return (ERROR);
    if (col < 0 || col > infos->cols - 1)
        return (ERROR);
    if (infos->maze[line][col] != c)
        return (ERROR);
    return (SUCCESS);
}

int check_directions(infos_t *infos, int *i, int *j, char c)
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

int check_end(infos_t *infos, int *i, int *j)
{
    if (check_directions(infos, i, j, '*') == ERROR) {
        infos->maze[*i][*j] = 'V';
        if (check_directions(infos, i, j, 'o') == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}

int execute_algorithm(infos_t *infos, int i, int j)
{
    if (infos->maze[i][j] != '*')
        return (ERROR);
    while (i != infos->lines - 1 || j != infos->cols - 1) {
        infos->maze[i][j] = 'o';
        if (check_end(infos, &i, &j) == ERROR)
            return (ERROR);
    }
    infos->maze[i][j] = 'o';
    return (SUCCESS);
}

int solve_maze(char *buffer)
{
    infos_t *infos = init_infos(buffer);

    if (infos == NULL)
        return (EXIT_ERROR);
    if (execute_algorithm(infos, 0, 0))
        print_maze(infos->maze, infos->cols, infos->lines);
    else
        printf("no solution found");
    free_maze(infos);
    free(buffer);
    return (0);
}