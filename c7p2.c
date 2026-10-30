#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct bt
{
    int data;
    int freq;
    struct bt *left, *right;
}BT;

BT * makeNode(int data)
{
    BT *t = (BT *) malloc(sizeof(BT));
    t->data = data;
    t->freq = 1;
    t->left = NULL;
    t->right = NULL;
    return t;
}

BT *insert(BT *t,int data)
{
    if(!t)
    {
        return makeNode(data);
    }
    if(t->data>data)
    {
        t->left=insert(t->left,data);
    }
    else if(t->data<data)
    {
        t->right=insert(t->right,data);
    }
    else
    {
        t->freq++;
    }
    return t;
}

void inorder(BT *t)
{
    if(t)
    {
        inorder(t->left);
        printf("value :%d \t freq:%d \n",t->data,t->freq);
        inorder(t->right);
    }
}

int main()
{
    BT *t=NULL;
    int a[500];
    printf("Original:\t");
    for(int i=0;i<500;i++)
    {
        a[i]=rand()%10;
        printf("%5d",a[i]);
        t=insert(t,a[i]);
    }
    printf("\n");


    printf("Inorder:\t\n");
    inorder(t);
    printf("\n");



    printf("\n");
    return 0;
}



