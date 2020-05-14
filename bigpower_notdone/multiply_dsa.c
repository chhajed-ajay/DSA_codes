#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    long long int **c, sum = 0, m, i, j, k, l1, l2, carry = 0, p;
    char t, *a, *b;
    a = (char *)calloc(1000000, sizeof(char));
    b = (char *)calloc(1000000, sizeof(char));
    scanf("%s", a);
    scanf("%s", b);
    l1 = strlen(a);
    l2 = strlen(b);
    c = (long long int **)calloc(l2, sizeof(long long int *));
    long long int *ans = (long long int *)calloc(l1 + l2, sizeof(long long int));
    for (i = 0; i < l2; i++)
    {
        c[i] = (long long int *)calloc(l1 + l2, sizeof(long long int));
        for (j = 0; j < l1 + l2; j++)
        {
            c[i][j] = 0;
        }
    }
    k = 0;
    for (i = l2 - 1; i >= 0; i--, k++)
    {
        carry = 0;
        m = l1 + l2 - 1 - k;
        for (j = l1 - 1; j >= 0; j--)
        {
            c[k][m] = (((b[i] - 48) * (a[j] - 48) + carry)) % 10;
            m--;
            carry = (((b[i] - 48) * (a[j] - 48) + carry)) / 10;
        }
        if (carry != 0)
        {
            c[k][m] = carry;
        }
    }
    carry = 0;
    for (i = l1 + l2 - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = 0; j < l2; j++)
        {
            sum += c[j][i];
        }
        ans[i] = (sum + carry) % 10;
        carry = (sum + carry) / 10;
    }
    printf("\n");
    for (i = 0; i < l1 + l2; i++)
    {
        if (ans[i] != 0)
        {
            for (j = i; j < l1 + l2; j++)
            {
                printf("%lld", ans[j]);
            }
            return 0;
        }
    }
    return 0;
}