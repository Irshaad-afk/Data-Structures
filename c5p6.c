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
NODE *Conc(NODE *l1,NODE *l2)
{
    NODE *l3=NULL;
    while(l1)
    {
        l3=insertTail(l3,l1->data);
        l1=l1->next;
    }
    while(l2)
    {
        l3=insertTail(l3,l2->data);
        l2=l2->next;
    }
    return l3;
}
int main()
{
    NODE *l1=NULL;
    NODE *l2=NULL;
    NODE *l3=NULL;
    int n1,n2,data1,data2;
    printf("Enter no of nodes for list 1:");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("Enter value%d: ",i+1);
        scanf("%d",&data1);
        l1= insertTail(l1,data1);
    }

    printf("Enter no of nodes for list 2:");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("Enter value%d: ",i+1);
        scanf("%d",&data2);
        l2= insertTail(l2,data2);
    }
    printf("List 1: ");
    display(l1);
    printf("\n");
    printf("List 2: ");
    display(l2);
    printf("\n");
    l3= Conc(l1,l2);
    printf("List 3: ");
    display(l3);
    printf("\n");
    return 1;
}


