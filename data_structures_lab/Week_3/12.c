#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

void merge(int* ar1, int* ar2, int len1, int len2)
{
	int i=0, j=0, k=0; 
	int a[len1+len2];
	while(i<len1 && j<len2)
	{
			if(ar1[i]<=ar2[j])
			{
					a[k] = ar1[i];	
					i++;	k++;
			}		
			else
			{
					a[k] = ar2[j];
					j++;   	k++;
			}		
	}
	
	while(i<len1)
	{
			a[k] = ar1[i];
			i++;	 k++;
	}
	
	while(j<len2)
	{
			a[k]= ar2[j];
			j++;	 k++;
	}
	
	for(i=0; i<len1; i++)
		ar1[i]=a[i];
	for(i=0; i<len2; i++)
		ar2[i]=a[i+len1];

}

int main (int argc, char **argv)
{
	char line[128];
	char v1[15];
	char v2[15];
	char v3[15];

	int *arr1, *arr2, n1, n2;
	
	fgets(line, sizeof line, stdin);
	sscanf(line, "%s", v1);
	n1=stoi(v1);
	arr1 = (int *)malloc(n1*sizeof(int));			//scanf("%d", &n1);
								//for(int i=0; i<n1; i++)	
								//	scanf("%d", arr1+i);
	for(int i=0;i<n1;i++)				
    	{
		fgets(line, sizeof line, stdin);
	 	sscanf(line, "%s", v1);
		arr1[i]= stoi(v1);
    	}
    	
    	fgets(line, sizeof line, stdin);
    	sscanf(line, "%s", v1);
   	n2=stoi(v1);					//scanf("%d", &n2);
	arr2 = (int*)malloc(n2*sizeof(int));
	for(int i=0;i<n2;i++)
	{
		fgets(line, sizeof line, stdin);
	 	sscanf(line, "%s", v1);
		arr2[i]= stoi(v1);
	}						//for(int i=0; i<n2; i++)
							//	scanf("%d", arr2+i);
	merge(arr1, arr2, n1, n2);
	
	for(int i=0; i<n1; i++)
		printf("%d\n", arr1[i]);
	for(int i=0; i<n2; i++)
		printf("%d\n", arr2[i]);
		
	free(arr1);
	free(arr2);
	return 0;

}
