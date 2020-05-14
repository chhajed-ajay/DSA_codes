#include<stdio.h>
int main()
{
    int x,n;scanf("%d %d",&x,&n);
    int y=1;
    while (n>0)
    {
        if(n%2==1)
        {
            y=y*x;
        }
        x=x*x;
        n=n/2;
    }
    printf("%d",y);
    return 0;
}