#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link;
}*root;
void display()
{
    struct node *temp;
    temp = root;
    while(temp->link!=NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->link;
    }
    printf("%d-->NULL",temp->data);
}
void reverse()
{
    struct node *p,*c,*n;
    p = NULL;c = root;
    while(c!=NULL)
    {
        n = c->link;
        c->link = p;
        p = c;
        c = n;
    }
    root = p;
    display();
}
// void append()
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     printf("Enter data you want to append\n");
//     scanf("%d", &temp->data);
//     temp->link = NULL;
//     if (root == NULL)
//     {
//         root = temp;
//     }
//     else
//     {
//         struct node *p;
//         p = root;
//         while (p->link != NULL)
//         {
//             p = p->link;
//         }
//         p->link = temp;
//     }
// }
void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node ));
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link = temp;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        append();
    }
    display();
    printf("\nREVERSE : ");
    reverse();
    printf("\n");
    return 0;
}