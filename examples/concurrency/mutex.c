#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NTHREADS 10

pthread_mutex_t lock;

int counter = 0;

void *func1(void *data);

int main(int argc, char *argv[])
{
    pthread_t thread_id[NTHREADS];
    int values[NTHREADS];

    for (int i = 0; i < NTHREADS; i++)
    {
        values[i] = i;

        pthread_create(&thread_id[i], NULL, func1, &values[i]);
    }

    for (int j = 0; j < NTHREADS; j++)
    {
        pthread_join(thread_id[j], NULL);
        pthread_exit(&thread_id[j]);
    }

    return 0;
}

void *func1(void *data)
{
    pthread_mutex_lock(&lock);

    int *x = (int *)data;

    counter++;

    printf("message is %d, thread id = %ld modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %ld read the counter %d\n", *x, pthread_self(), counter);

    pthread_mutex_unlock(&lock);

    return NULL;
}
