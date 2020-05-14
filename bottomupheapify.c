#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *lc;
    struct node *rc;
}node;

node *create()
{
    node *root;
    int x;
    scanf("%d",&x);
    if(x==-1)return NULL;

    root = (node *)malloc(sizeof(node));

    root -> data =x;

    printf("Enter left child of %d : ",x);
    root->lc = create();
    printf("Enter right child of %d : ",x);
    root->rc = create();
    return root;
}

void pre_order(node *parent)
{
    if(parent)
    {
        printf("%d ",parent -> data);
        pre_order(parent->lc);
        pre_order(parent->rc);
    }
}
void in_order(node *parent)
{
    if(parent)
    {
        in_order(parent->lc);
        printf("%d ",parent->data);
        in_order(parent->rc);
    }
}
void post_order(node *parent)
{
    if(parent)
    {
        post_order(parent->lc);
        post_order(parent->rc);
        printf("%d ",parent->data);
    }
}
void bottom_up_heapify(int i, int *H)
{
    int p, t;
    p = (i-1)/2;
    while(p>=0 && H[p]>H[i])
    {
        t = H[i];H[i]=H[p];H[p]=t;
        i = p;
        p = (i-1)/2;
    }
}
void add(int x, int *H, int n)
{
    H[n++] = x;
    bottom_up_heapify(n-1,H);
}
int main()
{
    node *root;
    // root = create();
    int n, i, x;
    scanf("%d",&n);
    int *H = (int *)malloc(sizeof(int)*2*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&H[i]);
    }
    printf("Enter the number you want to add : ");
    scanf("%d",&x);
    // pre_order(root);
    // // printf("Inorder traversal : ");
    // in_order(root);
    // printf("Postorder traversal : ");
    // post_order(root);
    add(x,H,n);
    for(i=0;i<n+1;i++)
    {
        printf("%d ",H[i]);
    }
    return 0;
}