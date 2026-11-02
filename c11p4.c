#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct
{
    int x;
    int y;
}Points;

int dist(Points p)
{
    return abs(p.x-p.y);
}

void swap(Points *a, Points *b)
{
    Points temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(Points a[], int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left<n && dist(a[left])>dist(a[large]))
    {
        large=left;
    }

    if (right<n && dist(a[right])>dist(a[large]))
    {
            large=right;
    }

    if (large!=i)
    {
        swap(&a[i],&a[large]);
        heapify(a,n,large);
    }
}

void heapSort(Points a[], int n)
{
    for (int i=(n/2)-1;i>=0;i--)
    {
        heapify(a, n, i);
    }
    for (int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}


void display(Points a[], int n)
{
    for (int i = 0; i < n; i++)
    {
         printf("(%d,%d) = %d\n", a[i].x,a[i].y,dist(a[i]));
    }
    printf("\n");
}


int main()
{
    printf("enter the number of points:");
    int n;
    scanf("%d",&n);
    Points a[n];
    printf("enter the numbers:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    display(a,n);

    heapSort(a,n);
    printf("The sorted points:\n");
    display(a,n);
    return 0;
}



