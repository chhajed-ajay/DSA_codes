#include <stdio.h>
int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int b[n], arr[n], i, count_arr[10]={0};
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        count_arr[arr[i]]+=1;
    }
    for(i=0;i<9;i++)
    {
        count_arr[i+1] = count_arr[i] + count_arr[i+1];
    }
    // for(i=0;i<10;i++)
    // {
    //     printf("%lld ",count_arr[i]);
    // }
    for(i=0;i<n;i++)
    {
        b[count_arr[arr[i]]-1]=arr[i];
        count_arr[arr[i]]--;
    }
     for(i=0;i<n;i++)
    {
        printf("%lld ",b[i]);
    }
}