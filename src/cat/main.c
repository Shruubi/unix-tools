#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char* argv[])
{
        char* filename;
        struct stat file_struct;
        int fd;

        if(argc < 2)
                exit(-1);

        filename = argv[1];

        fd = open(filename, O_RDONLY);

        int res = fstat(fd, &file_struct);

        if(res != 0)
                exit(-1);

        size_t filesize = file_struct.st_size;

        char* buff = (char*)malloc(filesize);

        read(fd, buff, filesize);

        for(int i = 0; i < filesize; i++) {
                printf("%c", buff[i]);
        }

        free(buff);
        close(fd);
        return(0);
}
