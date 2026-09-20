#include <stdio.h>
#include <sched.h>

int main()
{
    int min, max;

    min = sched_get_priority_min(SCHED_FIFO);
    max = sched_get_priority_max(SCHED_FIFO);

    printf("Minimum real-time priority = %d\n", min);
    printf("Maximum real-time priority = %d\n", max);

    return 0;
}
