#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

void selectionSort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[i], &a[min]);
    }
}

void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j;
    for (j = low; j < high; j++)
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void heapify(int a[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void countingSort(int a[], int n)
{
    int i, j, max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    int count[max + 1];
    for (i = 0; i <= max; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[a[i]]++;
    j = 0;
    for (i = 0; i <= max; i++)
        while (count[i] > 0)
        {
            a[j++] = i;
            count[i]--;
        }
}

int getMax(int a[], int n)
{
    int i, max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void radixCountingSort(int a[], int n, int exp)
{
    int output[n], count[10] = {0}, i;
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int max = getMax(a, n), exp;
    for (exp = 1; max / exp > 0; exp *= 10)
        radixCountingSort(a, n, exp);
}

void shellSort(int a[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
}

int main()
{
    int original[100], a[100], n, choice, i;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &original[i]);

    do
    {
        printf("             SORT MENU              \n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7. Counting Sort\n8. Radix Sort\n9. Shell Sort\n10. Display Original Array\n0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        for (i = 0; i < n; i++)
            a[i] = original[i];

        switch (choice)
        {
            case 1: bubbleSort(a, n); printf("\nBubble Sort:\n"); display(a, n); break;
            case 2: selectionSort(a, n); printf("\nSelection Sort:\n"); display(a, n); break;
            case 3: insertionSort(a, n); printf("\nInsertion Sort:\n"); display(a, n); break;
            case 4: mergeSort(a, 0, n - 1); printf("\nMerge Sort:\n"); display(a, n); break;
            case 5: quickSort(a, 0, n - 1); printf("\nQuick Sort:\n"); display(a, n); break;
            case 6: heapSort(a, n); printf("\nHeap Sort:\n"); display(a, n); break;
            case 7: countingSort(a, n); printf("\nCounting Sort:\n"); display(a, n); break;
            case 8: radixSort(a, n); printf("\nRadix Sort:\n"); display(a, n); break;
            case 9: shellSort(a, n); printf("\nShell Sort:\n"); display(a, n); break;
            case 10: printf("\nOriginal Array:\n"); display(original, n); break;
            case 0: printf("\nProgram terminated.\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}

Sorting algorithms included
