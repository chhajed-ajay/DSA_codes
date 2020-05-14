#include <stdio.h>
long long int gcd(long long int a, long long int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
long long int findGCD(long long int arr[], long long int n) 
{ 
    long long int result = arr[0]; 
    for (long long int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 
int main()
{
    long long int i,n,k;
    scanf("%lld %lld",&n,&k);
    long long int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long int m=findGCD(a,n);
    for(i=k;i>=0;i--)
    {
        if(i%m==0)
        {
            printf("%lld",i);
            return 0;
        }
    }
    return 0;
}
