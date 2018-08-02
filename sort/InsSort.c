#include <stdio.h>

/*
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
*/
void InsetionSort(int A[], int wait4Sort)
{
    int i,temp;
    if (wait4Sort > A[4])
    {
        A[4] = wait4Sort;
        for (i = 3; i >= 0; i--)
        {
            if (wait4Sort > A[i])
            {
                temp = A[i];
                A[i] = wait4Sort;
                A[i+1] = temp;
            }
            else{return;}
        }
    }
    else{return;}
}
int main()
{
    int Array[5] = {10,9,8,7,6};
    int intInput,i;
    for(;;)
    {
	    printf("Input a int num\n");
        scanf("%d",&intInput);
        InsetionSort(Array,intInput);
		printf("result:");
		for (i = 0; i < 5; i++)
		{
			printf("%d ",Array[i]);
		}
		printf("\n");
	}
	return 0;
}
