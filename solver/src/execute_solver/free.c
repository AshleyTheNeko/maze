#include "common_macros.h"
#include "common_structs.h"
#include <stdlib.h>
#include <unistd.h>

void free_2d_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void free_maze(infos_t *infos)
{
    free_2d_array(infos->maze);
    free(infos);
}