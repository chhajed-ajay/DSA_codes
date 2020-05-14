#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int digit(long long int n)
{
    long long int c=0;
    while(n!=0)
    {
        c++;
        n=n/10;
    }
    return c;
}
char *multiply(char *a, char *b)
{
    long long int **c, sum = 0, m, i, j, k, l1, l2, carry = 0, p;
    char t;
    l1 = strlen(a);
    l2 = strlen(b);
    c = (long long int **)calloc(l2, sizeof(long long int *));
    char *ans = (char *)calloc(l1 + l2, sizeof(char));
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
        ans[i] = (sum + carry) % 10 + 48;
        carry = (sum + carry) / 10;
    }
    return ans;
}
char *power(long long int x,long long int n)
{
    long long int k,j,i=0,d=digit(x);
    char *y=(char *)malloc(sizeof(char)*100000);
    char *z=(char *)malloc(sizeof(char)*100000);
    char *str=(char *)malloc(sizeof(char)*100000);
    // itoa(x, z, 10);
    while(x!=0)
    {
        z[d-i-1]=x%10 + 48;
        i++;
        x=x/10;
    }
    strcpy(y,"1");
    while(n>0)
    {
        if(n%2==1)
        {
            y = multiply(y,z);
        }
        z=multiply(z,z);
        n=n/2;
    }
    for(i=0;i<strlen(y);i++)
    {
        if(y[i]!='0')
        {
            break;
        }
    }
    k=0;
    for(j=i;j<strlen(y);j++)
    {
        str[k]=y[j];
        k++;
    }
    return str;
}
int main()
{
    long long int x,n;
    scanf("%lld %lld",&x,&n);
    printf("%s",power(x,n));
    // printf("%s",multiply("543454356345","2332423"));
    return 0;
}