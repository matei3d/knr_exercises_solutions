// Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for entab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>
#define MAXLINE 1024 // Character buffer
#define TABLENGTH 8  // Default tab length in most systems

int getline(char line[], int maxline);

char *entab(char s[], int len, int tabLength);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%s\n", entab(line, len, TABLENGTH));
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

char *entab(char s[], int len, int tabLength)
{
    static char out[MAXLINE];

    // Entab to new array and return
    int i;     // Current index of s[]
    int j = 0; // Current index of out[]
    int k;     // Tab offset within out[]
    for (i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            int toTabStop = tabLength - (i % tabLength); // Number of chars till next tab stop.
            for (k = 0; k < toTabStop && s[i + k] == ' '; k++); 
            // Checking if it's blank all the way to next stop.
            if (k == toTabStop) 
            {
                out[j++] = '\\';
                out[j++] = 't';
                //out[j++] = '\t';
                i += toTabStop - 1;
            }
            else
            {
                out[j++] = s[i];
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