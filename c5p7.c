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

int midNode(NODE *l)
{
    NODE *t1=l;
    NODE *t2=l;
    while(t2!=NULL && t2->next!=NULL)
    {
        t2=t2->next->next;
        t1=t1->next;
    }
    return t1->data;
}
int main()
{
    NODE *l1=NULL;
    int n,data;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter value%d: ",i+1);
        scanf("%d",&data);
        l1= insertTail(l1,data);
    }
    printf("List 1:");
    display(l1);
    printf("\n");
    printf("Midnode: %d",-idNode(l1));

    return 1;
}

