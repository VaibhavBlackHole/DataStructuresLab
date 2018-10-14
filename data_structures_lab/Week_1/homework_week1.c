#include<stdio.h>
#include<stdlib.h>
int main()
{
	int p, q, i, j, x, y, sum;
	int *M, **ptr_ptr;
	printf("Give the size of 2-d array: ");
	scanf("%d%d", &p, &q);
	ptr_ptr = (int **)malloc(p*sizeof(int*)); 		// initializing pointer to pointer

	
	for(i=0; i<p; i++)
			ptr_ptr[i]= (int *)malloc(q*sizeof(int));	// initializing pointer using pointer to pointer

	
	printf("Now give the values:\n");	
	for(i=0; i<p; i++)			// scanning values of matrix
	{
		for(j=0; j<q; j++)
					scanf("%d",(ptr_ptr[i]+j));			
	}


	printf("Matrix:\n");
	for(i=0; i<p; i++)		// printing matrix
	{
		for(j=0; j<q; j++)
					printf("%d ",ptr_ptr[i][j]);			
		
		printf("\n");
	}


	printf("\nTranspose:\n");
	for(i=0; i<q; i++)		// printing transpose
	{
		for(j=0; j<p; j++)		
			printf("%d ", ptr_ptr[j][i]);
		printf("\n");
	}


	printf("\n");
	printf("Give the new size of 2-d array: ");
	scanf("%d%d", &x, &y);   // finding x and y to increse size of array
	ptr_ptr = (int **)realloc(ptr_ptr, x*sizeof(int*));
	
	for(i=0; i<x; i++)			// reallocating memory for new array
		ptr_ptr[i] = (int *)realloc(ptr_ptr[i], y*sizeof(int));

	printf("Now give the values:\n");
	for(i=0; i<x; i++)			// scanning the new elements
	{
		for(j=0; j<y; j++)
		{
			if(ptr_ptr[i][j]==0) 
				scanf("%d", ptr_ptr[i]+j);
		}
	}
	
	
	for(i=0; i<x; i++)
			for(j=0; j<y; j++)
				sum+=ptr_ptr[i][j];			// finding sum of the all elements of 2-d array
		
	printf("sum = %d\n", sum);
	return 0;
	
}
