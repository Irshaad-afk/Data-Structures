#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct Node2{
int data2;
struct Node2 *next;
}COL;

typedef struct Node1{
int data1;
struct Node1 *d;
COL *r;
}ROW;

ROW *makeRow()
{
    ROW *t= (ROW*)malloc(sizeof(ROW));
    t->data1= rand()%10;
    t->d= NULL;
    t->r= NULL;
    return t;
}

COL *makeCol()
{
    COL *t= (COL*)malloc(sizeof(COL));
    t->data2= rand()%10;;
    t->next= NULL;
    return t;
}

ROW *jagg(int a)
{
    ROW *l=NULL;
        ROW *t=NULL;
        for(int i=0;i<a;i++)
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

            int b=rand()%10;
            COL *t2=NULL;
            for(int j=0;j<b;j++)
            {
                COL *cur= makeCol();
                if(!t2)
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
        return l;

}

void disp(ROW *l)
{
    ROW *t = l;

    while(t)
    {
        printf("%d : ", t->data1);
        COL *t2 = t->r;

        while(t2)
        {
            printf("%d ", t2->data2);
            t2 = t2->next;
        }

        printf("\n");

        t = t->d;
    }
}
int main()
{
    ROW *l = NULL;

    l = jagg(5);

    disp(l);

    return 0;
}
