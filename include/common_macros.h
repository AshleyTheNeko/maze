#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

static const int DIRECTIONS_SIZE = 4;
#define UNUSED __attribute__((unused))
#define COMMANDS "   solver/solver maze.txt\n"
#define USAGE "    a maze solver, takes in parameter a maze stored in a file"
#define PERMISSIONS "Permission denied\n"
#define READ "Read error\n"
#define AMOUNT "Not the right amount of arguments\n"
#define PERMISSION "Permission denied\n"
#define EMPTY "Your file is empty\n"
#define ASCII "Your file must only contain ascii characters\n"
#define END "Your file must not finish by a return of line character\n"
#define LINES "Your maze must be rectangular\n"
#define MALLOC "Malloc failed\n"

#endif /* !COMMON_MACROS_H_ */