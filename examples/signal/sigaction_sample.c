#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t unprocessedSig = 0;

void sighandler(int signo);

int main(int argc, char *argv[])
{
    printf("this is pid %d\n", getpid());

    struct sigaction act;

    act.sa_handler = &sighandler;

    sigfillset(&act.sa_mask);
    act.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &act, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("important: kill this process");

    while (1)
    {
        if (unprocessedSig)
        {
            unprocessedSig = 0;
            printf("SIGINT signal occrred.\n");
        }
    }

    return 0;
}

void sighandler(int signo)
{
    if (signo == SIGINT)
    {
        unprocessedSig = 1;
    }
}