#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int flags;

    fd = open("q12.txt", O_RDWR | O_APPEND);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    switch (flags & O_ACCMODE)
    {
        case O_RDONLY:
            printf("Opening mode: READ ONLY\n");
            break;

        case O_WRONLY:
            printf("Opening mode: WRITE ONLY\n");
            break;

        case O_RDWR:
            printf("Opening mode: READ WRITE\n");
            break;

        default:
            printf("Unknown access mode\n");
    }

    if (flags & O_APPEND)
        printf("O_APPEND is enabled\n");

    close(fd);

    return 0;
}
