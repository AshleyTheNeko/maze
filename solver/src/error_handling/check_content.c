#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "common_macros.h"
#include "common_structs.h"

int is_ascii(char *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n') {
            write(STDERR_FILENO, ASCII, strlen(ASCII));
            return (ERROR);
        }
    }
    return (SUCCESS);
}

int find_first_line(const char *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n')
            return (i);
    }
    return (size);
}

int check_line(int i, char c, int first, int *line)
{
    int next;

    if (c == '\n' || c == '\0') {
        *line += 1;
        next = (i - *line) / *line;
        if (next != first) {
            write(STDERR_FILENO, LINES, strlen(LINES));
            return (ERROR);
        }
    }
    return (SUCCESS);
}

int check_size(char *buffer, int size)
{
    int first = find_first_line(buffer, size);
    int line = 0;

    for (int i = 0; i <= size; i++) {
        if (check_line(i + 1, buffer[i], first, &line) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}