#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct bt
{
    char data;
    struct bt *left, *right;
}BT;

BT * makeNode(char data)
{
    BT *t = (BT *) malloc(sizeof(BT));
    strcpy(t->data,data);
    t->left = NULL;
    t->right = NULL;
    return t;
}
char findmax(BT* t)
{
    if (t->right == NULL)
        return t->data;

    return findmax(t->right);
}

bool search(BT* t, char data)
{
    if (t == NULL)
        return false;

    if (t->data == data)
        return true;

    if (data < t->data)
        return search(t->left, data);

    return search(t->right, data);
}


BT *insert(BT *t,char data)
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
BT *deleted(BT *t,char data)
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
        t->data=findmax(t->right);
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

void inorder(BT *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%s\t",t->data);
        inorder(t->right);
    }
}

int main()
{
    BT *t=NULL;
    char a[10];
    printf("BST:\t");
    scanf("%s",a);

    int i=0;
    while(a[i]!='\0')
    {
        if(a[i] == 'D')
        {
            i++;

            if (search(t, a[i]))
            {
                printf("\nValue %c already exists\n", a[i]);
            }
            else
            {
                t = insert(t, a[i]);
            }

            i++;
        }
        else if (a[i] == 'U')
        {
            i++;

            if (!search(t, a[i]))
            {
                printf("\nValue %c does not exist\n", a[i]);
            }

            i++;
        }
        else if (a[i] == 'K')
        {
            i++;

            if (!search(t, a[i]))
            {
                printf("\nValue %c does not exist\n", a[i]);
            }
            else
            {
                t = deleted(t, a[i]);
            }
            i++;
        }
        else
        {
            printf("\nInvalid Sequence\n");
            i++;
        }
    }

    printf("\nDisplaying inorder traversal:\n");
    inorder(t);

    printf("\n");

    return 0;
}


