#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int count = 0;
    char filename[100];

    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            sprintf(filename, "file_%d_%d.txt", getpid(), count++);

            fd = creat(filename, 0644);

            if (fd == -1)
            {
                perror("creat");
                return 1;
            }

            printf("Created %s with FD %d\n", filename, fd);
        }

        sleep(1);
    }

    return 0;
}
