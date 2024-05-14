#include <unistd.h>
#include "dante_gen.h"

void print_map(char **map, v2i_t *size)
{
    for (int y = 0; y < size->y; y++) {
        write(1, map[y], size->x);
        if (y != size->y - 1)
            write(1, "\n", 1);
    }
}