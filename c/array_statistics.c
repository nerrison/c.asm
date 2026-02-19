#include <stdio.h>
#include <stdlib.h>

/**
 * array_statistics.c
 *
 * Demonstrates:
 *  - Heap memory allocation using malloc/free
 *  - Pointer arithmetic
 *  - Array traversal
 *  - Input validation
 *  - Calculating sum, average, max, min
 *
 * Compilation:
 *  gcc -Wall -Wextra -std=c11 array_statistics.c -o array_statistics
 *
 * Usage:
 *  ./array_statistics
 */

int main(void)
{
    int size;

    /* Ask user for number of elements */
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    /* Allocate heap memory for the array */
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Input numbers into the array with validation */
    int i = 0;
    int num;

    while (i < size)
    {
        printf("Enter number %d: ", i + 1);
        if (scanf("%d", &num) != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n') /* Clear input buffer */
                ;
            continue;
        }

        *(arr + i) = num; /* Store value using pointer arithmetic */
        i++;
    }

    /* Calculate sum */
    int sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }

    /* Calculate average */
    double average = (double)sum / size;

    /* Find maximum and minimum */
    int max = *arr;
    int min = *arr;

    for (i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }

    /* Print results */
    printf("\n=== Array Statistics ===\n");
    printf("Numbers entered: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    /* Free heap memory */
    free(arr);
    arr = NULL;

    return 0;
}
