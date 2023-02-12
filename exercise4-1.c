// Write a function strrindex(s, t) which returns the position of the rightmost occurence of t in s, or -1 if there is none.

#include <stdio.h>
#define MAXLINE 1000    /* Maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strlength(char s[]);

char pattern[] = "ould";    /* Pattern do be searched for */

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;
    

    while (getline(line, MAXLINE) > 0)
    {
        int n = strindex(line, pattern);
        if (n >= 0) {
            printf("%s", line);
            found++;
        }
        printf("%i", found);
    }
        
    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strlength:   return the length of string s[], -1 if there is none */
int strlength(char s[])
{
    int count;

    for (count = 0; s[count] != '\0'; count++);

    return count;
}

/* strindex:    return the rightmost position of t in s, -1 if there is none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for ( i = strlength(s); i >= 0; --i) // for each character in the s array
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) // iterate to the end as long as current char s[j] matches with current t[k] and we havent reached the end of t[]
            printf("[inloop]");
        if (k > 0 && t[k] == '\0') // character matches greater than 0 AND reached end of pattern string t[].
            return i;
    }
    return -1;
}