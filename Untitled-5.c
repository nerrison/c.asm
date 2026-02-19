#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * isPalindrome - checks if a token is a palindrome
 * @token: string to check
 *
 * Return: void (prints result)
 */
void isPalindrome(char *token)
{
    int left = 0;
    int right = strlen(token) - 1;

    for (; left < right;)
    {
        if (!isalnum(token[left]))
        {
            left++;
            continue;
        }

        if (!isalnum(token[right]))
        {
            right--;
            continue;
        }

        if (tolower(token[left]) != tolower(token[right]))
        {
            printf("%s is not palindrome\n", token);
            return;
        }

        left++;
        right--;
    }

    printf("%s is a palindrome\n", token);
}

/**
 * main - Entry point
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    int capacity = 100;
    char *input = malloc(capacity);
    char *token;

    if (!input)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        return (1);
    }

    printf("\n=====ENTER STRING=====\n");

    while (1)
    {
        printf("\n>> your entry (use ctrl + C to quit)\n> ");

        if (fgets(input, capacity, stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");
        while (token != NULL)
        {
            isPalindrome(token);
            token = strtok(NULL, " ");
        }
    }

    free(input);
    input = NULL;

    return (0);
}