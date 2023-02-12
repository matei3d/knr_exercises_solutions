// Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main()
{
    int c;
    
    int numBlanks = 0; 
    int numTabs = 0;
    int numLines = 0; 

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            numLines++;
        else if (c == '\t')
            numTabs++;
        else if (c == ' ')
            numBlanks++;
    }

    printf("Blanks: %d\tTabs: %d\tLines: %d", numBlanks, numTabs, numLines);
}

/// COMPLETE