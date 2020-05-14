#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long int len(long long int n)
{
    long long int l = 0;
    while (n != 0)
    {
        l++;
        n = n / 10;
    }
    return l;
}
int main()
{
    // printf("%d",len(10897286400));
    long long int r, i, j, k, sum, f, l1, l2, m, n, x, y, *a, *b, carry, t, p,**c;
    char *ans = (char *)calloc(1000000, sizeof(char));
    a = (long long int *)malloc(1000000 * sizeof(long long int));
    b = (long long int *)malloc(1000000 * sizeof(long long int));
    c = (long long int **)malloc(100000*sizeof(long long int *));
    for (i = 0; i < 1000; i++)
    {
        c[i] = (long long int *)malloc(100*sizeof(long long int));
        for (r = 0; r < 1000; r++)
        {
            c[i][r] = 0;
        }
    }
    
    scanf("%lld", &n);
    for (i = 0; i < len(n) + 10; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    m = n - 1;
    x = n;
    y = m;
    k = 0;
    f = 0;
    for (t = 1; t <= m; t++)
    {
        l1 = f;
        // l = len(n);
        for (r = 0; r < l1; r++)
        {
            a[r] = 0;
            b[r] = 0;
            a[r] = ans[r] - 48;
            printf("a[%lld] : ans[%lld] = %c\n",r,r,ans[r]);

        }
        y = m - t + 1;
        // x = n - t + 1;
        printf("x : %lld\ny : %lld\n", x, y);
        if(t==1){
        l1 = len(x);}
        l2 = len(y);
        printf("l1 : %lld\nl2 : %lld\n", l1, l2);
        for (i = l1 - 1, j = l2 - 1; i >= 0; i--, j--)
        {
            if(t==1){
            a[i] = x % 10;
            x = x / 10;}
            if (j >= 0)
            {
                b[j] = y % 10;
                // printf("b[%lld] : %lld\n", j, b[j]);
                y = y / 10;
            }
            else
            {
                b[j] = 0;
            }
        }
        for (k = 0; k < l1; k++)
        {
            printf("a[%lld] : %lld\n", k, a[k]);
        }
        for(k=0;k<l2;k++){printf("b[%lld] : %lld\n", k, b[k]);}
        // l2 = l1;
        k = 0;
        for (p = l2 - 1; p >= 0; p--, k++)
        {
            carry = 0;
            f = l1 + l2 - 1 - k;
            for (j = l1 - 1; j >= 0; j--)
            {
                // p = p+1;
                // p = pow(10, k);
                // t = (char)((((int)b[i] - 48)*((int)a[j]-48) + carry)%10)+48;
                // printf("%lld", ((((int)b[i] - 48)*((int)a[j]-48) + carry)%10)+48);
                c[k][f] = (((b[p]) * (a[j]) + carry)) % 10;
                // printf("%lld",c[k][m]);
                f--;
                carry = (((b[p]) * (a[j]) + carry)) / 10;
                if (f != 0)
                {
                    c[k][f - 1] = 0;
                }
                printf("\ncarry : %lld\n", carry);
            }
            if (carry != 0)
            {
                c[k][f] = carry;
            }
        }
        for (p = 0; p < l2; p++)
        {
            for (j = 0; j < l1 + l2; j++)
            {
                printf("%lld", c[p][j]);
            }
            printf("\n");
        }
        carry = 0;
        // long long int *ans2 = (long long int *)calloc(1000000, sizeof(long long int));
        for (p = l1 + l2 - 1; p >= 0; p--)
        {
            sum = 0;
            for (j = 0; j < l2; j++)
            {
                sum += c[j][p];
                // sum = sum + carry;
                // carry = sum/10;
            }
            ans[p] = (sum + carry) % 10 + 48;
            // printf("%lld ",ans[i]);
            carry = (sum + carry) / 10;
        }
        f = 0;
        for (p = 0; p < l1 + l2; p++)
        {
            // if (ans[p] != 0)
            // {
            // for (j = p; j < l1 + l2; j++)
            // {
            // ans2[f] = ans[j];
            // printf("f : %lld ", f);
            f++;
            printf("ans[%lld] : %c\n", p, ans[p]);
            // }
            // return 0;
            // }
        }
        // x = 0;
        for (p = 0; p < f; p++)
        {
            // x += ans[p] * pow(10, f - p - 1);
            a[p] = ans[p];
        }
        // printf("\nupdated x : %lld\n", x);
        // for(p=0;p<l1+l2;i++)
    }
    return 0;
}