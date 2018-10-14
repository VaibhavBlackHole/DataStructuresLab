#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, *arr, temp, i, j;
	printf("Please enter size of array:");
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	
	printf("Please enter array values:");
	for(i=0; i<n; i++)
		scanf("%d", arr+i);
	
	for(i=0; i<n; i++)
	{
		 j=i+1;
		while(j>=0 && arr[j]<arr[j-1] && j<n)
		{
			temp =  arr[j-1];
			arr[j-1]= arr[j];
			arr[j]= temp;
			j--;
		}
	}
	
	for(i=0; i<n; i++)
			printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
