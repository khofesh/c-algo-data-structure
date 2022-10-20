#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// https://leetcode.com/problems/happy-number/

int square_sum(int n);
bool is_happy(int n);

int main(void)
{
    bool result = is_happy(19);
    printf("result: %d\n", result);

    return EXIT_SUCCESS;
}

int square_sum(int n)
{
    int r = 0;
    while (n)
    {
        int tmp = n % 10;
        r += tmp * tmp;
        n /= 10;
    }

    return r;
}

bool is_happy(int n)
{
    int slow = n;
    int fast = n;

    do
    {
        slow = square_sum(slow);
        fast = square_sum(fast);
        fast = square_sum(fast);
    } while (slow != fast);

    if (slow == 1)
    {
        return true;
    }

    return false;
}
