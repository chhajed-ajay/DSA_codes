#include<stdio.h>
#include<string.h>
int main()
{
    char t[100], p[10];
    long long int i, j, n, m;
    scanf("%s %s",t,p);
    n = strlen(t);m = strlen(p);
    for(i=0;i<n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(t[i+j]!=p[j])break;
        }
        if(j == m)
        {
            printf("There is a match.....\n");
            return 0;
        }
    }
    return 0;
}