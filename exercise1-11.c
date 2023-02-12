// Write a program that prints its input one word per line

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
                printf("\n");
            state = OUT;
        }
        else
        {
            printf("%c", c);
            state = IN;
        }
    }
}

/// COMPLETE
