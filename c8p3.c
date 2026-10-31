#include<stdio.h>
#include<malloc.h>

typedef struct BT
{
    int data;
    struct BT *left;
    struct BT *right;
}BT;

BT *create(int data)
{
    BT *temp=(BT*)malloc(sizeof(BT));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

BT *insert(BT *t,int data)
{
    if(!t)
    {
        return create(data);
    }
    if(data<t->data)
        t->left=insert(t->left,data);
    else if(data>t->data)
        t->right=insert(t->right,data);

    return t;
}

void inorder(BT *t,int k,int *c)
{
    if(!t)
       return 0;
    inorder(t->left,k,c);

    (*c)++;
    if(*c==k)
    {
        printf("\nSmallest is %d",t->data);
        return;
    }
    inorder(t->right,k,c);
}



int main()
{
    BT *a=NULL;
    for(int i=0;i<10;i++)
    {
        int x=rand()%100;
        printf("%5d",x);
        a=insert(a,x);
    }



    int k;
    printf("\nEnter k to get the value:");
    scanf("%d",&k);
    int c=0;

    inorder(a,k,&c);
    return 0;
}

