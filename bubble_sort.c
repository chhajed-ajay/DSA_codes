#include <stdio.h>
#include <stdlib.h>
void swap(long long int *a, long long int *b)
{
    long long int t;
    t = *a;
    *a=*b;
    *b = t;
}
int main()
{
    long long int n, d, j;
    scanf("%lld", &n);
    long long int B[100], arr[100], i, count_arr[100] = {0}, b = 1;
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                // d = arr[i];
                // arr[i]=arr[j];
                // arr[j]=d;
                swap(&arr[j],&arr[j+1]);
            }
        }
        // printf("%lld ",arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%lld ",arr[i]);
    }
    return 0;
}
