#include <stdio.h>
#include <stdlib.h>
int insert_heap();
struct node
{
    int freq;
    int num;
    int heap_index;
    struct node *link;
};
int n = 0; // initial size of an array
int min_freq_num = -1;
void print(int *H)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", H[i]);
    }
}
int top_down_heapify(int i, int *H, int n)
{
    int l, t;
    while (2 * i + 2 < n)
    {
        if (H[2 * i + 1] < H[2 * i + 2])
        {
            l = 2 * i + 1;
        }
        else
        {
            l = 2 * i + 2;
        }
        if (H[i] > H[l])
        {

            t = H[i];
            H[i] = H[l];
            H[l] = t;
            i = l;
        }
        else
        {
            break;
        }
    }
    if (2 * i + 1 < n && H[i] > H[2 * i + 1])
    {
        t = H[i];
        H[i] = H[2 * i + 1];
        H[2 * i + 1] = t;
        return 2 * i + 1;
    }
    return i;
}
int bottom_up_heapify(int i, int *H)
{
    int p, t;
    p = (i - 1) / 2;
    while (p >= 0 && H[p] > H[i])
    {
        t = H[i];
        H[i] = H[p];
        H[p] = t;
        i = p;
        p = (i - 1) / 2;
    }
    return i;
}
int update(int *H, int i, int x)
{
    int k;
    if (H[i] < x)
    {
        H[i] = x;
        k = top_down_heapify(i, H, n);
    }
    else
    {
        H[i] = x;
        k = bottom_up_heapify(i, H);
    }
    return k;
}
void delete_min(int *H)
{
    H[0] = H[--n];
    top_down_heapify(0, H, n);
}
void delete_min_freq(int H[])
{
    int t = H[0];
    delete_min(H);
    while (t == H[0])
    {
        delete_min(H);
    }
}
int append(int x, struct node **root, int heap_arr[])
{
    int flag = 0, z;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->num = x;
    // scanf("%d", &temp->data);
    temp->link = NULL;
    if (*root == NULL)
    {
        printf("root is null \n");
        (*root) = temp;
        (*root)->freq = 1;
        (*root)->num = x;
        (*root)->heap_index = insert_heap(1, heap_arr);
        if ((*root)->heap_index == 0)
        {
            min_freq_num = x;
        }
    }
    else
    {
        printf("I am in else\n");
        struct node *p;
        p = *root;
        if ((*root)->num == x)
        {
            (*root)->freq++;
            z = update(heap_arr, (*root)->heap_index, (*root)->freq);
            if (z == 0)
            {
                min_freq_num = x;
            }
            return 0;
        }
        while (p->link != NULL)
        {
            printf("p->num : %d", p->num);
            if (p->num == x)
            {
                p->freq++;
                printf("x : %d heap_index : %d freq : %d\n", x, p->heap_index, p->freq);
                flag = 1;
                z = update(heap_arr, p->heap_index, p->freq); 
                if (z == 0)
                {
                    min_freq_num = x;
                }
                break;
            }
            p = p->link;
        }
        if (flag == 0)
        {
            printf("I am in flag 0\n");
            p->link = temp;
            temp->num = x;
            temp->freq = 1;
            temp->heap_index = insert_heap(1, heap_arr);
            if (temp->heap_index == 0)
            {
                min_freq_num = x;
            }
        }
    }
    return 0;
}
int insert_heap(int x, int *H)
{
    // int x;
    // printf("Enter node you want to add : \n");
    // scanf("%d",&x);
    H[n++] = x;
    return bottom_up_heapify(n - 1, H);
    // print(H,n);
}
void search_or_insert_in_hashtable(int x, struct node *hash_table[], int heap_arr[])
{
    int p = 100007;
    int m = x % p;
    append(x, &hash_table[m], heap_arr);
}
void add_integer(int x, struct node *hash_table[], int heap_arr[])
{
    search_or_insert_in_hashtable(x, hash_table, heap_arr);
    // insert_heap(x,heap_arr);
}
int main()
{
    int p = 100007;
    int i, q, y = 1, x;
    struct node *hash_table[10000];
    int heap_arr[10000];
    printf("Enter 0 to stop, 1 to add integer, 2 to delete maximum freq. element\n");
    while (y != 0)
    {
        scanf("%d", &y);
        switch (y)
        {
        case (1):
            printf("Enter integer you want to add : ");
            scanf("%d", &x);
            add_integer(x, hash_table, heap_arr);
            print(heap_arr);
            // printf("%d",heap_arr[0]);
            break;
        case (2):
            delete_min_freq(heap_arr);
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = hash_table[min_freq_num%p];
            while(temp->link!=NULL)
            {
                if(temp->num == min_freq_num)
                {
                    temp->freq = 0;
                    break;
                }
            }
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
