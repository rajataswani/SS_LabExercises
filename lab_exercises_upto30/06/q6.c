#include <unistd.h>

int main()
{
    char buffer[100];
    int n;

    n = read(0, buffer, sizeof(buffer));

    if (n == -1)
    {
        return 1;
    }

    write(1, buffer, n);

    return 0;
}
