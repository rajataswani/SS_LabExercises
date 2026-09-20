#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child exiting...\n");
        return 0;
    }
    else
    {
        printf("Parent PID = %d\n", getpid());
        printf("Child PID  = %d\n", pid);

        sleep(30);
    }

    return 0;
}
