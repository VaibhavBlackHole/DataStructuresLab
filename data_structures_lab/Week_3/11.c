#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

int find_index(int *A, int n)
{
	int i=0;
	for(i=n-2; i>=0; i--)
	{
		//printf("%d", i);
	    	if(A[i]>A[n-1])
	    		return i;
    	}
    	return i;
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A, n, temp, ind=0 ;
    fgets(line, sizeof line, stdin);
    sscanf(line, "%s", v1);
    n=stoi(v1);
    //scanf("%d", &n);
    A = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
	fgets(line, sizeof line, stdin);
	sscanf(line, "%s", v1);
	A[i]= stoi(v1);
    }
  //  for(int i=0; i<n; i++)
    //	scanf("%d", A+i);
    
    ind = find_index(A, n);
    //printf("index is:%d", ind);
    for(int i=n-1; i>ind+1; i--)
    {
    	temp = A[i];
    	A[i]=A[i-1];
    	A[i-1]=temp;
    }
    
    for(int i=0; i<n; i++)
    	printf("%d\n", *(A+i));

        free(A);

    return 0;
}
