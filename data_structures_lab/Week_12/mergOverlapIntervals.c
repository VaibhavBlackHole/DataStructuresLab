#include<stdio.h>
#include<stdlib.h>

typedef struct interval
{
	int strt, ed;
}intval;

void swap(intval *ar1, intval *ar2)
{
		int temp;
		temp = ar1->strt;
		ar1->strt=ar2->strt;
		ar2->strt=temp;
		temp = ar1->ed;
		ar1->ed = ar2->ed;
		ar2->ed = temp;
}

int partition(intval *ar, int st, int end)
{
	int pindex=st, temp;
	int pivot = ar[end].strt;
	
	for(int i=st; i<end; i++)
	{
		if(ar[i].strt<=pivot)
		{
			swap(&ar[i], &ar[pindex]);
			pindex++;
		}
	}
	
	swap(&ar[pindex], &ar[end]);
	
	return pindex;
}

void quickSort(intval *ar, int st, int end)
{
	if(st>=end)
		return;

	int pindex;
	pindex = partition(ar, st, end);
	quickSort(ar, st, pindex-1);
	quickSort(ar, pindex+1, end);
	return;
}

int main()
{	
	int m;
	intval *ar;
	scanf("%d", &m);
	
	ar = (intval*)malloc(m*sizeof(intval));
	for(int i=0; i<m; i++)
		scanf("%d%d", &ar[i].strt, &ar[i].ed);

	quickSort(ar, 0, m-1);
	//for(int i=0; i<m; i++)
		//printf("%d %d\n", ar[i].strt, ar[i].ed);
	//printf("\n");
	
	for(int i=1; i<m+1; i++)
	{
		int end = ar[i-1].ed;
		printf("%d ", ar[i-1].strt);
		while(i<m && end>=ar[i].strt /*&& *end<=ar[i].ed*/)
		{
			if(end<ar[i].ed)
				end=ar[i].ed;
			i++;
		}
		//if(end<=ar[i].ed)
			//end = ar[i].ed;
		//while(i<m-1 && end>ar[i+1].ed)
				//i++;
		
	 	//while(i< m-1 && end>=ar[i+1].strt && end<=ar[i+1].ed)
		//{
			//i++;
			//end=ar[i].ed;
		//}
		printf("%d\n", end);
		//i++;
		//while(i<m-1 && end>ar[i+1].ed)
				//i++;
	}
	return 0;
}
