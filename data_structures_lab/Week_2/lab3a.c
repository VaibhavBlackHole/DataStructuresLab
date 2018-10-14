#include<stdio.h>
#include<stdlib.h>

int findPivotPosition(int *a,int n)
{
	int ind=0;
	for(int i=1; i<n; i++)
	{
			if(a[i]<=a[0])
				ind++;
	}
	return ind;
}
int main()
{
	int index=0, *a, n;
	
	printf("Please enter size of array:");
	scanf("%d", &n);
	a = (int*)malloc(n*sizeof(int));
	printf("Please enter values in the array:");
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	index = findPivotPosition(a, n);
	printf("pivot_position is:%d\n", index);
}
