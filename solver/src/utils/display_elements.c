#include "common_macros.h"
#include "dante_solve.h"
#include <stdio.h>
#include <unistd.h>

void print_usage(void)
{
    puts("USAGE :");
    puts(COMMANDS);
    puts("DESCRIPTION :");
    puts(USAGE);
}

void print_line(char **maze, int i, int cols)
{
    for (int j = 0; j < cols; j++) {
        if (maze[i][j] == 'V')
            maze[i][j] = '*';
    }
    write(STDOUT_FILENO, maze[i], cols);
}

void print_maze(char **maze, int cols, int lines)
{

    for (int i = 0; i < lines; i++) {
        print_line(maze, i, cols);
        if (maze[i + 1] != NULL)
            write(STDOUT_FILENO, "\n", 1);
    }
}