#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int iseven(char *n)
{
    int l = strlen(n);
    if((n[l-1]-48)%2==0)
    {
        return 1;
    }
    return 0;
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
    printf("\n");
    // for (i = 0; i < l1 + l2; i++)
    // {
    //     if (ans[i] != 0)
    //     {
    //         for (j = i; j < l1 + l2; j++)
    //         {
    //             printf("%lld", ans[j]);
    //         }
    //         return 0;
    //     }
    // }
    return ans;
}

char* div2(char *string)
{
    char *s,*a ;
    // string = (char *)malloc(sizeof(char) * 100000);
    s = (char *)malloc(sizeof(char) * 100000);
    // scanf("%s", string); 
    a = (char *)malloc(sizeof(char) * 100000);
    int k,n, i, len = strlen(string), carry = 0,j;
    n = (string[0] - 48) / 2;
    for (i = 0; i < len - 1; i++)
    {
        s[i] = n + 48 ;
        n = (((string[i] - 48) % 2) * 10 + string[i + 1] - 48) / 2 ;
    }
    s[i] = n + 48;
    int l = strlen(s);
    printf("l : %d\n",l);
    // printf("%c",s[0]);
    for(i=0;i<l;i++)
    {
        while(s[i]=='0')
        {
            i++;
        }
        break;
    }
    if(i==l)
    {return "0";
    }
    k = 0;
    for(j=i;j<l;j++)
    {
        a[k] = s[j];
        // printf("%c",a[k]);
        k++;
    }
    a[k]='\0';
    // return ")";
    printf("a : %s",a);
     return a;
}
char *power(char *x,char *n)
{
    if(n[0]=='0')
    {
        return "1";
    }
    // else if(n%2==0)
    else if(iseven(n))
    {
        // printf("\n%s*%s",multiply(x,x),div2(n));
        return power(multiply(x,x),div2(n));
    }
    else
    {
        // printf("\n%s*%s*%s",x,multiply(x,x),div2(n));
        return multiply(x,power(multiply(x,x),div2(n)));
    }    
}
int main()
{
    char *x = (char *)malloc(sizeof(char)*100000);
    char *n = (char *)malloc(sizeof(char)*100000);
    char *c = (char *)malloc(sizeof(char)*1000000);

    scanf("%s %s",x,n);
     printf("%s",multiply("12345","9876623"));
    printf("\n%s",div2("128"));
    // div2("128");
    strcpy(c,power(x,n));
    int i;
    for(i =0 ;i < strlen(c);i++)
    {if(c[i]!='0')
    break;}
    printf("%s",c+i);
    return 0;
}