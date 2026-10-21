#include<stdio.h>
#include<string.h>

void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void permute(char *a,int s,int e)
{
    if(s==e)
    {
        printf("%s\n",a);
        return;
    }

    for(int i=s;i<=e;i++)
    {
        swap(&a[s],&a[i]);
        permute(a,s+1,e);
        swap(&a[s],&a[i]);
    }
}

int main()
{
    char list[50];
    int n;
    printf("enter size:");
    scanf("%d",&n);
    printf("enter the list:");
    scanf("%s",list);

    permute(list,0,n-1);
    return 0;

}
