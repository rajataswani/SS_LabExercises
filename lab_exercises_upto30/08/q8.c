#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char ch;
    char line[1024];
    int pos = 0;
    int n;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    while ((n = read(fd, &ch, 1)) > 0)
    {
        if (ch == '\n')
        {
            write(1, line, pos);
            write(1, "\n", 1);
            pos = 0;
        }
        else
        {
            if (pos < sizeof(line) - 1)
            {
                line[pos++] = ch;
            }
        }
    }

    /* Print final line if file doesn't end with '\n' */
    if (pos > 0)
    {
        write(1, line, pos);
        write(1, "\n", 1);
    }

    close(fd);

    return 0;
}
