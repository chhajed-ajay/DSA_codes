#include<stdio.h>
#include<string.h>
int main()
{
    long long int cx=0,cy=0,l,n,i,j,k;
    char s[100];
    scanf("%s",s);
    l = strlen(s);
    i = 0;
    j = l-1;
    while(i<=j)
    {
        while(s[i++]!='0')
        {
        }
        cx+=1;
        while(s[j--]!='1')
        {
        }
        cy+=1;
    }
    if(cx==cy)
    {
        printf("0's and 1's are equal on opposite sides at index : %lld\n",i-1);
    }
    return 0;
}