// Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input one line at a time.

#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF 80

int getline(char line[], int maxline);

int reverseLine(char in[], char out[], int len);

char *reverse(char s[]);

int main()
{
    int len;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) 
    {
        // Reverse the line using a zippy copy to other array method.
        reverseLine(line, reversed, len);

        // Print the reversed line.
        printf("%s\n", reversed);

        // Reverse the line by returning it.
        printf("%s\n", reverse(line));

        // Reversing the line destructively (overwriting 'line[]' itself) is the same as above, but pointing s[] to t[] instead of returning t[] as char*.
    }

    return 0;
}

// Reverses the character string s without any outside help.
char *reverse(char s[])
{
    // First find the index at end of the string
    int len = 0;
    while (s[len] != '\0' && len < MAXLINE)
        len++;
    
    // Reverse the string
    static char t[MAXLINE];
    int i, j;
    for (j = 0, i = len - 1; i >= 0; i--, j++)
        t[j] = s[i];
    t[j] = '\0';

    return t;
}

// Copies the reverse of input line in[] into output line out[].
int reverseLine(char in[], char out[], int len)
{
    int i, j; 
    for (i = len - 1, j = 0; i >= 0; --i, j++)
    {
        out[j] = in[i];
    }
    out[j] = '\0';

    return 0;
}

int getline(char s[], int lim) 
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}