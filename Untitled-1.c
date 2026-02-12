#include <stdio.h>

int largestNum(int *num, int count)
{
    if (!num || count == 0) return -1;

    int max = num[0];
    for (int i = 1; i < count; i++)
    {
        if (num[i] > max)
            max = num[i];
    }
    return max;
}

int smallestNum(int *num, int count)
{
    if (!num || count == 0) return -1;

    int min = num[0];
    for (int i = 1; i < count; i++)
    {
        if (num[i] < min)
            min = num[i];
    }
    return min;
}

int average(int *num, int count)
{
    int total=0;

    if(!num || count == 0) return -1;

    for (int i =0; i <count; i++)
    {
        total += num[i];
    }

    int avr = total/count;

    return avr;
}

int main(void)
{
    int num[10];
    int count = 0;

    printf("Enter at most 5 numbers (0 to stop):\n");

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
        return 0;
    }

    int result = largestNum(num, count);
    int minRes = smallestNum(num, count);

    printf("Smallest number: %d\n", minRes);
    printf("Largest number: %d\n", result);
    printf("Number of items entered: %d\n", count);
    printf("Average: %d\n", average(num, count));


    return 0;
}
