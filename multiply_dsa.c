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
    //long long int c[l2][l1+l2]  ;
    k = 0;
    for (i = l2 - 1; i >= 0; i--, k++)
    {
        carry = 0;
        m = l1 + l2 - 1 - k;
        for (j = l1 - 1; j >= 0; j--)
        {
            // p = pow(10, k);
            // t = (char)((((int)b[i] - 48)*((int)a[j]-48) + carry)%10)+48;
            // printf("%lld", ((((int)b[i] - 48)*((int)a[j]-48) + carry)%10)+48);
            c[k][m] = (((b[i] - 48) * (a[j] - 48) + carry)) % 10;
            // printf("%lld",c[k][m]);
            m--;
            carry = (((b[i] - 48) * (a[j] - 48) + carry)) / 10;
        }
        if (carry != 0)
        {
            c[k][m] = carry;
        }
    }
    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < l1 + l2; j++)
        {
            printf("%lld", c[i][j]);
        }
        printf("\n");
    }
    carry = 0;
    for (i = l1 + l2 - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = 0; j < l2; j++)
        {
            sum += c[j][i];
            // sum = sum + carry;
            // carry = sum/10;
        }
        ans[i] = (sum + carry) % 10;
        // printf("%lld ",ans[i]);
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
        // for(j=i+1;j<l1+l2;j++)
        // {
        //     printf("%lld",ans[j]);
        // }
    }
    return 0;
}