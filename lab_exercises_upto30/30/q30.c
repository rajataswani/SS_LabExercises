#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    pid_t pid;
    time_t now;
    struct tm *t;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
        return 0;

    setsid();

    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // printf("Daemon Process must have been created successfully");
    while (1)
    {
        now = time(NULL);
        t = localtime(&now);

        /*
         * Example task:
         * Execute when current minute is 30.
         */
        if (t->tm_min == 30)
        {
            int fd = open("/tmp/daemon_output.txt",
                          O_WRONLY | O_CREAT | O_APPEND, 0666);

            if (fd != -1)
            {
                dprintf(fd, "Daemon executed task.\n");
                close(fd);
            }

            sleep(60);
        }

        sleep(10);
    }

    return 0;
}
