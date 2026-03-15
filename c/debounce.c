#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBOUNCE_LIMIT 2
#define SAMPLE 5
#define MODULO 2

int button_pressed(void)
{
    return rand() % MODULO;
}

int debounce(int raw_Rs)
{
    static int stable_state = 0;
    static int count = 0;

    if(raw_Rs != stable_state){
        count++;

        if(count >= DEBOUNCE_LIMIT){
        stable_state = raw_Rs;
        count = 0;
        }
    }else{
        count =0;
    }

    return stable_state;
}


int main(void)
{
    srand(time(NULL));

    for(int i = 0; i < SAMPLE; i++)
    {

        int raw_R = button_pressed();
        int clean = debounce(raw_R);

        printf("> Raw %d   > Clean %d\n", raw_R, clean);
    }

    return 0;
}