#include "common_structs.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **convert_map(char *buffer, infos_t *infos, int size)
{
    char **maze = malloc(sizeof(char *) * (infos->lines + 1));
    char *tmp = malloc(sizeof(char) * (infos->cols + 1));
    int tmp_i = 0;
    int lines = 0;

    if (maze == NULL || tmp == NULL)
        return (NULL);
    for (int i = 0; i <= size; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            tmp[tmp_i] = '\0';
            maze[lines++] = tmp;
            tmp = malloc(sizeof(char) * (infos->cols + 1));
            tmp_i = 0;
        } else
            tmp[tmp_i++] = buffer[i];
    }
    maze[lines] = NULL;
    free(tmp);
    return (maze);
}