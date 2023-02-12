// Write a program to print a histogram of the frequencies of different characters in its input.

#include <stdio.h>

#define CHARSET 128 // there are 128 ascii characters

int main()
{
    unsigned int c;

    // static declaration makes sure the array elements are initialized to 0
    static int charFrequencies[CHARSET]; 

    while ((c = getchar()) != EOF)
    {
        if (c >= 0 && c < CHARSET)
            ++charFrequencies[c];
    }

    // Numeric Output
    for (int i = 0; i < CHARSET; i++)
    {
        printf("%4c : %4d\n", (i), charFrequencies[i]);
    }

    // Horizontal Histogram Output
    for (int i = 0; i < CHARSET; i++)
    {
        printf("%4c : ", (i));
        for (int j = 0; j < charFrequencies[i]; j++)
        {
            printf("X");
        }
        printf("\n");
    }

}

/// COMPLETE