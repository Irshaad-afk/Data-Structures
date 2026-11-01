#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


void insertionsort(int a[],int n,int *ic)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;

        while(j>=0 && a[j]>key)
        {
            (*ic)++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void merge(int a[],int l,int m,int h,int *mc)
{
    int i=l;
    int j=m+1;
    int k=0;
    int *res =(int*)malloc(sizeof(int)*(h-l+1));
    while(i<=m && j<=h)
    {
        (*mc)++;
        if(a[i]<=a[j])
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

void mergesort(int a[],int l,int h,int *mc)
{
    if(l<h)
    {

        int m=(l+h)/2;
        mergesort(a,l,m,mc);
        mergesort(a,m+1,h,mc);
        merge(a,l,m,h,mc);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int p,int r,int *qc)
{
    int pivot=a[p];
    int i=p;
    for(int j=p+1;j<=r;j++)
    {
        (*qc)++;
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[p],&a[i]);
    return i;
}

void Quicksort(int a[],int p,int r,int *qc)
{
    if(p<r)
    {

        int k=partition(a,p,r,qc);
        Quicksort(a,p,k-1,qc);
        Quicksort(a,k+1,r,qc);

    }
}


void heapify(int a[], int n, int i,int *hc)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left<n && a[left]>a[large])
    {
        large=left;
        (*hc)++;
    }

    if (right<n && a[right]>a[large])
    {
            large=right;
            (*hc)++;
    }

    if (large!=i)
    {
        swap(&a[i],&a[large]);
        heapify(a,n,large,hc);
    }
}

void heapSort(int a[], int n,int *hc)
{
    for (int i=(n/2)-1;i>=0;i--)
    {
        heapify(a, n, i,hc);
    }
    for (int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0,hc);
    }
}

void countsort(int a[],int n)
{
    int k = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > k)
            k = a[i];
    }
    int *C= (int *)malloc((k+1)*sizeof(int));
    int *B= (int *)malloc(n*sizeof(int));

    for(int i=0;i<=k;i++)
    {
        C[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        C[a[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        C[i]=C[i]+C[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        B[C[a[i]]-1]=a[i];
        C[a[i]]=C[a[i]]-1;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = B[i];
    }

}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
         printf("%d ", a[i]);
    }
    printf("\n");
}


int main()
{
    int a[20], b[20], c[20], d[20], e[20];

    for (int i = 0; i < 20; i++)
   {
     a[i] = rand() % 100;

     b[i] = a[i];
     c[i] = a[i];
     d[i] = a[i];
     e[i] = a[i];
   }
    display(a,20);

    int ic=0,mc=0,hc=0,qc=0;
    insertionsort(a,20,&ic);
    //display(a,20);
    printf("Total Count for insertion: %d",ic);
    printf("\n");

    mergesort(b,0,19,&mc);
    //display(a,20);
    printf("Total Count for merge: %d",mc);
     printf("\n");

    Quicksort(c,0,19,&qc);
    //display(a,20);
    printf("Total Count for quick: %d",qc);
     printf("\n");


    heapSort(d,20,&hc);
    //display(a,20);
    printf("Total Count for heap: %d",hc);
     printf("\n");

    countsort(e,20);
   // display(a,20);

    return 0;


}
