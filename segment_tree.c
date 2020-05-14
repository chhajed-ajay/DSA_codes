#include<stdio.h>
#include<stdlib.h>
void bulid(int a[], int ST[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {   
        ST[n-1+i] = i;
    }
    for(i=n-2;i>-1;i--)
    {
        if(a[ST[2*i+1]]>a[ST[2*i+2]])
        {
            ST[i] = ST[2*i+2];
        }
        else
        {
            ST[i] = ST[2*i+1];
        }
    }
}
void update(int a[],int i,int x,int ST[])
{
    a[i]=x;
    i = ((n-1+i)-1)/2;
    while(i>=0)
    {
        if(a[ST[2*i+1]]>a[ST[2*i+2]])
        {
            ST[i] = ST[2*i+2];
        }
        else
        {
            ST[i] = ST[2*i+1];
        }
        i = (i-1)/2; // further upward parent node
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    int *ST=(int *)malloc(sizeof(int)*3*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bulid(a, ST, n);
    return 0;
}