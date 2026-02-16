#include <stdio.h>

/**
 * largestNum - Returns the largest number in an array
 * @num: Pointer to the array of integers
 * @count: Number of elements in the array
 *
 * Return: Largest integer, or -1 if array is empty or NULL
 */
int largestNum(int *num, int count)
{
    if (!num || count == 0)
        return (-1);

    int max = num[0];

    for (int i = 1; i < count; i++)
    {
        if (num[i] > max)
            max = num[i];
    }

    return (max);
}

/**
 * smallestNum - Returns the smallest number in an array
 * @num: Pointer to the array of integers
 * @count: Number of elements in the array
 *
 * Return: Smallest integer, or -1 if array is empty or NULL
 */
int smallestNum(int *num, int count)
{
    if (!num || count == 0)
        return (-1);

    int min = num[0];

    for (int i = 1; i < count; i++)
    {
        if (num[i] < min)
            min = num[i];
    }

    return (min);
}

/**
 * average - Returns the average of an array of integers
 * @num: Pointer to the array of integers
 * @count: Number of elements in the array
 *
 * Return: Average as an integer, or -1 if array is empty or NULL
 */
int average(int *num, int count)
{
    if (!num || count == 0)
        return (-1);

    int total = 0;

    for (int i = 0; i < count; i++)
        total += num[i];

    return (total / count);
}

/**
 * main - Reads integers from user, finds min, max, and average
 *
 * Return: 0 on success
 */
int main(void)
{
    int num[10];
    int count = 0;

    printf("Enter at most 10 numbers (0 to stop):\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);

        if (num[i] == 0)
            break;

        count++;
    }

    if (count == 0)
    {
        printf("No numbers entered.\n");
        return (0);
    }

    int maxRes = largestNum(num, count);
    int minRes = smallestNum(num, count);

    printf("Smallest number: %d\n", minRes);
    printf("Largest number: %d\n", maxRes);
    printf("Number of items entered: %d\n", count);
    printf("Average: %d\n", average(num, count));

    return (0);
}
