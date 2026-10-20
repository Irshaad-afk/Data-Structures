#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct bt
{
    int data;
    struct bt *left, *right;
}BT;

BT * makeNode(int data)
{
    BT *t = (BT *) malloc(sizeof(BT));
    t->data = data;
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
    if(t->data<data)
    {
        t->right=insert(t->right,data);
    }
    return t;
}

void inorder(BT *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%5d",t->data);
        inorder(t->right);
    }
}

void preorder(BT *t)
{
    if(t)
    {
        printf("%5d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(BT *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%5d",t->data);
    }
}

int height(BT *t)
{
    if(!t)
    {
        return 0;
    }
    int l=height(t->left);
    int r=height(t->right);
    return l>r?l+1:r+1;

}
BT *deleted(BT *t,int data)
{
    if(!t)
        return NULL;
    if(t->data==data)
    {
        if(!t->left && !t->right)
            return NULL;
        if(!t->left)
            return t->right;
        if(!t->right)
            return t->left;
        t->data=findMin(t->right);
        t->right=deleted(t->right,t->data);
        return t;
    }
    if(t->data>data)
    {
        t->left=deleted(t->left,data);
    }
    else
    {
        t->right=deleted(t->right,data);
    }
    return t;
}

int findMin(BT *t)
{
    if(!t->right)
    {
        return t->data;
    }
    return findMin(t->right);
}


int search(BT *t,int data)
{
    if(!t)
        return 0;
    if(t->data==data)
        return 1;
    if(t->data>data)
        return search(t->left,data);
    if(t->data<data)
        return search(t->right,data);
}

int count(BT *t)
{
    if(!t)
        return 0;
    return 1+count(t->left)+count(t->right);
}

int main()
{
    BT *t=NULL;
    int a[10];
    printf("Original:\t");
    for(int i=0;i<10;i++)
    {
        a[i]=rand()%100;
        printf("%5d",a[i]);
        t=insert(t,a[i]);
    }
    printf("\n");
    printf("Inorder:\t");
    inorder(t);
    printf("\n");
    printf("Preorder:\t");
    preorder(t);
    printf("\n");
    printf("Postorder:\t");
    postorder(t);
    printf("\n\n");

    printf("Height: %3d\n\n",height(t));

    printf("After Deleting 69 :");
    deleted(t,69);
    inorder(t);
    printf("\n\n");

    printf("Search 69:");
    int s=search(t,69);
    if(s)
    {
        printf("found");
    }
    else
    {
        printf("not found");
    }
    printf("\n\n");


    int c=count(t);
    printf("Count:%5d",c);


    printf("\n");
    return 0;
}
