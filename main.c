#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct timeval time;
    gettimeofday(&time, 0);
    int t1 = time.tv_usec;

    usleep(1000);
    gettimeofday(&time, 0);
    printf("%ld\n", time.tv_usec - t1);
    return 0;
}
