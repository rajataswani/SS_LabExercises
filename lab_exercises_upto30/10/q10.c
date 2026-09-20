#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    off_t pos;

    char data1[] = "1234567890";
    char data2[] = "ABCDEFGHIJ";

    fd = open("q10_file.txt",
              O_RDWR | O_CREAT | O_TRUNC,
              0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (write(fd, data1, 10) != 10)
    {
        perror("write");
        close(fd);
        return 1;
    }

    pos = lseek(fd, 10, SEEK_CUR);

    if (pos == (off_t)-1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("lseek returned position: %ld\n", (long)pos);

    if (write(fd, data2, 10) != 10)
    {
        perror("write");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
