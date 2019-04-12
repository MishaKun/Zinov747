#include <stdio.h>
#include <stdlib.h>

int sift (int *array, int start, int end)
{
    int i, j, x=array[start];
    i = start; j = 2*start;
    if (j<end && array[j+1]<array[j])
        j++;
    while (j<=end && array[j]<x)
    {
        array[i] = array[j];
        i = j;
        j =j* 2;
        if (j<end && array[j+1]<array[j])
            j++;
    }
    array[i] = x;
    return 0;
}

int HeapSort (int *array, int n)
{ 
    int start = n/2+1, end=n-1;
    int x;
    while (start>0)
        sift (array, --start, end);
    while (end>0)
    {
        x = array[0];
        array[0] = array[end];
        array[end] = x;
        sift (array, start, --end);
    }
}

int print(int *array,int n)
{
	for (int i=0; i<n; ++i)
        {
		printf("%d ",array[i]);
        }
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for (int i=0; i<n; ++i)
	{
		int val;
		scanf("%d", &val);
		array[i] = val;
	}
	HeapSort(array,n);
	print(array,n);
}
