#include<stdio.h>
#include<stdlib.h>

void merge(int* a, int i, int ni, int j, int nj)
{	
	int len1=ni, len2=nj;
	int arr[ni+nj];
	int strt1 = 0, strt2 = 0, k=0; 
	while(ni>0 && nj>0)
	{
		if(a[i+strt1]<=a[j+strt2])
		{
			arr[k]=a[i+strt1];
			strt1++; k++;
			ni--;
		}
		else
		{
			arr[k]=a[j+strt2];
			strt2++; k++;
			nj--; 
		}
	}
	
	while(ni>0)
	{
			arr[k]=a[i+strt1];
			k++;
			strt1++;
			ni--;
	}
	
	while(nj>0)
	{
			arr[k]=a[j+strt2];
			k++;
			strt2++;
			nj--;
	}
	
	strt1=0; 
	while(len1>0)
	{
		a[strt1+i]=arr[strt1];
		strt1++;
		len1--;
	}
	
	strt2=0;
	while(len2>0)
	{
		a[strt2+j]=arr[strt1];
		strt1++; strt2++;
		len2--;
	}
	
	return;
}


void mergeSort(int *A, int start, int end)
{
	if(start>=end)
		return;
	int mid=(start+end)/2;
	mergeSort(A, start, mid);
	mergeSort(A, mid+1, end);
	merge(A, start,mid-start+1, mid+1, end-mid);
	return;	
}

int main()
{
	int n, *arr;
	printf("Give total no of inputs:");
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	
	printf("Give array:");
	for(int k=0; k<n; k++)
		scanf("%d", arr+k);
				
	mergeSort(arr, 0, n-1);
	
	for(int k=0; k<n; k++)
		printf("%d ", arr[k]);
	printf("\n");
	free(arr);
	return 0;		
}

