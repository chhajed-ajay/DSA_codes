#include <stdio.h>
#include <string.h>
int main()
{
    char t[100], p[10];
    long long int i, j, x, n, m, N, y;
    scanf("%s %s", t, p);
    n = strlen(t);
    m = strlen(p);
    N = p[0] - 48;
    y = t[0] - 48;
    x = 2;
    for (j = 1; j < m; j++)
    {
        x = x * 2;
        N = N * 2 + p[j] - 48;
        y = y * 2 + t[j] - 48;
    }
    printf("N : %lld \ny : %lld\n", N, y);
    if (N == y)
    {
        printf("There is a match....\n\n");
        return 0;
    }
    for (i = 1; i < n - m; i++)
    {
        y = (y * 2 + t[i + m - 1] - 48 - x *( t[i - 1] - 48))%p;
        printf("%lld ",y);
        if (N == y)
        {
            printf("There is a match....\n\n");
            return 0;
        }
    }
    return 0;
}