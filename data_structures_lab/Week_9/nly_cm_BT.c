#include<stdio.h>
#include<stdlib.h>

int n=0;

void preorder(int *arr, int ind, int n)		
{
	if(ind>=n)				
		return;				
	printf("%d ", arr[ind]);		
	preorder(arr, 2*ind+1, n);		
	preorder(arr, 2*ind+2, n);
	return;
}

void postorder(int *arr, int ind, int n)	
{
	if(ind>=n)				
		return;
	postorder(arr, 2*ind+1, n);		
	postorder(arr, 2*ind+2, n);
	printf("%d ", arr[ind]);
	return;
}

void inorder(int *arr, int ind, int n)		
{
	if(ind>=n)				
		return;
	inorder(arr, 2*ind+1, n);		
	printf("%d ", arr[ind]);
	inorder(arr, 2*ind+2, n);
	return;
}

int main()
{
	int vtc,i=0;
	int *ver;
	ver = (int*)malloc(200*sizeof(int));		
	scanf("%d\n", &vtc);				
	//printf("%d", vtc);
	for(int j=0; j<vtc; j++)	
	{
		scanf("%d\n", &ver[j]);			
		n++;
		
	}
	
	inorder(ver, 0, n);			
	printf("\n");				
	preorder(ver, 0, n);			
	printf("\n");
	postorder(ver, 0, n);			
	printf("\n");
	free(ver);
	return 0;
}

