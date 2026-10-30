#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct bt
{
    char data[100];
    struct bt *left, *right;
}BT;

BT * makeNode(char data[])
{
    BT *t = (BT *) malloc(sizeof(BT));
    strcpy(t->data,data);
    t->left = NULL;
    t->right = NULL;
    return t;
}

BT *insert(BT *t,char data[])
{
    if(!t)
    {
        return makeNode(data);
    }
    if(strcmp(t->data,data)>0)
    {
        t->left=insert(t->left,data);
    }
    if(strcmp(t->data,data)<0)
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
        printf("%s\t",t->data);
        inorder(t->right);
    }
}
int countl(BT *t)
{
    if(!t)
        return 0;
    if(!t->left && !t->right)
       return 1;
    return countl(t->left)+countl(t->right);
}

int count1(BT *t)
{
    if(!t)
        return 0;
    if(!t->left && t->right || !t->right && t->left)
       return 1+count1(t->left)+count1(t->right);;
    return count1(t->left)+count1(t->right);
}

int count2(BT *t)
{
    if(!t)
        return 0;
    if(t->left && t->right)
       return 1+count2(t->left)+count2(t->right);;
    return count2(t->left)+count2(t->right);
}

int main()
{
    BT *t=NULL;
    int n;
    printf("enter n:");
    scanf("%d",&n);
    char a[n][100];
    printf("BST:\t");
    for(int i=0;i<n;i++)
    {
       scanf("%s",a[i]);
       t=insert(t,a[i]);
    }
    printf("\n");
    printf("Inorder:");
    inorder(t);
    printf("\n");

    int c0=countl(t);
    printf("Count:%5d",c0);
    printf("\n");

    int c1=count1(t);
    printf("Count one child:%5d",c1);
    printf("\n");

    int c2=count2(t);
    printf("Count two child:%5d",c2);
    printf("\n");


    printf("\n");
    return 0;
}

