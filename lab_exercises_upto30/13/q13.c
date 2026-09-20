#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    result = select(STDIN_FILENO + 1,
                    &readfds,
                    NULL,
                    NULL,
                    &timeout);

    if (result == -1)
    {
        perror("select");
        return 1;
    }

    if (result == 0)
    {
        printf("Timeout: No input received.\n");
    }
    else if (FD_ISSET(STDIN_FILENO, &readfds))
    {
        printf("Input is available on STDIN.\n");

        char buffer[100];
        int n = read(STDIN_FILENO, buffer, sizeof(buffer));

        if (n > 0)
        {
            write(STDOUT_FILENO, buffer, n);
        }
    }

    return 0;
}
