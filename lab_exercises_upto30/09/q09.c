#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &st) == -1)
    {
        printf("Error: cannot get file information\n");
        return 1;
    }

    printf("Inode number          : %lu\n", st.st_ino);
    printf("Number of hard links  : %lu\n", st.st_nlink);
    printf("UID                   : %u\n", st.st_uid);
    printf("GID                   : %u\n", st.st_gid);
    printf("File size             : %ld bytes\n", st.st_size);
    printf("Block size            : %ld bytes\n", st.st_blksize);
    printf("Number of blocks      : %ld\n", st.st_blocks);
    printf("Last access time      : %ld\n", st.st_atime);
    printf("Last modification     : %ld\n", st.st_mtime);
    printf("Last status change    : %ld\n", st.st_ctime);

    return 0;
}
