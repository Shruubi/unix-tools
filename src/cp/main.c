#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char* argv[])
{
        char* src;
        char* dest;

        int src_fd;
        int dest_fd;

        struct stat src_stat;

        if(argc < 3)
                exit(-1);

        src = argv[1];
        dest = argv[2];

        src_fd = open(src, O_RDONLY);
        dest_fd = open(dest, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        /* get the stat of the src file so we can get the read size */
        int stat_res = fstat(src_fd, &src_stat);

        if(stat_res != 0)
                exit(-1);

        size_t src_filesize = src_stat.st_size;

        char* buff = (char*)malloc(src_filesize);
        
        int read_res = read(src_fd, buff, src_filesize);
        int write_res = write(dest_fd, buff, src_filesize);

	if(read_res == -1 || write_res == -1)
		exit(-1);
       
        int err = errno;
        fsync(dest_fd);
        printf("fsync errno: %d\n", err);

        err = errno;

        close(dest_fd);
        close(src_fd);

        free(buff);

        return(0);
}
