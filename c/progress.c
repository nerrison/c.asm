#include <stdio.h>
#include <unistd.h>

#define MAX_PROGRESS 100
#define WIDTH 20
#define GREEN "\033[32m"
#define RSET "\033[0m"

int main(void)
{
    for(int i = 0; i<=MAX_PROGRESS; i++)
    {
        int percent = i;
        int filled = (percent * WIDTH)/MAX_PROGRESS;

        printf("\r[");
        for(int j = 0; j < filled; j++) printf(GREEN "#");

        for(int j = filled; j <WIDTH; j++) printf(RSET "-");

        printf("] %d%%", percent);

        fflush(stdout);
        usleep(500000);
    }
    printf("\nDone\n");
    return 0;
}