#include "common_macros.h"
#include "dante_solve.h"
#include "common_structs.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int init_height(char *buffer, int size)
{
    int height = 0;

    for (int i = 0; i <= size; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0')
            height++;
    }
    return (height);
}

int init_width(char *buffer, int size)
{
    int width = 0;

    for (int i = 0; i <= size; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            width = i;
            return (width);
        }
    }
    return (width);
}

infos_t *init_infos(char *buffer)
{
    infos_t *infos = malloc(sizeof(infos_t));

    if (infos == NULL) {
        write(STDERR_FILENO, MALLOC, strlen(MALLOC));
        return (NULL);
    }
    infos->size = strlen(buffer);
    infos->cols = init_width(buffer, infos->size);
    infos->lines = init_height(buffer, infos->size);
    infos->maze = convert_map(buffer, infos, infos->size);
    if (infos->maze == NULL) {
        write(STDERR_FILENO, MALLOC, strlen(MALLOC));
        return (NULL);
    }
    return (infos);
}