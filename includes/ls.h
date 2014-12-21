#include <sys/types.h>

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define DIR_BUFF_SIZE 256
#define DIR_ARG_INDEX 1

char* get_directory(int argc, char* argv[]);
