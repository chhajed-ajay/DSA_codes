#include<stdio.h>
long long int power(int x, long long int n)
{
    if(n==0)return 1;
    else if (n%2==0)
    {
        return power(x*x,n/2);
    }
    else
    {
        return x*power(x*x,n/2);
    }
}
int main()
{
    long long int n,x;
    scanf("%lld %lld",&x,&n);
    printf("%lld",power(x, n));
    return 0;
}