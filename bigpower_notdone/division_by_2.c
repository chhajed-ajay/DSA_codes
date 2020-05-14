#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *s, *string;
    string = (char *)malloc(sizeof(char) * 100000);
    s = (char *)malloc(sizeof(char) * 100000);
    scanf("%s", string);
    int n, i, len = strlen(string), carry = 0;
    n = (string[0] - 48) / 2;
    for (i = 0; i < len - 1; i++)
    {
        s[i] = n + 48;
        n = (((string[i] - 48) % 2) * 10 + string[i + 1] - 48) / 2;
    }
    s[i] = n + 48;
    printf("%s", s);
    return 0;
}