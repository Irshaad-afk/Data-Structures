#include<stdio.h>

void oddmagic(int n, int ms[50][50])
{
    int r,c;
    r = 0;
    c= n/2;
    for(int i=1;i<=n*n;i++)
    {
        ms[r][c]=i;
        int newr=(r-1+n)%n;
        int newc=(c+1)%n;

        if(ms[newr][newc]!=0)
        {
            r=(r+1)%n;
        }
        else
        {
            r=newr;
            c=newc;
        }
    }
}
void printmagic(int n, int ms[50][50])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",ms[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;int ms[50][50];
    printf("Enter the order of the square: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ms[i][j]=0;
        }
    }
    oddmagic(n,ms);
    printmagic(n,ms);
    return 0;
}
