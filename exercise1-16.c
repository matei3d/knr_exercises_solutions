// Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;    // Current line length
    int max;    // Maximum line length seen so far 
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) 
    {
        if (len > max) 
        {
            max = len;
            copy(longest, line);
        }

        printf("This line's length was of %d characters\n", len);
        printf("This line's contents: \n");
        printf("%s", line);
    }

    if (max > 0) // there was a line
        printf("%s", longest);

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) // (why are these different from the signature declaration at the start? I guess the variable names used don't matter?)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';    // The null character is used to signal that a string has terminated. 
                    // It is used by stdio's printf to detect the end of a string in a character array.
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') // Interesting assignment + comparison happening here.
        ++i;
}

/// COMPLETE