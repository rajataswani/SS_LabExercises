#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("PID = %d\n", getpid());

    while (1)
    {
        printf("Running...\n");
        sleep(2);
    }

    return 0;
}
