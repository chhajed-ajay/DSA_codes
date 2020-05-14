#include <stdio.h>
#define BIG 100000

int main()
{
    int Fact[BIG] = {1};
    int n, i, j, NOD = 1, c = 0;

    scanf("%d", &n);

    for(i = 2; i <= n; i++)
    {
        for(j = 0; j < NOD; j++)
        {
            Fact[j] = Fact[j] * i;
            Fact[j] = Fact[j] + c;
            c = Fact[j]/10;
            Fact[j] = Fact[j]%10;
        }
        while(c)
        {
            Fact[NOD] = c%10;
            c = c/10;
            NOD++;
        }
    }
    // printf("%d\n", NOD);

    for(i = NOD - 1; i >= 0; i--)
        printf("%d", Fact[i]);
    return 0;
}