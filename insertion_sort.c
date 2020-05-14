#include<stdio.h>
int main()
{
    long long int n, i, j, k;
    scanf("%lld",&n);
    long long int b[n],arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    // void insertionSort(int arr[], int n) 
// { 
    int  key; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
// } 
printf("SORTED : \n");
for(i=0;i<n;i++)
    {
        printf("%lld ", arr[i]);
    }
    
}