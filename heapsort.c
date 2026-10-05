#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n, int i)
{
    int large, temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    large = i;

    if(l < n && a[l] > a[large])
        large = l;

    if(r < n && a[r] > a[large])
        large = r;

    if(large != i)
    {
        temp = a[i];
        a[i] = a[large];
        a[large] = temp;

        heapify(a, n, large);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for(i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int a[20], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Random elements: ");
    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    heapSort(a, n);

    printf("\nSorted elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}