#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int priority;

    errno = 0;

    priority = nice(0);

    if (errno != 0)
    {
        perror("nice");
        return 1;
    }

    printf("Current nice value = %d\n", priority);

    printf("Process PID = %d\n", getpid());

    while (1)
    {
        sleep(10);
    }

    return 0;
}
