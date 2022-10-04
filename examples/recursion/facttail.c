#include <stdio.h>
#include <stdlib.h>

/*
 * factorial in tail-recursive manner
 */

int facttail(int n, int a);

int main(int argc, char *argv[])
{
    int result = facttail(4, 1);

    printf("facttail result: %d\n", result);

    return 0;
}

int facttail(int n, int a)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return a;
    }
    else
    {
        return facttail(n - 1, n * a);
    }
}
