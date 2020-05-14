#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n, i;
    scanf("%d",&n);
    int a[n], b[n], s[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int top = -1;
    for(i=0;i<n;i++)
    {
        if(top < 0) // if stack is empty 
        {
            s[++top] = i; 
        }
        else if (a[s[top]] < a[i]) // if the last element in the stack is less than current no.
        {
            s[++top] = i;
        }
        else
        {
            while(top >= 0 && a[s[top]]>=a[i])
            {
                b[s[top--]]=i;
            } 
            s[++top] = i;  
        }
    }
    while(top >= 0)
    {
        b[s[top--]]= -1;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}