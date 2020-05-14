#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
void printarray(long long int arr[], long long int n);
long long int partition(long long int arr[],long long  int i, long long int j, long long int pivot)
{
    long long int l, r, k, t;
    l = i;
    r = j;
    while (l <= r)
    {
        while (l <= r && arr[l] <= pivot)
            {l++;}
        while (l <= r && arr[r] >= pivot)
            {r--;}
        if (l <= r)
        {
            t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            l++;r--;
        }
    }
    k = l - 1;
    arr[i - 1] = arr[k];
    arr[k] = pivot;
    // printf("Pivot index : %d\n",k);
    // printarray(arr,n);
    return k;
}
void RQS(long long int arr[], long long int i, long long int j)
{
    long long int t, p, k;
    if (i < j)
    {   srand(time(0));
        p = (rand()%(j-i+1)) + i;
        // p = 1;
        t = arr[i];
        arr[i] = arr[p];
        arr[p] = t;
        k = partition(arr,i+1,j, arr[i]);
        RQS(arr, i,k - 1);
        RQS(arr, k + 1, j);
        // printarray(arr,n);
    }
}
void printarray(long long int arr[], long long int n)
{
    long long int i;
    for (i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}
int main()
{
    long long int n,i;
    scanf("%lld",&n);
    long long int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    printf("\nARRAY : ");
    printarray(arr, n);
    long long int  j;
    i = 0;
    j = n-1;
    RQS(arr,i, j);
    printf("\nSORTED ARRAY : ");
    printarray(arr, n);
    return 0;
}
