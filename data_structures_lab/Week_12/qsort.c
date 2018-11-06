#include<stdio.h>
#include<stdlib.h>

int partition(int *ar, int st, int end)
{
	int pindex=st, temp;
	int pivot = ar[end];
	
	for(int i=st; i<end; i++)
	{
		if(ar[i]<=pivot)
		{
			temp = ar[i];
			ar[i]=ar[pindex];
			ar[pindex]=temp;
			pindex++;
		}
	}
	
	temp = ar[pindex];
	ar[pindex]=ar[end];
	ar[end]=temp;
	
	return pindex;
}

void quickSort(int *ar, int st, int end)
{
	if(st>=end)
		return;

	int pindex;
	pindex = partition(ar, st, end);
	//printf("\n%d\n", pindex);
	quickSort(ar, st, pindex-1);
	quickSort(ar, pindex+1, end);
	return;
}

int main()
{	
	int n;
	int *ar;
	scanf("%d", &n);
	
	ar = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		scanf("%d", ar+i);

	quickSort(ar, 0, n-1);
	for(int i=0; i<n; i++)
		printf("%d ", ar[i]);
	printf("\n");
	return 0;
}
