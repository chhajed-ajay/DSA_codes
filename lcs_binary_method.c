#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void display(struct node *root);
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
void display(struct node *root) // function for displaying the nodes
{
    struct node *temp;
    temp = root;               // stroing the root in temp
    while (temp->link != NULL) // NULL is the adress of last variable, thus we are
    // using the loop upto that
    {
        printf("%d-->", temp->data); // printing the values
        temp = temp->link;             // storing adress of next node to the current one
    }
    printf("%d-->NULL\n", temp->data); // printing the last element
}
int min(int n, int m)
{
    return n > m ? m : n;
}

int search(int i, int x, int l, char *s1, char *s2, struct node *hash_arr[])
{
    int k = 0, j;
    struct node *temp;
    if (hash_arr[x] != NULL)
    {
        temp = hash_arr[x];
        j = temp->data;
        while (temp->link != NULL)
        {
            k = 0;
            while (k < l)
            {
                if (s2[i++] == s1[j++])
                {
                    k++;
                }
            }
            if (k == l)
            {
                printf("length : %d is found",l);
                return 1;
            }
            else
            {
                temp = temp->link;
            }
        }
    }
    return 0;
}
int find_substring(char *s1, char *s2, int len, struct node *hash_arr[])
{
    int p = 10000007;
    int i, y, x, j, l1 = strlen(s1), l2 = strlen(s2), check = 0;
    y = s1[0] - 48;
    x = 2;
    // APPEND FUCNTION
    for (j = 1; j < len; j++)
    {
        x = x * 2;
        y = (y * 2 + s1[j] - 48) % p;
    }
    for (i = 1; i < l1 - len+2; i++)
    {
        append(i - 1, y % p, hash_arr);
        y = (y * 2 + s1[i + len - 1] - 48 - x * (s1[i - 1] - 48)) % p;
    }
    // SEARCH FUNCTION
    y = s2[0] - 48;
    x = 2;
    for (j = 1; j < len; j++)
    {
        x = x * 2;
        y = (y * 2 + s2[j] - 48) % p;
    }
    for (i = 1; i < l2 - len+2; i++)
    {
        if (search(i - 1, y % p, len, s1, s2, hash_arr) == 1)
        {
            return 1;
        }
        else
        {
            printf("s2 : %d\n",y);
            y = (y * 2 + s2[i + len - 1] - 48 - x * (s2[i - 1] - 48)) % p;
            check++;
        }
    }
    if (check == l2 - len - 1)
    {
        return 0;
    }
    return 0;
}
int lcs_bin(char *s1, char *s2, int low,int l, int high)
{
    printf("high : %d\nlow : %d\n",high,low);
    if (high >= low)
    {
        struct node *hash_arr[100000] = {NULL};
        l = (low + high) / 2;
        printf("Length in process : %d\n",l);
        if (find_substring(s1, s2, l, hash_arr) == 1)
        {
            return lcs_bin(s1, s2, l + 1,l, high);
        }
        else
        {
            struct node *hash_arr[100000] = {NULL};
            return lcs_bin(s1, s2, low,l, l - 1);
        }
    }
    // printf("%d",l);
    return l;
}
int main()
{
    char *s1 = (char *)malloc(sizeof(char) * 100000);
    char *s2 = (char *)malloc(sizeof(char) * 100000);
    scanf("%s %s",s1,s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    int high = min(l1, l2);
    int low = 0;
    // printf("high : %d\nlow : %d\n",high,low);
    printf("Length of longest common substring : %d\n", lcs_bin(s1, s2,(low+high)/2, low, high));
    return 0;
}