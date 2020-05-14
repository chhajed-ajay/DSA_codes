#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    long long int **c, sum = 0, m, i, j, k, l1, l2, carry = 0, p, X, Y, l11, l22;
    char t, *a, *b, *x, *y;
    a = (char *)calloc(1000000, sizeof(char));
    b = (char *)calloc(1000000, sizeof(char));
    scanf("%s", a);
    scanf("%s", b);
    l1 = strlen(a);
    l2 = strlen(b);
    l11 = l1;
    l22 = l2;
    // long long int *ans = (long long int *)calloc(l1 + l2, sizeof(long long int));
    x = (char *)calloc(4 * (l1 / 4 + 1), sizeof(char));
    char *z = (char *)calloc(4 * (l1 / 4 + 1), sizeof(char));
    y = (char *)calloc(4 * (l2 / 4 + 1), sizeof(char));
    c = (long long int **)calloc(l1 + l2 + 1, sizeof(long long int *));
    long long int *ans = (long long int *)calloc(l1 + l2 + 1, sizeof(long long int));
    for (i = 0; i < l2 / 4 + 1; i++)
    {
        c[i] = (long long int *)calloc((l1 + l2) / 4 + 1, sizeof(long long int));
        for (j = 0; j < (l1 + l2) / 4 + 1; j++)
        {
            c[i][j] = 0;
        }
    }
    if (l1 % 4 != 0)
    {
        for (i = 0; i < 4 * (l1 / 4 + 1) - l1; i++)
        {
            x[i] = '0';
            l11++;
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
    for (i = 4 * (l1 / 4 + 1) - 1; i >= 0; i--)
    {
        y[i] = '0';
    }
    for (i = 4 * (l1 / 4 + 1) - 1, j = l2 - 1; j >= 0; i--)
    {
        y[i] = b[j];
        j--;
    }
    for (i = 0; i < 4 * (l1 / 4 + 1); i++)
    {
        printf("%c", y[i]);
    }
    l22 = l11;
    printf("\n");
    printf("l11 : %lld\nl22 : %lld\n", l11, l22);
    for(i=0;i<l22;i++)
    {
        // printf("%c",x[i]);
        z[i] = x[i];
    }
   //printf("\n%d",(z[l22-4]-48)*1000 + (z[l22-3]-48)*100 + (z[l22-2]-48)*10 + (x[l22-1]-48));
    k = 0;
    for (i = l22 - 1; i >= 0; i -= 4, k++)
    {
        Y = (y[i - 3] - 48) * 1000 + (y[i - 2] - 48) * 100 + (y[i - 1] - 48) * 10 + y[i] - 48;
        // X = (z[i - 3] - 48) * 1000 + (x[i - 2] - 48) * 100 + (x[i - 1] - 48) * 10 + x[i] - 48;
        carry = 0;
        m = (l11 + l22) / 4 - 1 - 1 - k;
        for (j = l22-1; j >= 0; j -= 4)
        {
            X = (z[j - 3] - 48) * 1000 + (z[j - 2] - 48) * 100 + (z[j - 1] - 48) * 10 + z[j] - 48;
            printf("X : %lld\nY : %lld\n", X, Y);
            // p = pow(10, k);
            // t = (char)((((int)b[i] - 48)*((int)a[j]-48) + carry)%10)+48;
            // printf("%lld", ((((int)b[i] - 48)*((int)a[j]-48) + carry)%10)+48);
            c[k][m] = ((Y * X + carry)) % 10000;
            // printf("%lld ", c[k][m]);
            m--;
            carry = ((Y * X + carry)) / 10000;
        }
        if (carry != 0)
        {
            c[k][m] = carry;
        }
        printf("\n");
    }
    for (i = 0; i < l2 / 4 + 1; i++)
    {
        for (j = 0; j < (l1 + l2) / 4 + 1; j++)
        {
            printf("%lld ", c[i][j]);
        }
        printf("\n");
    }
    carry = 0;
    k = (l1+l2)/4 + 1;
    for (i = (l1+l2)/4; i >= 0; i--)
    {
        sum = 0;
        for (j = 0; j < l2/4+1; j++)
        {
            sum += c[j][i];
            // sum = sum + carry;
            // carry = sum/10;
        }
        ans[k] = (sum + carry) % 10000;
        k--;
        // printf("%lld ",ans[i]);
        carry = (sum + carry) / 10000;
    }
    printf("\n\n");
    if(l1%4!=0)
    {
    for(i=0;i<(l1+l2)/4+2;i++)
    {
        printf("%lld",ans[i]);
    }
    return 0;}
    for(i=0;i<(l1+l2)/4+2;i++)
    {
        printf("%lld ",ans[i]);
    }
    printf("\n");
    return 0;
}