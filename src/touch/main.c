#include "touch.h"

int
main(int argc, char* argv[])
{
        char* pathname;
        int fd;

        if(argc < 2)
                exit(-1);

        pathname = argv[1];
        if(pathname == NULL)
                exit(-1);

        fd = open(pathname, O_CREAT);
        int err = errno;
        if(err != 0)
                exit(-1);

        close(fd);
        return(0);
}
