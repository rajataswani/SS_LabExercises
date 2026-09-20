#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int fd2 = 10;

    fd = open("q11_dup2.txt",
              O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
              0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (dup2(fd, fd2) == -1)
    {
        perror("dup2");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("New FD = %d\n", fd2);

    write(fd, "Written by FD1\n", 15);
    write(fd2, "Written by FD2\n", 15);

    close(fd);
    close(fd2);

    return 0;
}
