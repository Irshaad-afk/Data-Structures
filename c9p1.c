#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 4000
#define M 50000
typedef struct node
{
    int val;
    struct node *next;
}NODE;
typedef struct bt
{
    int data;
    struct bt *l, *r;
}BT;
typedef struct AVL
{
    int key;
    struct AVL *left;
    struct AVL *right;
}AVL;
typedef struct
{
    int arr[Max];
}Array;

void sortedarray(Array *a)
{
    for(int i=0;i<Max-1;i++)
    {
        for(int j=0;j<Max-i-1;j++)
        {
            if(a->arr[j]>a->arr[j+1])
            {
                int temp=a->arr[j];
                a->arr[j]=a->arr[j+1];
                a->arr[j+1]=temp;
            }
        }
    }
}

int searcharray(Array a,int key)
{
    int c=0;
    for(int i=0;i<Max;i++)
    {
        c++;
        if(a.arr[i]==key)
        {
            return c;
        }
    }
    return c;
}

int searchbin(Array a,int key)
{
    int l=0;
    int h=Max-1;
    int c=0;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        c++;
        if(a.arr[m]==key)
        {
            return c;
        }
        if(a.arr[m]<key)
        {
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }
    return c;
}

NODE *makeNode(int data)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->val=data;
    temp->next=NULL;
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


int findPos(NODE *l,int data)
{
    int c=0;
    while(l)
    {
        c++;

        if(l->val==data)
            return c;
        l=l->next;
    }
    return c;
}


BT *makeNode2(int data)
{
    BT *t = (BT *) malloc(sizeof(BT));
    t->data = data;
    t->l = NULL;
    t->r = NULL;
    return t;
}

BT *insert(BT *t,int data)
{
    if(!t)
    {
        return makeNode2(data);
    }
    if(t->data>data)
    {
        t->l=insert(t->l,data);
    }
    if(t->data<data)
    {
        t->r=insert(t->r,data);
    }
    return t;
}


int searchbt(BT *t,int data)
{
    int c=0;

    while(t!=NULL)
    {
        c++;
    }
    if(t->data==data)
        return c;
    if(t->data<data)

    return searchbt(t->r,data);
}


AVL *create(int data)
{
    AVL *temp=(AVL*)malloc(sizeof(AVL));
    temp->key=data;
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

AVL *insertavl(AVL *a, int data)
{

    if (a == NULL)
        return create(data);

    if (data < a->key)
        a->left = insertavl(a->left, data);

    else if (data > a->key)
        a->right = insertavl(a->right, data);

    else
        return a;

    update(a);

    int balance = getbal(a);


    if (balance > 1 && data < a->left->key)
        return rightRotate(a);


    if (balance < -1 && data > a->right->key)
        return leftRotate(a);


    if (balance > 1 && data > a->left->key)
    {
        a->left = leftRotate(a->left);
        return rightRotate(a);
    }


    if (balance < -1 && data < a->right->key)
    {
        a->right = rightRotate(a->right);
        return leftRotate(a);
    }

    return a;
}
AVL *searchavl(AVL *v,int k)
{
    if(v==NULL||v->key==k)
    {
        return v;
    }
    if(k<v->key)
    {
        return searchavl(v->left,k);
    }
    return searchavl(v->right,k);
}

void inorderavl(AVL *a)
{
    if(a)
    {
        inorderavl(a->left);
        printf("%d\t",a->key);
        inorder(a->right);
    }
}

void inorder(BT *t)
{
    if(t)
    {
        inorder(t->l);
        printf("%d\t",t->data);
        inorder(t->r);
    }
}
void displayA(Array *a)
{
    for(int i=0;i<Max;i++)
    {
        printf("%d\t",a->arr[i]);
    }

}

void displayL(NODE *l)
{
    while(l)
    {
        printf("%d\t",l->val);
        l=l->next;
    }
}

int main()
{
    Array a;
    Array b;
    NODE *l=NULL;
    BT *t=NULL;
    AVL *v=NULL;
    for(int i=0;i<Max;i++)
    {
        int n=rand()%10000;
        int d=0;
        for(int j=0;j<i;j++)
        {
            if(a.arr[j]==n)
            {
                d=1;
                break;
            }
        }
        if(d)
        {
            i--;
        }
        else
        {
            a.arr[i]=n;
            b.arr[i]=n;
        }
    }

    for(int i=0;i<Max;i++)
    {
        l=insertTail(l,a.arr[i]);
    }

    for(int i=0;i<Max;i++)
    {
        t=insert(t,a.arr[i]);
    }

    for(int i=0;i<Max;i++)
    {
        v=insertavl(v,a.arr[i]);
    }


    printf("Unsorted Array:\n");
    displayA(&a);

    sortedarray(&b);
    displayA(&b);

    displayL(l);

    inorder(t);

    inorderavl(v);


    int ac=0,lc=0,bc=0,vc=0,uc=0;
    int t1=0,t2=0,t3=0,t4=0,t5=0;

    for(int i=0;i<M;i++)
    {
        int key=rand()%10000;

        if(searcharray(a,key)==0)
        {
            t1=t1+uc;
            uc++;
        }
        if(searchbin(b,key)==0)
        {
             t2=t2+uc;
            ac++;
        }
        if(findPos(l,key)==-1)
        {
             t3=t3+uc;
            lc++;
        }
        if(searchbt(t,key)==0)
        {
             t4=t4+uc;
            bc++;
        }
        if(searchavl(v,key)==0)
        {
             t5=t5+uc;
            vc++;
        }

    }

    printf("\n\n");
    printf("Unsorted array:%d\n",t1/uc);
    printf("Sorted array:%d\n",t2/ac);
    printf("Linked list:%d\n",t3/lc);
    printf("BT:%d\n",t4/bc);
    printf("AVL:%d\n",t5/vc);




    return 0;
}
