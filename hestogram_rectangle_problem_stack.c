#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int max,top , i ,n;
    scanf("%d",&n);
    int *R = (int *)malloc(sizeof(int)*n);
    int *s = (int *)malloc(sizeof(int)*n);
    int *B = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&R[i]);
    }
    // Left to Right .......
    top = -1;
    for(i=0;i<n;i++)
    {
        if(top < 0)
        {
            s[++top] = i;
        }
        else if(R[s[top]] < R[i])
        {
            s[++top]= i;
        }
        else
        {
            while(top >= 0 && R[s[top]] >= R[i])
            {
                B[s[top--]] = i;
            }
            s[++top] = i;
        }
    }
    while(top >= 0)
    {
        B[s[top--]] = n;
    }
    max = 0;
    for(i=0;i<n;i++)
    {
        if(max < (B[i] - i - 1)*R[i])
        {
            max = (B[i] - i - 1)*R[i];
        }
    }
    // Right to Left .....
    s = (int *)malloc(sizeof(int)*n);
    top = -1;
    for(i=n-1;i>=0;i--)
    {
        if(top < 0)
        {
            s[++top] = i;
        }
        else if(R[s[top]] < R[i])
        {
            s[++top]= i;
        }
        else
        {
            while(top >= 0 && R[s[top]] >= R[i])
            {
                B[s[top--]] = i;
            }
            s[++top] = i;
        }
    }
    while(top >= 0)
    {
        B[s[top--]] = -1;
    }
    for(i=n-1;i>=0;i--)
    {
        if(max < (i - B[i] - 1)*R[i])
        {
            max = (i - B[i] - 1)*R[i];
        }
    }
    printf("Maximum area of a rectangle : %d\n",max);
    return 0;
}