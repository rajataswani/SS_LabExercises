#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2)
    {
        const char msg[] = "Usage: ./q14 <filename>\n";
        write(2, msg, sizeof(msg) - 1);
        return 1;
    }

    if (lstat(argv[1], &st) == -1)
    {
        const char msg[] = "Error: cannot access file\n";
        write(2, msg, sizeof(msg) - 1);
        return 1;
    }

    if (S_ISREG(st.st_mode))
    {
        const char msg[] = "Regular file\n";
        write(1, msg, sizeof(msg) - 1);
    }
    else if (S_ISDIR(st.st_mode))
    {
        const char msg[] = "Directory\n";
        write(1, msg, sizeof(msg) - 1);
    }
    else if (S_ISFIFO(st.st_mode))
    {
        const char msg[] = "FIFO\n";
        write(1, msg, sizeof(msg) - 1);
    }
    else if (S_ISLNK(st.st_mode))
    {
        const char msg[] = "Symbolic link\n";
        write(1, msg, sizeof(msg) - 1);
    }
    else if (S_ISCHR(st.st_mode))
    {
        const char msg[] = "Character device\n";
        write(1, msg, sizeof(msg) - 1);
    }
    else if (S_ISBLK(st.st_mode))
    {
        const char msg[] = "Block device\n";
        write(1, msg, sizeof(msg) - 1);
    }
    else if (S_ISSOCK(st.st_mode))
    {
        const char msg[] = "Socket\n";
        write(1, msg, sizeof(msg) - 1);
    }

    return 0;
}
