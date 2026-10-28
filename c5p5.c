#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

void display(NODE *l)
{
    while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
}

NODE *makeNode(int data)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

NODE *insertHead(NODE *l,int data)
{
    NODE *temp=makeNode(data);
    temp->next=l;
    return temp;
}

NODE *insertTail(NODE *l,int data)
{
    if(!l)
        return makeNode(data);
    NODE *t=l;
    while(t->next)
    {
        t=t->next;
    }
    t->next=makeNode(data);
    return l;
}
NODE *Copy(NODE *l)
{
    if(!l)
        return NULL;
    NODE *t=makeNode(l->data);
    t->next=Copy(l->next);
    return t;
}
int main()
{
    NODE *l1=NULL;
    NODE *l2=NULL;
    int n,data;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter value%d: ",i+1);
        scanf("%d",&data);
        l1= insertTail(l1,data);
    }
    printf("List: ");
    display(l1);
    printf("\n");
    l2= Copy(l1);
    printf("Copied List: ");
    display(l2);
    printf("\n");
    return 1;
}

