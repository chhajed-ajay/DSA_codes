#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    long long int data;
    struct node *link;
};
int search(long long int i, long long int x, long long int l, char *s1, char *s2, struct node *hash_arr[])
{
    printf("l : %lld\n", l);
    long long int k = 0, j;
    struct node *temp;
    if (hash_arr[x] != NULL)
    {
        temp = hash_arr[x];
        m:
        while (temp != NULL)
        {
            k = 0;
            j = temp->data;
            while (k < l)
            {
                if (s2[j] != s1[i])
                {
                    temp = temp->link;
                    goto m;
                }
                else
                {
                    k++;
                }
                j++;i++;
            }
            if(k==l)
            {
                printf("string fnd\n");
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
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
void append(long long int k, long long int i, struct node *hash_arr[]) // function for storing the no. of inputs
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

int min(int n, int m)
{
    if (n > m)
        return m;
    return n;
}
int main()
{
    long long int c[100], y, x, count = 0, i, j, z, k, n, m, l1, l2, l = 1, p = pow(10, 6) + 7;
    char *s1 = (char *)malloc(sizeof(char) * 10000);
    char *s2 = (char *)malloc(sizeof(char) * 10000);
    scanf("%s %s", s1, s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    long long int ll = min(l1, l2);
    printf("minimum length : %lld\n", ll);
label:

    while (l <= ll)
    {
        struct node *hash_arr[10000] = {NULL};
        printf("\n\nlength : %lld\n\n", l);
        // APPending KA KAAM challu
        y = s2[0] - 48;
        x = 2;
        for (j = 1; j < l; j++)
        {
            x = x * 2;
            y = (y * 2 + s2[j] - 48) % p;
        }
        for (i = 1; i < l2 - l + 2; i++)
        {
            printf("APPEND : %lld at %lld\n", i - 1, y % p);
            append(i - 1, y % p, hash_arr);
            y = (y * 2 + s2[i + l - 1] - 48 - x * (s2[i - 1] - 48)) % p;
        }
        printf("\nappend ka kaam khatam\n");
        y = s1[0] - 48;
        x = 2;
        for (j = 1; j < l; j++)
        {
            x = x * 2;
            y = (y * 2 + s1[j] - 48) % p;
        }
        count = 0;
        for (i = 1; i < l1 - l + 2; i++)
        {
            count++;
            if (search(i - 1, y, l, s1, s2, hash_arr) == 1)
            {
                l++;
                goto label;
            }
            y = (y * 2 + s1[i + l - 1] - 48 - x * (s1[i - 1] - 48)) % p;
            printf("count : %lld\n", count);
        }
        if (count == l1 - l + 1)
        {
            printf("long common : %lld", l - 1);
            return 0;
        }
    }
l:
    printf("\nLongest common substring : %lld\n", l - 1);
    return 0;
}