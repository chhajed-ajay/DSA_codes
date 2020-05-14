#include<stdio.h>
#include<stdlib.h>
int main()
{
    int k,n,i,y,j,t;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        t = a[i];
        j= i-1;
        while(j>=0 && a[j]>t)
        {
            y= a[j+1];
            a[j+1]=a[j];
            a[j]=y;
            j--;
        }
        for(k=0;k<n;k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
    }
    return 0;
}