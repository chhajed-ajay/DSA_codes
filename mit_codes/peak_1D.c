#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int low = 0,high = n-1,mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid-1]<=a[mid] && a[mid+1]<=a[mid])
        {
            printf("PEAK NUMBER : %d\n",a[mid]);
            return 0;
        }
        else if(a[mid]<a[mid-1])
        {
            high = mid-1;
        }
        else if(a[mid-1]<a[mid])
        {
            low = mid+1;
        }
    }
    return 0;
}