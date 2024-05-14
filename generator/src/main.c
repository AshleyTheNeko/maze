#include "dante_gen.h"
#include "common_macros.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    v2i_t size = {0};
    bool perfect = false;

    if (argc < 3)
        return (84);
    if (argc > 4)
        return (84);
    size.x = atoi(argv[1]);
    size.y = atoi(argv[2]);
    if (size.y <= 0 || size.x <= 0)
        return (84);
    if (special_cases(&size))
        return (0);
    if (argc == 4)
        if (!strcmp(argv[3], "perfect"))
            perfect = true;
    return (init_generation(&size, perfect));
}