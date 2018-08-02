#include <stdio.h>

void InsertionSort(int A[], int n)
{
	int i,j,get;
    for (i = 1; i < n; i++)
    {
        get = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > get)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get;
    }
}

int main()
{
	int i;
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n = sizeof(A) / sizeof(int);
    InsertionSort(A, n);
    printf("插入排序结果：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
