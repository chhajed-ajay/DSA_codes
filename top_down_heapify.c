#include<stdio.h>
#include<stdlib.h>
void top_down_heapify(int H[], int n, int i)
{
    int l,t;
    while(2*i+2 < n)
    {
        if(H[2*i+1] > H[2*i+2])
        {
            l = 2*i+1;
        }
        else
        {
            l = 2*i+2;
        }
        if(H[i]>H[l])
        {
            // printf("Swapping %d and %d\n",H[i],H[l]);
            t = H[i];
            H[i]=H[l];
            H[l]=t;
            i = l;
        }
        else
        {
            break;
        }
    }
    if(2*i+1 <= n-1 && H[i]>H[2*i+1])
    {
        // printf("single swap\n");
        t = H[i];
        H[i]=H[2*i+1];
        H[2*i+1]= t;
    }
    if(2*i+2 <= n-1 && H[i]>H[2*i+2])
    {
        // printf("single swap\n");
        t = H[i];
        H[i]=H[2*i+2];
        H[2*i+2]= t;
    }
    // printf("Heapify task is completed for %d node.\n",i);
}
int main()
{
    int n, i;
    scanf("%d",&n);
    int *H = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){scanf("%d",&H[i]);}
    for(i=n/2-1;i>=0;i--)
    {
        top_down_heapify(H, n, i);
    }
    for(i=0;i<n;i++){printf("%d ",H[i]);}
    return 0;
}