#include "dante_gen.h"
#include <stdlib.h>
#include <time.h>

static void remove_random_walls(char **map, v2i_t *size)
{
    for (int y = 0; y < size->y; y++)
        for (int x = 0; x < size->x; x++)
            map[y][x] = (map[y][x] == 'X' && !(rand() % 2)) ? '*' : map[y][x];
    for (int y = 5; y < size->y - 5; y++)
        for (int x = 5; x < size->x - 5; x++)
            map[y][x] = (map[y][x] == '*' && !(rand() % 3)) ? 'X' : map[y][x];
}

static void fill_map_with_walls(char **map, v2i_t *size)
{
    for (int y = 0; y < size->y; y++)
        for (int x = 0; x < size->x; x++)
            map[y][x] = 'X';
}

status_t init_generation(v2i_t *size, bool perfect)
{
    char **map = NULL;

    map = calloc(size->y, sizeof(char *));
    if (!map)
        return (EXIT_ERROR);
    for (int y = 0; y < size->y; y++) {
        map[y] = calloc(size->x, sizeof(char));
        if (!map[y]) {
            free_map(map, size);
            return (EXIT_ERROR);
        }
    }
    srand(time(NULL));
    fill_map_with_walls(map, size);
    dig_map(map, size);
    if (!perfect)
        remove_random_walls(map, size);
    print_map(map, size);
    free_map(map, size);
    return (EXIT_OK);
}