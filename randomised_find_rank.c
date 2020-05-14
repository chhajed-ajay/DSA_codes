#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void printarray(int arr[], int n);
int partition(int arr[], int i, int j, int pivot)
{
    int l, r, k, t;
    l = i;
    r = j;
    while (l <= r)
    {
        while (l <= r && arr[l] <= pivot)
        {
            l++;
        }
        while (l <= r && arr[r] >= pivot)
        {
            r--;
        }
        if (l <= r)
        {
            t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            l++;
            r--;
        }
    }
    k = l - 1;
    arr[i - 1] = arr[k];
    arr[k] = pivot;
    // printf("Pivot index : %d\n",k);
    // printarray(arr,n);
    return k;
}
int Randomised_rank_find(int arr[], int i, int j, int r)
{
    int t, p, k;
    if (i <= j)
    {
        srand(time(0));
        p = (rand() % (j - i + 1)) + i;
        // p = 1;
        t = arr[i];
        arr[i] = arr[p];
        arr[p] = t;
        k = partition(arr, i + 1, j, arr[i]);
        if (r == j - k + 1)
        {
            return k;
        }
        else if (r < j - k + 1)
        {
            return Randomised_rank_find(arr, k + 1, j, r);
        }
        else
        {
            return Randomised_rank_find(arr, i, k - 1, r - j + k - 1);
        }
    }
    return -1;
}
void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n, i, r;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // printf("\nARRAY : ");
    // printarray(arr, n);
    scanf("%d", &r);
    int j;
    i = 0;
    j = n - 1;
    printf("Rank of %d is %d\n", arr[Randomised_rank_find(arr, 0, n - 1, r)], r);
    return 0;
}
