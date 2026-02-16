#include <stdio.h>

/**
 * main - Continuously reads an array and finds two elements that sum to a target
 *
 * Return: 0 on success
 */
int main(void)
{
    int target;
    int size;
    char q;

    while (1)
    {
        printf("Enter 'q' to quit or any other key to continue: ");
        scanf(" %c", &q);

        if (q == 'q' || q == 'Q')
        {
            printf("Exiting.......\n");
            break;
        }

        do
        {
            printf("Input Number Of Elements: ");
            scanf(" %d", &size);

            if (size < 2)
            {
                printf("Invalid size! You must enter at least 2 elements.\n");
            }
        } while (size < 2);

        int array[size];

        for (int i = 0; i < size; i++)
        {
            printf("Element %d: ", i + 1);
            scanf(" %d", &array[i]);
        }

        printf("\nEnter target number: ");
        scanf(" %d", &target);

        int found = 0;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (array[i] + array[j] == target)
                {
                    printf("Match found at Element %d and %d: %d + %d = %d\n",
                           i + 1, j + 1, array[i], array[j], target);
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }

        if (!found)
            printf("No two elements sum to %d\n", target);

        printf("\n");
    }

    return (0);
}
