#include <stdio.h>
#include <stdlib.h>
// priority(node) >= priority(node->parent) :)
// lc = 2i+1 ; rc = 2i + 2 ; parent = (i-1)/2 :|
void top_down_heapify();
void add();
void delete_min();
void bottom_up_heapify();
void print(int *H, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }
}
void bottom_up_heapify(int i ,int *H)
{
    int p,t;
    p = (i-1)/2;
    while(p>=0 && H[p]>H[i])
    {
        t = H[i];
        H[i] = H[p];
        H[p] = t;
        i = p;
        p = (i-1)/2;
    }
    // print(H,n);
}
void top_bottom_heapify(int i, int *H, int n)
{
    int l,t;
    while(2*i + 2 < n)
    {
        if(H[2*i+1] < H[2*i + 2])
        {
            l = 2*i+1;
        }
        else
        {
            l = 2*i + 2;
        }
        if(H[i]>H[l])
        {
         
        t = H[i];
        H[i] = H[l];
        H[l] = t;
        i = l;   
        }
        else
        {
            break;
        }
    }
    if(2*i + 1 < n && H[i]> H[2*i + 1])
    {
        t = H[i];H[i]=H[2*i + 1];H[2*i+1] = t;
    } 
}
void add(int n, int *H)
{
    int x;
    printf("Enter node you want to add : \n");
    scanf("%d",&x);
    H[n++] = x;
    bottom_up_heapify(n-1,H);
    print(H,n);
}
void delete_min(int *H, int n)
{
    H[0]=H[--n];
    // top_down_heapify(0,H,n);
}
void update(int *H, int n)
{
    int x,i;
    scanf("%d",&i);
    printf("Enter the value : \n");
    scanf("%d",&x);
    if(H[i]<x)
    {
        H[i]=x;
        // top_down_heapify(i,H,n);
    }
    else
    {
        H[i]=x;
        bottom_up_heapify(i,H);
    }
}
int main()
{
    int n, i, x;
    scanf("%d", &n);
    int *H = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &H[i]);
    }
    printf("Enter 1 to add a node in binary heap. \n");
    printf("Enter 2 to delete min a node in binary heap. \n");
    printf("Enter 3 to update a node in binary heap. \n");
    scanf("%d", &x);
    if (x == 1)
    {
        add(n, H);
    }
    if (x == 2)
    {
        delete_min(H, n);
    }
    if (x == 3)
    {
    printf("Enter the position you want to update : \n");
        // update(H,n);
    }
    return 0;
}