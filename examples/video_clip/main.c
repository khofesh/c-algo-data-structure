#include <stdio.h>
#include <stdlib.h>

/**
 *
Given a list of video clips start and end times, merge all overlapping
clip intervals
Input: intervals = [[1,4], [10, 11], [4,5]]
Output: [[1,5], [10, 11]]
Explanation: Since intervals [1,4] and [4,5] overlaps, merge them into
[1,5].

https://javascript.plainenglish.io/javascript-algorithms-merge-intervals-leetcode-98da240805bc
 */

void mergeIntervals(int intervals[3][2], int size);
int compare(const void *a, const void *b);
int max(int a, int b);

int main()
{
    /*
    const intervals = [
    [1, 4],
    [10, 11],
    [4, 5],
  ];
    */
    int intervals[3][2] = {
        {1, 4},
        {10, 11},
        {4, 5},
    };
    int intervals2[3][2] = {
        {1, 4},
        {10, 11},
        {4, 6},
    };
    int intervals3[3][2] = {
        {1, 4},
        {10, 11},
        {4, 11},
    };

    printf("first interval:::::::\n");
    /**
     * The first line calculates the size of the entire array (in bytes)
     * divided by the size of one row (also in bytes), which gives you
     * the number of rows in the array. The second line calculates
     * the size of one row (in bytes) divided by the size of one
     * element (also in bytes), which gives you the number of
     * columns in the array.
     */
    int rows = sizeof(intervals) / sizeof(intervals[0]);
    // int cols = sizeof(intervals[0]) / sizeof(int);

    mergeIntervals(intervals, rows);

    printf("second interval:::::::\n");
    int rows2 = sizeof(intervals2) / sizeof(intervals2[0]);
    mergeIntervals(intervals2, rows2);

    printf("third interval:::::::\n");
    int rows3 = sizeof(intervals3) / sizeof(intervals3[0]);
    mergeIntervals(intervals3, rows3);

    return 0;
}

void mergeIntervals(int intervals[3][2], int size)
{
    // Sort intervals by start time
    qsort(intervals, size, sizeof(intervals[0]), compare);

    // Initialize an empty list to store the merged intervals
    int mergedIntervals[size][2];
    int mergedSize = 0;

    // Iterate through the sorted intervals
    for (int i = 0; i < size; i++)
    {
        // If the current interval doesn't overlap with the last interval in the merged list, add it
        if (mergedSize == 0 || intervals[i][0] > mergedIntervals[mergedSize - 1][1])
        {
            mergedIntervals[mergedSize][0] = intervals[i][0];
            mergedIntervals[mergedSize][1] = intervals[i][1];
            mergedSize++;
        }
        // Otherwise, merge the current interval with the last interval in the merged list
        else
        {
            mergedIntervals[mergedSize - 1][1] = max(intervals[i][1], mergedIntervals[mergedSize - 1][1]);
        }
    }
    for (int i = 0; i < mergedSize; i++)
    {
        printf("[%d,%d]\n", mergedIntervals[i][0], mergedIntervals[i][1]);
    }
}

// Compare function for qsort, sorts intervals by start time
int compare(const void *a, const void *b)
{
    int *interval1 = (int *)a;
    int *interval2 = (int *)b;
    return interval1[0] - interval2[0];
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
