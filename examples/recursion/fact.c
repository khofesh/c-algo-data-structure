#include <stdio.h>

/*
 * computing factorials
 */

int factorial(int n);

int main(int argc, char *argv[])
{
    int result = factorial(10);

    printf("factorial result of 10 is: %d\n", result);

    return 0;
}

int factorial(int n)
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
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
