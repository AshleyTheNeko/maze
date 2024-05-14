#ifndef BONUS_HEADER_H_
#define BONUS_HEADER_H_

#include "common_structs.h"
#include <stdbool.h>

enum map_colors {
    X_COLOR = 1,
    STAR_COLOR,
    O_COLOR,
    V_COLOR
};

status_t init_generation(v2i_t *size, bool perfect, char ***map);
void free_map(char **map, v2i_t *size);
int dig_map(char **map, v2i_t *size);
int special_cases(v2i_t *size);
int curse_final_loop(char **map, v2i_t *size);
int display_map(char **map, v2i_t *size, int ms_wait);
int solve_maze(infos_t *infos);

#endif /* !BONUS_HEADER_H_ */