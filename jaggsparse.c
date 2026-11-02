#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct Node2{
int col;
int v;
struct Node2 *next;
}COL;

typedef struct Node1{
struct Node1 *d;
COL *r;
}ROW;

ROW *makeRow()
{
    ROW *t= (ROW*)malloc(sizeof(ROW));
    //t->data1= rand()%10;
    t->d= NULL;
    t->r= NULL;
    return t;
}

COL *makeCol(int col, int v)
{
    COL *t= (COL*)malloc(sizeof(COL));
    t->col=col;
    t->v=v;
    t->next= NULL;
    return t;
}

ROW *sparse(int a[][4],int rr,int cc)
{
    ROW *l=NULL;
    ROW *t=NULL;
        for(int i=0;i<rr;i++)
        {
            ROW *curr= makeRow();

            if(!l)
            {
                l=curr;
                t=curr;
            }
            else
            {
                t->d = curr;
                t = curr;
            }

            COL *t2=NULL;
            for(int j=0;j<cc;j++)
            {
                if(a[i][j]!=0){
                        COL *cur= makeCol(j,a[i][j]);
                if(!(t->r))
                {
                    t->r=cur;

                }

                else
                {
                    t2->next = cur;
                }
                t2=cur;
                }
            }
        }
        return l;

}

void disp(ROW *l)
{
    ROW *t = l;

    while(t)
    {

        COL *t2 = t->r;

        while(t2)
        {
            printf(" %d %d ", t2->col, t2->v);

            t2 = t2->next;
        }

        printf("\n");

        t = t->d;
    }
}
int main()
{
    int r,c;
    printf("enter r,c");
    scanf("%d",&r);
    scanf("%d",&c);

    int a[4][4];



    printf("\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=(rand()%10)*(rand()%2);
        }
    }

    printf("the og matrix is:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    ROW *l = sparse(a,4,5);

    //l = jagg(5);

    disp(l);

    return 0;
}
