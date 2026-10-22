#include<stdio.h>

void oddmagic(int n, int ms[50][50],int r,int c,int i)
{


    if(i<=n*n)
    {
        ms[r][c]=i;
        int newr=(r-1+n)%n;
        int newc=(c+1)%n;

        if(ms[newr][newc]==0)
        {
            oddmagic(n,ms,newr,newc,i+1);
        }
        else{
            oddmagic(n,ms,(r+1)%n,c,i+1);
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
    oddmagic(n,ms,1,3,1);
    printmagic(n,ms);
    return 0;


}