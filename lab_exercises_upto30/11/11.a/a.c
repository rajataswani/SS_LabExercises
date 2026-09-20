#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fd2;

    fd = open("q11.txt",
              O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
              0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    fd2 = dup(fd);

    if (fd2 == -1)
    {
        perror("dup");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("Duplicated FD = %d\n", fd2);

    write(fd, "Using FD1\n", 10);
    write(fd2, "Using FD2\n", 10);

    close(fd);
    close(fd2);

    return 0;
}
