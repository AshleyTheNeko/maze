#include "loop_header.h"
#include <malloc.h>

void free_map(char **map, v2i_t *size)
{
    if (!map)
        return;
    for (int y = 0; y < size->y; y++)
        free(map[y]);
    free(map);
}