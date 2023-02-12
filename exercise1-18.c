// Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF 80

int getline(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) 
    {
        // Remove trailing blanks and tabs and delete blank lines entirely.
        for (int i = len - 1; i >= 0 && (line[i]==' '||line[i]=='\t'||line[i]=='\n'); --i)
            line[i] = '\0';

        // Print the edited line.
        printf("%s", line);
        
        // Create new input line.
        printf("\n");
    }

    return 0;
}

int getline(char s[], int lim) 
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// COMPLETE