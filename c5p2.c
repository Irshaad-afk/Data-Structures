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

int countNode(NODE *l)
{
    int c=0;
    while(l)
    {
        c++;
        l=l->next;
    }
    return c;
}

int findPos(NODE *l,int data)
{
    int pos=1;
    while(l)
    {
        if(l->data==data)
            return pos;
        l=l->next;
        pos++;
    }
    return -1;
}

int countNodeRec(NODE *l)
{
    if(!l)
        return 0;
    return 1+ countNodeRec(l->next);
}

int findPosRec(NODE *l,int data,int curpos)
{
    if(!l)
        return -1;
    if(l->data==data)
        return curpos;
    return findPosRec(l->next,data,curpos+1);
}

int findsum(NODE *l)
{
    if(!l)
        return 0;
    return l->data+findsum(l->next);
}

void printRev(NODE *l)
{
    if(l)
    {
        printRev(l->next);
        printf("%5d",l->data);
    }
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
    int c= countNode(l1);
    int p= findPos(l1,500);

    printf("List 1:");
    display(l1);
    printf("\nNo of Nodes in List 1: %d",c);
    printf("\nNo of Nodes(Recursive) in List 1: %d\n",countNodeRec(l1));
    printf("\nThe position of the given element: %d",p);
    printf("\nThe position(Recursive) of the given element: %d\n",findPosRec(l1,2000,1));
    printf("\nSum of List 1: %d",findsum(l1));
    printf("\nReverse List 1:");
    printRev(l1);
    printf("\n\n");
    /*printf("List 2:");
    display(l2);
    printf("\nSum of List 2: %d",findsum(l2));
    printf("\nReverse List 2:");
    printRev(l2);*/
    printf("\n\n");
    return 1;
}

