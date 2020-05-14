#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int n,i,j,max;
    scanf("%lld",&n);
    long long int *a=(long long int *)malloc(sizeof(long long int)*n);
    long long int *p=(long long int *)malloc(sizeof(long long int)*n);
    for(i=0;i<n;i++){scanf("%lld",&a[i]);}
    p[0]=0;
    max = 0;
    for(i=1;i<n+1;i++)
    {
        p[i]=p[i-1]+a[i-1]; // in this case an additional array is consuming space . :( :|
    }
    for(j=1;j<n+1;j++)
    {
        if(p[j]-p[i]>max)
        {
            max=p[j]-p[i];
        }
        if(p[j]<p[i])
        {
            i=j;
        }
    }
    printf("maximum sum of a subarray is : %lld\n",max);
    return 0;
}