#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct node
{
    long long int data;
    struct node *link;
} * hash_arr[10000];
char text[100], match[100], **hash;
long long int n, l;
// hash = (char **)malloc(n * sizeof(char*));
// void search(long long int x, char *arr, long long int m)
// {
//     int k = 0;
//     struct node *temp;
//     if (hash_arr[x] != NULL)
//     {
//         temp = hash_arr[x];
//         while (temp != NULL)
//         {
//             k = 0;
//             // if (strcmp(hash[x], arr) == 0)
//             while (k < l)
//             {
//                 if (arr[k] == hash[x][k])
//                 {
//                     k++;
//                     continue;
//                 }
//                 printf("The pattern is not found ... \n");
//                 break;
//             }
//             if (k == l)
//             {
//                 printf("string found\n");
//                 break;
//             }
//             temp = temp->link;
//         }
//         // printf("There is no such pattern like at position %lld (number = %lld) in text...\n",m,x);
//     }
// }
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
    // display(hash_arr[i]);
}

int main()
{
    long long int p, i, x, j, y, k, m, len;
    printf("Enter the text : ");
    scanf("%s", text);
    len = strlen(text);
    printf("Enter the no. of patterns and length of pattern : \n");
    scanf("%lld ", &n);
    // printf("len : %lld\nn : %lld\ny : %lld", len, n, l);
    p = (long long int)pow(2, 30) + 5;
    hash = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        k = 0;
        hash[i] = (char *)malloc(l * sizeof(char));
        scanf("%s", hash[i]);
        // m = hash[i];
        l = strlen(hash[i]);
        for (j = 0; j < l; j++)
        {
            k += (int)(hash[i][j]);
            // k += m % 10 * pow(2, j);
            // m = m / 10;
        }
        // printf("%lld ", k);
        append(i, k % p);
    }
    printf("\n");
    y = (int)text[0];
    // x = 2;
    for (j = 1; j < l; j++)
    {
        // x = x * 2;
        // N = N * 2 + p[j] - 48;
        y = y + (int)text[j];
    }
    // printf("y : %lld\n", y);
    // printf("mathc : ");
    for (i = 0; i < l; i++)
    {
        match[i] = text[i];
        // printf("%c ", match[i]);
    }
    // printf("y : %lld\n", y);
    // search(y % p, match, 0);
    for (i = 1; i < len - l + 1; i++)
    {
        y = y + (int)text[i + l-1 ] - (int)text[i-1 ];
        // printf("i : %lld\ny : %lld\n", i, y);
        // printf("match : ");
        for (j = 0; j < l; j++)
        {
            match[j] = text[i + j];
            // printf("%c ", match[j]);
        }
        // search(y % p, match, i);
        x = y%p;
        // printf("x : %lld\n",x);
        // void search(long long int x, char *arr, long long int m)
        // {
            k = 0;
            struct node *temp;
            if (hash_arr[x] != NULL)
            {
                // printf("inside if condition..\n");
                temp = hash_arr[x];
                while (temp != NULL)
                {
                    // printf("inside while loop\n");
                    k = 0;
                    // if (strcmp(hash[x], arr) == 0)
                    while (k < l)
                    {
                        if (match[k] == hash[temp->data][k])
                        {
                            // printf("k : %lld\n",k);
                            k++;
                            continue;
                        }
                        // printf("The pattern is not found ... \n");
                        break;
                    }
                    if (k == l)
                    {
                        // printf("string found\n");
                        // break;
                        goto m;
                    }
                    temp = temp->link;
                }
                m:
                    printf("string '%s' found in text at %lld\n",match,i+1);
                // printf("There is no such pattern like at position %lld (number = %lld) in text...\n",m,x);
            }
            // else{printf("string  not found in text :( \n",match);}
        // }
        // hash_arr[y / 3] = y;
        // printf("%lld : %lld\n", y, y);
        // y = y * 2 + text[i + l - 1] - 48 - x * (text[i - 1] - 48);
    }
    // for (i = 0; i < strlen(t) - l; i += 1)
    // {
    // }

    return 0;
}