#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record
{
    int id;
    char name[20];
};

int main()
{
    int fd;
    struct record records[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    struct flock lock;
    int record_no = 1;

    fd = open("records.dat", O_RDWR | O_CREAT, 0666);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, records, sizeof(records));

    /* Lock record 1 */
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_no * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        return 1;
    }

    printf("Record %d locked.\n", record_no);

    /* Access record */
    lseek(fd, record_no * sizeof(struct record), SEEK_SET);

    struct record r;

    read(fd, &r, sizeof(r));

    printf("ID   : %d\n", r.id);
    printf("Name : %s\n", r.name);

    /* Unlock */
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Record unlocked.\n");

    close(fd);

    return 0;
}
