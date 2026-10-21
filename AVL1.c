#include<stdio.h>
#include<malloc.h>

typedef struct AVL
{
    int data;
    struct AVL *left;
    struct AVL *right;
}AVL;

AVL *create(int data)
{
    AVL *temp=(AVL*)malloc(sizeof(AVL));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int height(AVL *a)
{
    if(a==NULL)
    {
        return 0;
    }
    int l=height(a->left);
    int r=height(a->right);

    return l>r?l+1:r+1;
}

int max(int a,int b)
{
    return(a>b)?a:b;
}

void update(AVL *a)
{
    if(a)
      {
          int h = 1 + max(height(a->left),height(a->right));
      }
}

AVL *rightRotate(AVL *y)
{
    AVL *t = y->left;
    AVL *T2 = t->right;

    t->right = y;
    y->left = T2;

    update(y);

    update(t);

    return t;
}


AVL *leftRotate(AVL *x)
{
    AVL *t = x->right;
    AVL *T2 = t->left;

    t->left = x;
    x->right = T2;

    update(x);

    update(t);

    return t;
}

int getbal(AVL *a)
{
    if(a==NULL)
        return 0;
    return height(a->left)-height(a->right);
}

AVL *insert(AVL *a, int data)
{

    if (a == NULL)
        return create(data);

    if (data < a->data)
        a->left = insert(a->left, data);

    else if (data > a->data)
        a->right = insert(a->right, data);

    else
        return a;

    update(a);

    int balance = getbal(a);


    if (balance > 1 && data < a->left->data)
        return rightRotate(a);


    if (balance < -1 && data > a->right->data)
        return leftRotate(a);


    if (balance > 1 && data > a->left->data)
    {
        a->left = leftRotate(a->left);
        return rightRotate(a);
    }


    if (balance < -1 && data < a->right->data)
    {
        a->right = rightRotate(a->right);
        return leftRotate(a);
    }

    return a;
}

void inorder(AVL *a)
{
    if(a)
    {
        inorder(a->left);
        printf("%d ",a->data);
        inorder(a->right);
    }
}

void levelp(AVL *a,int l)
{
    if(!a)
        return 0;
    if(l==0)
    {
        printf("%5d",a->data);
    }

    levelp(a->left,l-1);
    levelp(a->right,l-1);
}

void levorder(AVL *a)
{
    int h=height(a);
    for(int i=0;i<h;i++)
    {
        printf("level %d:",i);
        levelp(a,i);
        printf("\n");
    }
}

int main()
{
    AVL *a=NULL;
    a=insert(a,1);
    a=insert(a,2);
    a=insert(a,3);
    a=insert(a,4);
    a=insert(a,5);
    a=insert(a,6);
    a=insert(a,7);
    a=insert(a,8);
    a=insert(a,9);
    a=insert(a,10);

    /*for(int i=0;i<10;i++)
    {
        int x=rand()%10;
        printf("%5d",x);
        a=insert(a,x);
    }*/



    printf("Inorder: ");
    inorder(a);
    printf("\n");

    levorder(a);
    return 0;
}