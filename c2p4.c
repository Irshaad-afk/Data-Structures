#include<stdio.h>
#include<math.h>

int main()
{
    int p1[201];

    p1[0]=100;
    for(int i=1,l=199;i<=100,l>=0;i++,l=l-2)
    {
        p1[2*i-1]=rand()%1000;
        p1[2*i]=l;
        int t=rand()%2;
        if(t==1)
        {
           p1[2*i-1]= -p1[2*i-1];
        }
    }
    int p2[201];
    p2[0]=100;
    for(int i=1,l=200;i<=100,l>=0;i++,l=l-2)
    {
        p2[2*i-1]=rand()%1000;
        p2[2*i]=l;
        int t=rand()%2;
        if(t==1)
        {
           p2[2*i-1]= -p2[2*i-1];
        }
    }

    int p3[300];
    int n=p1[0];
    int m=p2[0];
    int i=1,j=1,k=0;
    while(i<=n&&j<=m)
    {
        if(p1[2*i]==p2[2*j])
        {
            int t= p1[2*i-1]+p2[2*j-1];
            if(t!=0)
            {
                k++;
                p3[2*k-1]=t;
                p3[2*k]=p1[2*i];
            }
            i++;
            j++;
        }
        else if(p1[2*i]>p2[2*j])
        {
            k++;
            p3[2*k-1]=p1[2*i-1];
            p3[2*k]=p1[2*i];
            i++;
        }
        else
        {
            k++;
            p3[2*k-1]=p2[2*j-1];
            p3[2*k]=p2[2*j];
            j++;
        }
    }
        while(i<=n)
        {
            k++;
            p3[2*k-1]=p1[2*i-1];
            p3[2*k]=p1[2*i];
            i++;
        }
        while(j<=m)
        {
           k++;
           p3[2*k-1]=p2[2*j-1];
           p3[2*k]=p2[2*j];
           j++;
        }
        for(int i=0;i<100;i++)
        {
            printf("%d ",p1[i]);
        }
         printf("\n");
        for(int i=0;i<100;i++)
        {
            printf("%d ",p2[i]);
        }
        printf("\n");
        p3[0]=k;
        printf(" [ ");
        for(int i=0;i<=2*k;i++)
        {
            printf("%d  ", p3[i]);
        }
        printf("] ");

}
