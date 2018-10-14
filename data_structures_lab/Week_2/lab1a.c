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
	
	for(i=n-1; i>0; i--)
	{
		if(arr[i-1]>arr[i])         // checking if no is greater than array[n-1]
		{
			temp =  arr[i-1];
			arr[i-1]= arr[i];
			arr[i]= temp;
		}	
	}
		
	
	for(i=0; i<n; i++)
			printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
