#include "dante_solve.h"
#include "common_macros.h"
#include <string.h>

int main(int ac, char **av)
{
    char *buffer;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_usage();
        return (0);
    }
    if (check_rights(av[1], ac) == ERROR)
        return (EXIT_ERROR);
    buffer = open_file(av[1]);
    if (check_file(buffer) == ERROR || buffer == NULL)
        return (EXIT_ERROR);
    return (solve_maze(buffer));
}