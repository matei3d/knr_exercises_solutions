// Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 10

int main()
{
    int c, len, state;

    // static declaration makes sure the array elements are initialized to 0
    static int wordLengths[MAXLEN]; 

    len = 0;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
                ++wordLengths[len - 1];
            len = 0;
            state = OUT;
        }
        else
        {
            if (len < MAXLEN)
                ++len;
            state = IN;
        }
    }

    // Numeric Output
    for (int i = 0; i < MAXLEN - 1; i++)
    {
        printf("%4d : %4d\n", (i+1), wordLengths[i]);
    }
    
    printf("%4d+: %4d\n", (MAXLEN), wordLengths[MAXLEN - 1]);

    // Horizontal Histogram Output
    for (int i = 0; i < MAXLEN; i++)
    {
        if (i == MAXLEN - 1)
            printf("%3d+: ", (i+1));
        else
            printf("%3d : ", (i+1));

        for (int j = 0; j < wordLengths[i]; j++)
        {
            printf("X");
        }
        printf("\n");
    }

}

/// COMPLETE