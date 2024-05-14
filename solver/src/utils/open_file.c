#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "common_macros.h"

int file_exists(char const *path)
{
    struct stat stats;

    return (stat(path, &stats) == 0);
}

int get_file_size(char const *path)
{
    struct stat stats;

    stat(path, &stats);
    return (stats.st_size);
}

void *print_error(char *error, int fd)
{
    write(STDERR_FILENO, error, strlen(error));
    close(fd);
    return (NULL);
}

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = get_file_size(filepath);
    char *buffer = calloc(size + 2, sizeof(char));

    if (fd == -1)
        return (NULL);
    if (buffer == NULL)
        return (print_error(MALLOC, fd));
    if (read(fd, buffer, size) == -1)
        return (print_error(READ, fd));
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}