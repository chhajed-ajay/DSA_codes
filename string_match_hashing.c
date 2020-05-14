#include <stdio.h>
#include <string.h>
int main()
{
    long long int x, y, N, i, j, k, n, m, hash_arr[10];
    for (i = 0; i < 10; i++)
    {
        hash_arr[i] = 0;
    }
    char t[100], p[10];
    scanf("%s %s", t, p);
    n = strlen(t);
    m = strlen(p);
    printf("len(t) : %lld\n", n);
    N = p[0] - 48;
    y = t[0] - 48;
    x = 2;
    for (j = 1; j < m; j++)
    {
        x = x * 2;
        N = N * 2 + p[j] - 48;
        y = y * 2 + t[j] - 48;
    }
    if (N == y)
    {
        printf("We find the match of the pattern %s at 0..\n", p);
    }
    for (i = 1; i < n - m + 2; i++)
    {
        if (N == y)
        {
            printf("We find the match of the pattern %s at %lld..\n\n", p, i);
        }
        hash_arr[y / 3] = y;
        printf("%lld : %lld\n", y / 3, y);
        y = y * 2 + t[i + m - 1] - 48 - x * (t[i - 1] - 48);
    }
    // for(i=0;i<6;i++)
    // {
    //     printf("%lld",hash_arr[i]);
    // }
    return 0;
}