#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello from hello program\n");

    if (argc > 1)
        printf("Argument = %s\n", argv[1]);

    return 0;
}
