#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * sum_of_number - Converts a string to an integer and adds it to sum
 * @input: The input string
 * @sum: Pointer to the running sum
 */
void sum_of_number(char *input, int *sum)
{
    char *endptr;
    long number = strtol(input, &endptr, 10);

    if (*endptr != '\0')
    {
        printf("Invalid input: %s\n", input);
        return;
    }

    if (number > INT_MAX || number < INT_MIN)
    {
        printf("Number out of range: %ld\n", number);
        return;
    }

    int result = *sum + (int)number;
    printf("Sum of %d + %d = %d\n", *sum, (int)number, result);
    *sum = result;
}

/**
 * main - Continuously reads numbers and keeps a running sum
 *
 * Return: 0 on success
 */
int main(void)
{
    int sum = 0;
    char input[100];

    printf("===Enter digit(s)===\n");

    while (1)
    {
        printf("\n");
        printf("input: ");
        scanf(" %s", input);

        if (*input == 'q' && *(input + 1) == '\0')
        {
            printf("Exiting......\n");
            break;
        }

        sum_of_number(input, &sum);
    }

    return (0);
}
