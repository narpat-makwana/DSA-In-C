#include <stdio.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);

int main()
{
    int a[50], n, i;
    printf("How many elements?");
    scanf("%d", &n);
    printf("\nEnter array elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    printf("\nArray after sorting:");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

void quick_sort(int A[], int lb, int up)
{
    int pos;
    if (lb < up)
    {
        pos = partition(A, lb, up);
        quick_sort(A, lb, pos - 1);
        quick_sort(A, pos + 1, up);
    }
}

int partition(int A[], int lb, int up)
{
    int p, end, start, temp;
    p = A[lb];
    end = lb;
    start = up + 1;
    do
    {
        do
            end++;
        while (a[end] < p && end <= up);
        do
            start--;
        while (p < A[start]);
        if (end < start)
        {
            temp = A[end];
            A[end] = A[start];
            A[start] = temp;
        }
    } while (end < start);
    A[lb] = A[start];
    A[start] = p;
    return (start);
}