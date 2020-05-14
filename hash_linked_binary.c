#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct node
{
    long long int data;
    struct node *link;
} * hash_arr[100];
void search(long long int x,long long int i,long long int m)
{
    struct node *temp;
    int count = 0;
    if(hash_arr[i]!=NULL)
    {
        temp = hash_arr[i];
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                printf("The pattern %lld is found at position %lld in text ... \n",x,m);
                break;
            }
            temp = temp->link;
        }
        // printf("There is no such pattern like at position %lld (number = %lld) in text...\n",m,x);
    }
}
void display(struct node *root) // function for displaying the nodes
{
    struct node *temp;
    temp = root;               // stroing the root in temp
    while (temp->link != NULL) // NULL is the adress of last variable, thus we are
    // using the loop upto that
    {
        printf("%lld-->", temp->data); // printing the values
        temp = temp->link;             // storing adress of next node to the current one
    }
    printf("%lld-->NULL\n", temp->data); // printing the last element
}
void append(long long int k, long long int i) // function for storing the no. of inputs
{
    // struct node * root;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    // scanf("%lld", &temp->data); // taking input of that data which we have to append
    temp->link = NULL;       // making the adress stored in node pointed by temp as NULL
    if (hash_arr[i] == NULL) // if root dont have any adress or link
    {
        hash_arr[i] = temp; // assigning the address pointed by temp to root
    }
    else
    {
        struct node *p;
        p = hash_arr[i];
        while (p->link != NULL)
        {
            p = p->link; // address which is pointed by p , stored in p
        }
        p->link = temp;
    }
    display(hash_arr[i]);
}

int main()
{
    char text[100];
    printf("Enter the text : \n");
    scanf("%s", text);
    long long int p = pow(10, 5), n, l, i, x, j, y, k, *hash, m;
    scanf("%lld %lld", &n, &l);
    hash = (long long int *)malloc(n * sizeof(long long int));
    for (i = 0; i < n; i++)
    {
        k = 0;
        scanf("%lld", &hash[i]);
        m = hash[i];
        for (j = 0; j < l; j++)
        {
            k += m % 10 * pow(2, j);
            m = m / 10;
        }
        printf("%lld ", k);
        append(k, k % p);
    }
    y = text[0] - 48;
    x = 2;
    for (j = 1; j < l; j++)
    {
        x = x * 2;
        // N = N * 2 + p[j] - 48;
        y = y * 2 + text[j] - 48;
    }
    for (i = 1; i < strlen(text) - l + 2; i++)
    {
        printf("%lld\n",y);
        search(y,y%p,i);
        // hash_arr[y / 3] = y;
        // printf("%lld : %lld\n", y, y);
        y = y * 2 + text[i + l - 1] - 48 - x * (text[i - 1] - 48);
    }

    // for (i = 0; i < strlen(t) - l; i += 1)
    // {
    // }

    return 0;
}