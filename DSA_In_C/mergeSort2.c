#include <stdio.h>

void mergesort(int a[], int, int);
void merge(int a[], int, int, int);

int main()
{
    int a[30] = {12,58,63,14,54};
    int i,n = 5;
   
    mergesort(a, 0, n-1);
    printf("\nSorted array is :");
    for (i = 0; i < n; i++)
    {   
        printf("%d ", a[i]);
    }
    return 0;
}

void merge(int a[], int low, int mid, int high)
{
    int B[50]; //B stores sorted array
    int i, j, k;
    i = low;     //beginning of the first list
    j = mid + 1; //beginning of the second list
    k = 0;
    while (i <= mid && j <= high) //while elements in both lists
    {
        if (a[i] < a[j])
        {
            B[k] = a[i];
            i++;
        }
        else
        {
            B[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) //copy remaining elements of the first list
    {
        B[k] = a[i];
        i++;
        k++;
    }

    while (j <= high) //copy remaining elements of the second list
    {
        B[k] = a[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);      //left recursion
        mergesort(a, mid + 1, high); //right recursion
        merge(a, low, mid, high);    //merging of two sorted sub-arrays
    }
}
