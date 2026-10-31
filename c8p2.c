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

int count(BT *t)
{
    if(!t)
        return 0;
    return 1+count(t->left)+count(t->right);
}

int iscomp(BT *t,int i,int c)
{
    if(!t)
        return 1;
    if(i>=c)
    {
        return 0;
    }
    return iscomp(t->left,2*i+1,c)&&iscomp(t->right,2*i+2,c);
}

int ismin(BT *t)
{
    if(!t)
       return 1;

    if(t->left != NULL)
    {
        if(t->data>t->left->data)
            return 0;
    }

    if(t->right != NULL)
    {
        if(t->data>t->right->data)
            return 0;
    }
    return ismin(t->left)&&ismin(t->right);
}


int main()
{
    BT *t=create(10);
    t->left=create(20);
    t->right=create(30);

    t->left->left=create(40);
    t->left->right=create(50);

    t->right->left=create(60);
    t->right->right=create(70);


    int c=count(t);

    if(iscomp(t,0,c)&&ismin(t))
    {
        printf("It is a min heap");
    }
    else
    {
        printf("It is not a min heap");
    }

    return 0;
}
