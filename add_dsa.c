#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int max(long long int a, long long int b)
{
    if (a > b)
        return a;
    return b;
}
long long int min(long long int a, long long int b)
{
    if (a > b)
        return b;
    return a;
}
int main()
{
    long long int i, j, k, l1, l2, carry = 0;
    char t, a[1000000], b[1000000], c[1000000];
    scanf("%s", a);
    scanf("%s", b);
    l1 = strlen(a);
    l2 = strlen(b);
    k = 0;
    if (l1 == 1 && l2 == 1)
    {
        printf("%d", (int)a[0] + (int)b[0] - 48 - 48);
        return 0;
    }
    if (l1 > l2)
    {
        for (i = l1 - 1, j = l2 - 1; i >= 0; i--, j--)
        {
            if (j < 0)
            {
                if(carry==1 && i == 0)
                {
                    printf("1");
                }
                t = (char)(((int)a[i] + carry - 48) % 10) + 48;
                c[k] = t;
                k++;
                carry = ((int)a[i] + carry - 48) / 10;
                // printf("%lld",carry);
                continue;
            }
            t = (char)(((int)a[i] + (int)b[j] + carry - 48 - 48) % 10) + 48;
            c[k] = t;
            k++;
            carry = ((int)a[i] + (int)b[j] + carry - 48 - 48) / 10;
            // printf("%lld",carry);
        }
        // printf("%lld",carry);
    }
    else
    {
        for (i = l2 - 1, j = l1 - 1; i >= 0; i--, j--)
        {
            if (j < 0)
            {
                t = (char)(((int)b[i] + carry - 48) % 10) + 48;
                c[k] = t;
                k++;
                carry = ((int)b[i] + carry - 48) / 10;
                continue;
            }
            t = (char)(((int)b[i] + (int)a[j] + carry - 48 - 48) % 10) + 48;
            c[k] = t;
            k++;
            carry = ((int)b[i] + (int)a[j] + carry - 48 - 48) / 10;
        }
    }

    for (i = k; i >= 0; i--)
    {
        printf("%c", c[i]);
    }
    return 0;
}