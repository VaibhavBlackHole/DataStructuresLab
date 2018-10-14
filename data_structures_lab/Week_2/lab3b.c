#include<stdio.h>
#include<stdlib.h>

int findPivotPosition(int *a,int n)
{
	int ind=0; 
	for(int i=1; i<n; i++)
	{
			if(a[i]<=a[0])   // considering pivot to be a[0]
				ind++;
	}
	return ind;
}

int* pivotPartition(int pivot_position, int n, int *a)
{
	int *ar, sm=0, lr=0;
	ar = (int*)malloc(n*sizeof(int));
	for(int i=1; i<n; i++)
	{		
			ar[pivot_position] = a[0];
			if(a[i]<=a[0])
			{
					ar[sm] = a[i];  sm++; 
			}
			else
			{
				ar[pivot_position+lr+1] = a[i]; lr++;
			} 
		  
	}	
	
	return ar;
}
int main()
{
	int index=0, *a, n;
	
	printf("Please enter size of array:");
	scanf("%d", &n);
	a = (int*)malloc(n*sizeof(int));
	printf("Please enter the values of array:");
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	index = findPivotPosition(a, n);
	a = pivotPartition(index, n, a);
	
	printf("Partition occured at %dth position:", index);
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
}
