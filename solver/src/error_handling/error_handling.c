#include "common_macros.h"
#include "dante_solve.h"
#include "common_structs.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int check_rights(char const *path, int ac)
{
    if (ac != 2) {
        write(STDERR_FILENO, AMOUNT, strlen(AMOUNT));
        return (ERROR);
    }
    if (file_exists(path) == 0) {
        write(STDERR_FILENO, PERMISSION, strlen(PERMISSION));
        return (ERROR);
    }
    return (SUCCESS);
}

int check_maze_content(char *buffer)
{
    int size = strlen(buffer);

    if (is_ascii(buffer, size) == ERROR)
        return (ERROR);
    if (buffer[size - 1] == '\n') {
        write(STDERR_FILENO, END, strlen(END));
        return (ERROR);
    }
    if (check_size(buffer, size) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int check_file(char *buffer)
{
    if (buffer[0] == '\0') {
        free(buffer);
        write(STDERR_FILENO, EMPTY, strlen(EMPTY));
        return (ERROR);
    }
    if (check_maze_content(buffer) == ERROR) {
        free(buffer);
        return (ERROR);
    }
    return (SUCCESS);
}