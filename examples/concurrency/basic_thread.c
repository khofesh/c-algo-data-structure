#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hola();

int main(int argc, char *argv[])
{
    pthread_t thread;

    pthread_create(&thread, NULL, hola, NULL);

    // block the main thread untill thread is finished
    pthread_join(thread, NULL);

    pthread_exit(NULL);

    return 0;
}

void *hola()
{
    printf("hola mundo!\n");
    return NULL;
}
