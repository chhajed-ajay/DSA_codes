#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
1) pehle number ko binary m karna h 
2) 
*/
long long int log_val(char *num, long long int l)
{
    long long int i;
    char *temp=(char *)malloc(sizeof(char)*100000);
    temp[0]='1';
    for(i=1;i<l+1;i++)
    {
        temp[i]='0';
    }
    for(i=0;i<l+1;i++){printf("%c ",temp[i]);}
    for(i=0;i<l+1;i++)
    {
        if(pow(2,l+1-i)<)
    }
    return l-1;
}
int main()
{
    long long int n,i,l;
    char *num=(char *)malloc(sizeof(char)*100000);
    // taking input in binary form .... :)
    scanf("%s",num);
    l = strlen(num);
    printf("log value : %lld",log_val(num, l));
}