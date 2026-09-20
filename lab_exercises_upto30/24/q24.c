#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child[3];

    for (int i = 0; i < 3; i++)
    {
        child[i] = fork();

        if (child[i] == 0)
        {
            printf("Child %d: PID = %d\n", i + 1, getpid());
            sleep(i + 1);
            return 0;
        }
    }

    printf("Parent waiting for child 2: PID = %d\n", child[1]);

    waitpid(child[1], NULL, 0);

    printf("Child 2 finished.\n");

    return 0;
}
