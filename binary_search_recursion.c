#include<stdio.h>
int binary(int a[],int l, int r,int x, int mid)
{
    if(r>=l){
    if(a[mid] == x)
    {
        return 1;
    }
    if(a[mid]>x)
    {
        return binary(  a, l, mid-1,x,(l+mid -1)/2);
    }
    else
    {
        return binary(  a, mid + 1,r,x,(r+mid +1)/2);
    }
    }
    return 0;
}
int main()
{
    long long int a[]={1,2,3,4,5,5,6,6},l=0,r=7,mid=3;

    if(binary(a,l,r,0,mid))
    {
        printf("found");
    }
    else
    {
        printf("not found");
    }
    return 0;
}