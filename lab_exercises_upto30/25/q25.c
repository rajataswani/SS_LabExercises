#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    execl("./hello.out", "hello.out", argv[1], NULL);

    perror("execl");

    return 1;
}
