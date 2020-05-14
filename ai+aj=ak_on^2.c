#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
    // printf("Pivot index : %d\n", k);
    // printarray(arr,n);
    return k;
}
void RQS(int arr[], int i, int j)
{
    int t, p, k;
    if (i < j)
    {
        srand(time(0));
        p = (rand() % (j - i + 1)) + i;
        // p = 1;
        t = arr[i];
        arr[i] = arr[p];
        arr[p] = t;
        k = partition(arr, i + 1, j, arr[i]);
        RQS(arr, i, k - 1);
        RQS(arr, k + 1, j);
        // printarray(arr,n);
    }
}
int binary(int a[], int l, int r, int x, int mid)
{
    if (r >= l)
    {
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] > x)
        {
            return binary(a, l, mid - 1, x, (l + mid - 1) / 2);
        }
        else
        {
            return binary(a, mid + 1, r, x, (r + mid + 1) / 2);
        }
    }
    return 0;
}
int main()
{
    int n, i, x, l, r, t, k;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    RQS(a,0,n-1);
    k=0;
    label:
    // for (k = 0; k < n; k++)
    while(k<n)
    {
        l = 0;
        r = n - 1;
        while (l <= r)
        {
            if (a[l] + a[r] == a[k])
            {
                k++;
                printf("l : %d\nr : %d", l, r);
                goto label;
            }
            else if (a[l] + a[r] < a[k])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        printf("%d is not sum of two numbers\n",a[k]);
        k++;
    }
    return 0;
}