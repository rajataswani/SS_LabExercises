#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("q4_file.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File opened successfully. FD = %d\n", fd);

    close(fd);

    fd = open("q4_file.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd == -1)
    {
        perror("O_EXCL test");
    }
    else
    {
        printf("File created exclusively. FD = %d\n", fd);
        close(fd);
    }

    return 0;
}
