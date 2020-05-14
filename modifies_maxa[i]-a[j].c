#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int max,n,i,j;
    scanf("%lld",&n);
    long long int *arr=(long long int *)malloc(sizeof(long long int)*n);
    scanf("%lld",&arr[0]);
    for(i=1;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    max =0;i=0;
    for(j=1;j<n;j++)
    {
        if(arr[j]-arr[i]>max)
        {
            max = arr[j]-arr[i];
        }
        if(arr[i]>arr[j])
        {
            i=j;
        }
    }
    printf("maximum difference of two numbers in an array s.t. j>i is '%lld'",max);
    return 0;
}