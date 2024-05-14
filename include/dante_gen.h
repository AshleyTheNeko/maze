#ifndef DANTE
#define DANTE

#include <stdbool.h>
#include "common_structs.h"

status_t init_generation(v2i_t *size, bool perfect);
void print_map(char **map, v2i_t *size);
void free_map(char **map, v2i_t *size);
void dig_map(char **map, v2i_t *size);
int special_cases(v2i_t *size);

#endif /* !DANTE */
