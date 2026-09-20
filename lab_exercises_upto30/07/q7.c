#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char buffer[1024];
    int n;

    if (argc != 3)
    {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    fd1 = open(argv[1], O_RDONLY);

    if (fd1 == -1)
    {
        perror("open source");
        return 1;
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    bool flag = false;
    if (fd2 == -1)
    {
        perror("open destination");
        close(fd1);
        return 1;
    }
  

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
	    flag = true;
        if (write(fd2, buffer, n) != n)
        {
            perror("write");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    if(flag) printf("Successfully copied the content from the source file to the destiation file");


    close(fd1);
    close(fd2);

    return 0;
}
