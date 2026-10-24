#include<stdio.h>
typedef struct
{
    int coeff;
    int expo;
}TERM;
typedef struct
{
    TERM t[100];
    int nT;
}POLY;

POLY create()
{
   POLY p;
   p.nT=0;
   return p;
}

void print(POLY p)
{
    for(int i=0;i<p.nT;i++)
    {
        printf("+%dx^%d",p.t[i].coeff,p.t[i].expo);
    }
}
POLY attachterm(POLY p,TERM t)
{
    int i=p.nT-1;
    while(i>=0)
    {
        if(p.t[i].expo==t.expo)
        return p;
        else
        i=i-1;
    }
    i=p.nT-1;
    while((i>=0)&&(p.t[i].expo<t.expo))
    {
        p.t[i+1]=p.t[i];
        i=i-1;
    }
      p.t[i+1]=t;
      p.nT=p.nT+1;
      return p;
}

int main()
{
    TERM t1={2,12},t2={5,4},t3={8,12};
    POLY p;
    p=create();
    p=attachterm(p,t1);
    p=attachterm(p,t2);
    p=attachterm(p,t3);
    printf("\n P 1= ");
    print(p);
    return 0;
}

