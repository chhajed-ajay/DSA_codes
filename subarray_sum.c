#include <stdio.h>
long long int a[100];
int bin(int low, int high, int m)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == m)
        {
        }
        if (a[mid] > m)
        {
            high = low - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return mid;
}
int main()
{
    long long int low, high, mid, r, l, i, j, k, n, s = 0;
    scanf("%lld %lld", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (k == a[i])
        {
            printf("This sum is the sum of a subarray.\n");
            return 0;
        }
        a[i] = s + a[i];
        s = a[i];
    }
    low = 0;
    high = n - 1;
        for (i = 0; i < n; i++)
    {
        printf("%lld ", a[i]);
    }
    if(a[1]==k)
    {
            printf("This sum is the sum of a subarray.\n");
return 0;
    }
        r = n - 1;
    l = 0;
    while (l <= r)
    {
        mid = bin(l, r, k);
    // printf("mid : %lld\n", mid);

        if (a[mid] - a[l] == k || a[mid + 1] - a[l] == k)
        {
            printf("This sum is the sum of a subarray.\n");
            return 0;
        }
        l++;
    }
    printf("There is no such sub-array\n");
    return 2;
}