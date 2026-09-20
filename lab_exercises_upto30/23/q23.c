#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child PID = %d\n", getpid());

        sleep(5);

        printf("Parent PID after parent exits = %d\n", getppid());
    }
    else
    {
        printf("Parent exiting...\n");
        return 0;
    }

    return 0;
}
