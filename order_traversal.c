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
int main()
{
    node *root;
    root = create();
    printf("Preorder traversal : ");
    pre_order(root);
    printf("Inorder traversal : ");
    in_order(root);
    printf("Postorder traversal : ");
    post_order(root);
    return 0;
}