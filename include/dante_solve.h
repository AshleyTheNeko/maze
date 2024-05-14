#ifndef DANTE
#define DANTE

#include "common_structs.h"

//-----------------------------ERRORS folder------------------------------//
int check_file(char *buffer);
int check_rights(char const *path, int ac);
int check_size(char *buffer, int size);
int is_ascii(char *buffer, int size);

//-----------------------------EXECUTION folder------------------------------//
infos_t *init_infos(char *buffer);
int execute_algorithm(infos_t *infos, int i, int j);
int solve_maze(char *buffer);
void free_maze(infos_t *infos);

//-----------------------------UTILS folder------------------------------//
void print_usage(void);
void print_maze(char **maze, int cols, int lines);
char *open_file(char const *filepath);
int file_exists(char const *path);
char **convert_map(char *buffer, infos_t *infos, int size);

#endif