#include<stdio.h>
int main()
{
    int p1[10]={3,2,7,-3,5,5,3};
    int p2[10]={2,7,3,-5,0};
    int p3[10];
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
        p3[0]=k;
        printf(" [ ");
        for(int i=0;i<=2*k;i++)
        {
            printf("%d  ", p3[i]);
        }
        printf("] ");

}