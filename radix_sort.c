#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int n, d;
    scanf("%lld %lld", &n, &d);
    long long int B[100], arr[100], i, count_arr[100] = {0}, b = 1;
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    while (d--)
    {
        printf("fdhgd");

        for (i = 0; i < 10; i++)
        {
            count_arr[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            printf("%lld ",count_arr[(arr[i] / b) % 10]);
            count_arr[(arr[i] / b) % 10]++;
        }
        for (i = 0; i < 9; i++)
        {
            count_arr[i + 1] = count_arr[i] + count_arr[i + 1];
        }
        for (i = n-1; i >= 0; i--)
        {
            B[count_arr[(arr[i]/b)%10] - 1] = arr[i];
            count_arr[arr[i]]--;
        }  
        for (i = 0; i < n; i++)
        {
            arr[i] = B[i];
            printf("%lld ",arr[i]);
        }
        b=b*10;
    }
    for (i = 0; i < n; i++)
    {
        printf("%lld ",arr[i]);
    }
    return 0;
}
