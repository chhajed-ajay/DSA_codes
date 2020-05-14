#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long int t, p, i, j, k, l1, l2, carry = 0, *c, n, m;
    char *a, *b, s1[4], s2[4], *x, *y;
    a = (char *)calloc(1000000, sizeof(char));
    b = (char *)calloc(1000000, sizeof(char));
    scanf("%s", a);
    scanf("%s", b);
    l1 = strlen(a);
    l2 = strlen(b);
    x = (char *)calloc(l1 + 4 * (l1 / 4 + 1) - l1, sizeof(char));
    y = (char *)calloc(l2 + 4 * (l2 / 4 + 1) - l2, sizeof(char));
    c = (long long int *)calloc(l1 + l2, sizeof(long long int));
    for (i = 0; i < (l1 / 4 + 1); i++)
    {
        c[i] = 0;
    }
    if (l1 % 4 != 0)
    {
        for (i = 0; i < 4 * (l1 / 4 + 1) - l1; i++)
        {
            x[i] = '0';
        }
        for (i = 4 * (l1 / 4 + 1) - l1, j = 0; j < l1; j++, i++)
        {
            x[i] = a[j];
        }
    }
    else
    {
        for (i = 0; i < l1; i++)
        {
            x[i] = a[i];
        }
    }
    for (i = 0; i < 4 * (l1 / 4 + 1); i++)
    {
        printf("%c", x[i]);
    }
    printf("\n");
    for(i=4*(l1 / 4 + 1)-1;i>=0;i--)
    {
        y[i] = '0';
    }
    for(i=4*(l1 / 4 + 1)-1,j=l2-1;j>=0;i--)
    {
        y[i] = b[j];
        j--;
    }
    // for (i = 0; i < 4 * (l2 / 4 + 1) - l2; i++)
    // {
    //     y[i] = '0';
    // }
    // for (i = 4 * (l2 / 4 + 1) - l2, j = 0; j < l2; j++, i++)
    // {
    //     y[i] = b[j];
    // }
    // else
    // {
    //     for (i = 0; i < l2; i++)
    //     {
    //         y[i] = b[i];
    //     }
    // }
    for (i = 0; i < 4 * (l1 / 4 + 1); i++)
    {
        printf("%c", y[i]);
    }
    printf("\n");
    carry = 0;
    t = l1;
    p = l2;
    if (l1 % 4 != 0)
        t = 4 * (l1 / 4 + 1);
    if (l2 % 4 != 0)
        p = 4 * (l2 / 4 + 1);
    k = (l1 / 4 + 1) - 1;
    for (i = t - 1; i >= 0; i -= 4)
    {
        n = (x[i - 3] - 48) * 1000 + (x[i - 2] - 48) * 100 + (x[i - 1] - 48) * 10 + x[i] - 48;
        m = (y[i - 3] - 48) * 1000 + (y[i - 2] - 48) * 100 + (y[i - 1] - 48) * 10 + y[i] - 48;
        c[k] = (carry + n + m) % 10000;
        printf("n : %lld \n m : %lld \n%lld %lld ", n, m, k, c[k]);
        k--;
        carry = (carry + n + m) / 10000;
    }
    printf("\n");
    for (i = 0; i < (l1 / 4 + 1); i++)
    {
        if(c[i]==0 && i!=0 )
        {printf("0000");
        continue;}
        printf("%lld", c[i]);
    }
    printf("\n");
    return 0;
}