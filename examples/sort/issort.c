/*
 * insertion sort
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZ 6

typedef int (*fptrCompare)(const void *, const void *);

int issort(void *data, int size, int esize, fptrCompare compare);
static void print_idata(const int *array, int size);
static int compare_int(const void *int1, const void *int2);

int main(int argc, char *argv[])
{
    int iarray[10] = {
        0,
        5,
        1,
        7,
        3,
        2,
        8,
        9,
        4,
        6,
    };

    int size = 10;

    fprintf(stdout, "Before issort\n");
    print_idata(iarray, size);

    if (issort(iarray, size, sizeof(int), compare_int) != 0)
    {
        return 1;
    }

    fprintf(stdout, "After issort\n");
    print_idata(iarray, size);

    return 0;
}

int issort(void *data, int size, int esize, fptrCompare compare)
{
    char *a = data;
    void *key = (char *)malloc(esize);
    int i, j;

    if (key == NULL)
    {
        return -1;
    }

    for (j = 1; j < size; j++)
    {
        memcpy(key, &a[j * esize], esize);
        i = j - 1;

        while (i >= 0 && compare(&a[i * esize], key) > 0)
        {
            memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
            i--;
        }

        memcpy(&a[(i + 1) * esize], key, esize);
    }

    free(key);

    return 0;
}

/**
 * @brief print array of integers
 *
 * @param array
 * @param size
 */
static void print_idata(const int *array, int size)
{

    int i;

    for (i = 0; i < size; i++)
        fprintf(stdout, "A[%02d]=%d\n", i, array[i]);

    return;
}

/**
 * @brief compare 2 integers
 *
 * @param int1
 * @param int2
 * @return int
 */
static int compare_int(const void *int1, const void *int2)
{

    if (*(const int *)int1 > *(const int *)int2)
    {
        return 1;
    }
    else if (*(const int *)int1 < *(const int *)int2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
