#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


void insertionsort(char a[][100],int n)
{
    for(int i=1;i<n;i++)
    {
        char key[100];
        strcpy(key,a[i]);
        int j=i-1;

        while(j>=0 && strcmp(a[j],key)>0)
        {
            strcpy(a[j+1],a[j]);
            j--;
        }
        strcpy(a[j+1],key);
    }
}

int main()
{

    int n=5;
    char a[n][100];
    printf("enter the strings:");
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    insertionsort(a,n);
    printf("sorted strings:");
    for(int i=0;i<n;i++)
    {
        printf("%s\n",a[i]);
    }
    return 0;
}
