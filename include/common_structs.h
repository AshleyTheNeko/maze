#ifndef SOLVE
#define SOLVE

typedef struct {
    int x;
    int y;
} v2i_t;

typedef struct maze_infos {
    int size;
    int cols;
    int lines;
    char **maze;
} infos_t;

typedef enum return_status_code {
    ERROR,
    SUCCESS,
    EXIT_OK = 0,
    EXIT_ERROR = 84
} status_t;

#endif