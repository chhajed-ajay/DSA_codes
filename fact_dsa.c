#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long long int l, carry = 0, i, j, k, t, p, n, l1, l2;
    char *a, *b, *d, *c;
    a = (char *)calloc(10, sizeof(char));
    b = (char *)calloc(1000000, sizeof(char));
    scanf("%s", a);
    l = strlen(a);
    strcpy(b, a);
    //d = (char *)calloc(l2, sizeof(char));
    c = (long long int **)calloc(1000000, sizeof(long long int *));
    // for(i=0;i<l;i++)
    // {
    //     a[i]='0';
    // }
    if (a[l - 1] != '0')
    {
        a[l - 1] = a[l - 1] - 1;
        // printf("%s",a);
        // return 0;
        //printf("%c",b[l-1]);
    }
    else
    {
        for (i = l; i > 0; i--)
        {
            if (a[i - 1] != '0')
            {
                a[i - 1] = a[i - 1] - 1;
                //             printf("%c",a[i-1]);
                break;
            }
            a[i - 1] = '9';
            //           printf("%c",a[i-1]);
        }
        l1 = strlen(b);
        l2 = strlen(a);
        k = 0;
        while (a[0] != '0' && a[1] != '0')
        {
            k = 0;
            l1 = strlen(b);
            l2 = strlen(a);
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
            b = itoa(c);
            if (a[l2 - 1] != '0')
            {
                a[l2 - 1] = a[l2 - 1] - 1;
                // printf("%s",a);
                // return 0;
                //printf("%c",b[l-1]);
            }
            else
            {
                for (i = l2; i > 0; i--)
                {
                    if (a[i - 1] != '0')
                    {
                        a[i - 1] = a[i - 1] - 1;
                        //             printf("%c",a[i-1]);
                        break;
                    }
                    a[i - 1] = '9';
                    //           printf("%c",a[i-1]);
                }
            }
        }
        for (i = 0; i < l1; i++)
        {
            printf("%lld ", c[i]);
        }
            return 0;
    }