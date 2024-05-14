#include "loop_header.h"
#include <stdlib.h>

static const v2i_t DIRECTIONS[] = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0},
};

static int is_valid_path(char **map, v2i_t *size, v2i_t *pos, int direction)
{
    v2i_t dir_struct = DIRECTIONS[direction];
    v2i_t test_pos = {pos->x + dir_struct.x, pos->y + dir_struct.y};

    if ((map[pos->y - dir_struct.y][pos->x - dir_struct.x] == 'X'))
        return (0);
    if (test_pos.x < 0 || test_pos.x >= size->x)
        return (0);
    if (test_pos.y < 0 || test_pos.y >= size->y)
        return (0);
    if (!(map[pos->y][pos->x] == 'X' &&
    map[test_pos.y][test_pos.x] == 'X'))
        return (0);
    return (1);
}

static int make_paths_at_pos(char **map, v2i_t *size, v2i_t *pos)
{
    int dir_int = rand() % 4;
    v2i_t direction = {0};
    v2i_t forward = {0};
    v2i_t l_pos = *pos;
    int r_val = 0;

    for (int i = 0; i < 4 && !r_val; i++) {
        direction = DIRECTIONS[dir_int];
        forward = (v2i_t){l_pos.x + direction.x, l_pos.y + direction.y};
        if (is_valid_path(map, size, &forward, dir_int)) {
            map[forward.y][forward.x] = '*';
            map[forward.y + direction.y][forward.x + direction.x] = '*';
            l_pos = (v2i_t){forward.x + direction.x, forward.y + direction.y};
            dir_int = rand() % 4;
            i = -1;
            r_val = display_map(map, size, 20);
        } else
            dir_int = (dir_int + 1) % 4;
    }
    return (r_val);
}

int dig_map(char **map, v2i_t *size)
{
    int r_val = 0;

    map[0][0] = '*';
    for (int y = 0; y < size->y && !r_val; y += 2)
        for (int x = 0; x < size->x && !r_val; x += 2)
            r_val = make_paths_at_pos(map, size, (v2i_t [1]){{x, y}});
    if (r_val)
        return (SUCCESS);
    map[0][0] = '*';
    map[0][1] = '*';
    map[size->y - 1][size->x - 1] = '*';
    if (size->x % 2 && size->y % 2)
        map[size->y - 1][size->x - 2] = '*';
    return (EXIT_OK);
}