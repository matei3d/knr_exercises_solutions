// Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>
#define MAXLINE 1024    // Character buffer
#define TABLENGTH 8     // Default tab length in most systems

int getline(char line[], int maxline);

char *detab(char s[], int len, int tabLength);


int main() 
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%s\n", detab(line, len, TABLENGTH));
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
        
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

char *detab(char s[], int len, int tabLength)
{
    static char out[MAXLINE];

    // Detab to new array and return
    int i;      // Current index of s[]
    int j = 0;  // Current index of out[]
    int k;      // Tab offset within out[]
    for (i = 0; i < len; i++) 
    {
        if (s[i] == '\t')
        {
            int toTabStop = tabLength - (j % tabLength);  // Number of chars till next tab stop.
            // printf("%i chars till next tab stop.\n", toTabStop);
            for (k = 0; k < toTabStop; k++)
            {
                out[j++] = ' ';
            }
        }
        else 
        {
            out[j++] = s[i];
        }
    }
    out[j] = '\0';

    return out;
}

// COMPLETED