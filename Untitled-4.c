#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * main - Reads a string from the user, counts vowels, and prints positions
 * Return: 0 on success
 */
int main(void)
{
    //char vowel [] ={'a','A','e','E','i','I','o','O','u','U'};
    //char vowels[] = {'a','e','i','o','u'};

    char input[100];
    char clean[100];

    printf("==========ENTER WORDS==========\n");

    while (1)
    {
        int isfound = 0;
        int len = 0;
        int k = 0;

        printf("\n");
        printf(">> input (use ctrl + c to exit)\n");
        printf("> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        /* Remove non-alphabetic characters */
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (isalpha((unsigned char)input[i]))
            {
                clean[k++] = input[i];
            }
        }

        clean[k] = '\0';

        if (strlen(clean) == 0)
        {
            printf(">> invalid input! enter strings\n");
            continue;
        }

        len = strlen(clean);
        printf(">> length (space ignored): %d \n", len);

        //int num = sizeof(vowel)/sizeof(vowel[0]);

        for (int i = 0; clean[i] != '\0'; i++)
        {
            char c = tolower((unsigned char)clean[i]);

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                isfound++;
                printf("   *Found %c at letter(%d)\n", clean[i], i + 1);
            }

            /*
            for(int j = 0; j < num; j++)
            {
                if(clean[i] == vowel[j])
                {
                    isfound += 1;
                    printf("    *Found %c in (%s) at letter(%d).\n",
                           vowel[j], input, i + 1);
                }
            }
            */

            /*
            char c = tolower(clean[i]);

            for(int j = 0; j < num; j++)
            {
                if(c == vowels[j])
                {
                    isfound++;
                    printf("   *Found %c at letter(%d)\n", clean[i], i + 1);
                }
            }
            */
        }

        if (isfound == 0)
            printf("No vowel found for (%s)\n", input);
    }

    return (0);
}
