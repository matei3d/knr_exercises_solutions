// Write a program to copy its input to its output, replacing each string of one or more tab with a single tab.

#include <stdio.h>

int main()
{
    int c;
    
    int numTabs = 0;

    while ((c = getchar()) != EOF)
    {   
        if (c == '\t')
            numTabs++;
        else
            numTabs = 0;

        if (numTabs <= 1)
            printf("%c", c);
    }

    printf("\n");
}

/// COMPLETE