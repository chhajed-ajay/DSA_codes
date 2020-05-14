#include <stdio.h>
int main()
{
    long long int found, n, i, j, k;
    scanf("%lld", &n);
    long long int low, mid, high, a[n], x;
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    low = 0;
    high = n - 1;
    printf("Enter the number you want to search in the array : ");
    scanf("%lld", &x);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
        {
            found = 1;
            // return 0;
        }
        if (x > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (found == 1)
    {
        printf("\nNumber %lld found in the array", x);
    }
    else
    {
        printf("\nNot found :( ");
    }
    return 0;
}