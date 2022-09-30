#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func(void *x);

int main(int argc, char *argv[])
{
    pthread_t th;
    pthread_create(&th, NULL, func, (void *)100);

    void *ret_from_thread;
    int ri;
    pthread_join(th, &ret_from_thread);
    ri = (int)ret_from_thread;

    printf("outside thread, which returned %d\n", ri);

    pthread_exit(NULL);

    return 0;
}

void *func(void *x)
{
    int xi = (int)x;

    printf("inside thread; x = %d\n", xi);

    return (void *)(xi + 123);
}
