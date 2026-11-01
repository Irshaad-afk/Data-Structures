#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct
{
    int regis;
    int credits;
    float gpa;
}R;

void merge(R a[],int l,int m,int h)
{
    int i=l;
    int j=m+1;
    int k=0;
    R res[h-l+1];
    while(i<=m && j<=h)
    {
        if(a[i].credits<=a[j].credits)
        {
            res[k]=a[i];
            i++;
            k++;
        }
        else
        {
            res[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        res[k]=a[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        res[k]=a[j];
        j++;
        k++;
    }
    for(int i=0;i<h-l+1;i++)
    {
        a[l+i]=res[i];
    }
}

void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}


int main()
{
    printf("enter the number of records:");
    int n;
    scanf("%d",&n);
    R a[n];
    printf("enter the details:");
    for(int i=0;i<n;i++)
    {
        printf("record:%d",i+1);
        scanf("%d %d %f",&a[i].regis,&a[i].credits,&a[i].gpa);
    }
    mergesort(a,0,n-1);
    printf("RECORD:\n");
    printf("Reg\tCredits\tGPA\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%.2f\t\n",a[i].regis,a[i].credits,a[i].gpa);
    }
    return 0;
}

