#include "ls.h"

int
main(int argc, char* argv[])
{
        char* dir = get_directory(argc, argv);
        
        if(dir == NULL) {
                exit(-1);
        }

        DIR* dp = opendir(dir);

        if(dp == NULL) {
                exit(-1);
        }

        struct dirent* dirp;
        while((dirp = readdir(dp)) != NULL)
                printf("%s\n", dirp->d_name);

        closedir(dp);
        return(0);
}

char* 
get_directory(int argc, char* argv[])
{
        char* dir;

        if(argc < 2) {
                char buf[DIR_BUFF_SIZE];
                size_t size = DIR_BUFF_SIZE;

                dir = getcwd(buf, size);
        } else {
                dir = argv[DIR_ARG_INDEX];
        }

        return dir;
}
