#include <stdio.h>
void merge(int arr[], int i, int k, int j)
{
    int l = i, r = k + 1, p = 0;
    int b[100];
    while (l <= k && r <= j)
    {
        if (arr[l] <= arr[r])
        {
            b[p++] = arr[l++];
        }
        else
        {
            b[p++] = arr[r++];
        }
    }
    while (l <= k)
    {
        b[p++] = arr[l++];
    }
    while (r <= j)
    {
        b[p++] = arr[r++];
    }
    p = 0;
    l = i;
    while (l <= j)
    {
        arr[l++] = b[p++];
    }
}
void mergesort(int arr[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int i,n,arr[] = {13, 11, 122, 5, 6, 2}; 
    n = 6;
    mergesort(arr, 0, n-1);
    printf("Sorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}