#include "common_structs.h"
#include <stdio.h>

int special_cases(v2i_t *size)
{
    if (size->x < 4 || size->y < 4)
        return (1);
    return (0);
}