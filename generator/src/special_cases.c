#include "dante_gen.h"
#include <stdio.h>

int special_cases(v2i_t *size)
{
    if (size->x == 1 && size->y == 1) {
        putchar('*');
        return (1);
    }
    if (size->y == 1) {
        for (int i = 0; i < size->x; i++)
            putchar('*');
        return (1);
    }
    if (size->x == 1) {
        for (int i = 0; i < size->y - 1; i++) {
            putchar('*');
            putchar('\n');
        }
        putchar('*');
        return (1);
    }
    return (0);
}