#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdup_( char *string)
{
    size_t len = strlen(string)+1;

    char *str = malloc(sizeof(*str) * len);
    if(!str) return NULL;

    for(int i = 0; i < len; i++)
    {
        str[i] = string[i];
    }

    return str;
}

int main(void)
{
    size_t size = 100;

    char s[size];

    printf("enter string: ");
    if(!fgets(s, sizeof(s), stdin))
        return 1;
        

    s[strcspn(s, "\n")] = '\0';


    char *ss = strdup_(s);

    printf("> %s\n",ss);
    printf("> %zu size\n", strlen(ss));
    printf("> %zu - %zu = %zu", size, strlen(ss), size - strlen(ss));

    free(ss);

    return 0;
}