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

void check(NODE *l1,NODE *l2)
{
    while(l1 && l2)
    {
        if(l1->data!=l2->data)
        {
            printf("NOT SAME!!");
            return;
        }
        l1=l1->next;
        l2=l2->next;
    }
    if(!l1 && !l2)
    {
       printf("SAME!!");
       return;
    }
    printf("NOT SAME!!");
}

int main()
{
    NODE *l1=makeNode(200),*l2=makeNode(200);
    l1=insertHead(l1,1000);
    l1=insertTail(l1,2000);
    l2=insertHead(l2,1000);
    l2=insertTail(l2,2000);
    l2=insertTail(l2,3000);
    printf("List 1:");
    display(l1);
    printf("\n");
    printf("List 2:");
    display(l2);
      printf("\n");
    check(l1,l2);
    return 1;
}

