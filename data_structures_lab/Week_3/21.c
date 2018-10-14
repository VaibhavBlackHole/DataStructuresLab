#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

int heapSize=0;

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
    /* Fill in */
}

void minHeapify(int A[],int i)
{
	int smt = i;
	if(A[i]>A[2*i+1] && 2*i+1<heapSize)	
		smt = 2*i+1;
	
	if(A[2*i+2]<A[smt] && 2*i+2<heapSize)
	{
		smt = 2*i+2;
		swap(&A[i], &A[smt]);
		minHeapify(A, smt);
	}	
	else if(smt!=i)
	{
		swap(&A[i], &A[2*i+1]);
		minHeapify(A, 2*i+1);
	}
	else
		return;
	
    /* Ensure that the subtree rooted at A[i] is a min heap. */
}

int insertKey(int A[], int key)
{
	int flag=0;
	A[heapSize]=key;
	int i = heapSize;
	heapSize++;
	while(i>0)
	{
		if(A[i]<A[(i-1)/2])
		{
			swap(&A[i], &A[(i-1)/2]);
			i= (i-1)/2;
		}
		else
			return 1;
		flag=1;	
	}
	
	//printf("%d\n", A[heapSize-1]);
	if(flag==1 || i==0)
		return 1;
	return -1;
    /* Insert the element key into the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

int increaseKey(int A[], int i, int newVal)
{
	if(i>=heapSize)
		return -1;
	A[i]=newVal;
	minHeapify(A, i);
	return;
}

int decreaseKey(int A[], int i, int newVal)
{
	if(i>=heapSize)
		return -1;
	A[i]=newVal;
	while(i>0)
	{
		if(A[i]<A[(i-1)/2])
		{
			swap(&A[i], &A[(i-1)/2]);
			i= (i-1)/2;
		}
		else
			return 1;
		flag=1;	
	}
	return 1;
    /* Decrease the value of A[i] to newVal. Return 1 if the
    operation is successful and -1 otherwise. */
}

int deleteKey(int A[], int i)
{
	if(heapSize==0)
		return -1;
	A[i]=A[heapSize-1];
	heapSize--;
	minHeapify(A, i);
	return 1;
    /* Delete the element A[i] from the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

int extractMin(int A[])
{
	int val;
	if(heapSize==0)
		return -1;
	val=A[0];
	A[0]=A[heapSize-1];
	heapSize--;
	minHeapify(A,0);
	return val;
    /* Delete the root of the min heap represented by A. Return
    the deleted element if the operation is successful and -1
    otherwise. */
}

int getMin(int A[])
{
	if(heapSize==0)
		return -1;
	return A[0];
    /* Get the root of the min heap represented by A. Return
    the element if the operation is successful and -1 otherwise. */
}

void print(int A[])
{
	int i=0;
	while(i<heapSize)
	{
		printf("%d\n",A[i]);
		i++;
	}
    /* Display the heap represented by A in the increasing order
    of their indices, one element per line.*/
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A = NULL;
    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
            A = (int*) malloc(sizeof(int)* stoi(v1));
            continue;
        }

        if(strcmp(v1,"INS") == 0)
        {
            ret = insertKey(A, stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"DEL") == 0)
        {
            ret = deleteKey(A, stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"EXT") == 0)
        {
            ret = extractMin(A);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(A);
        }
        else if(strcmp(v1,"INC")==0)
	{
		ret = increaseKey(A, stoi(v2) , stoi(v3));
		if(ret<0)
			printf("%d\n", -1);
	}
        else if(strcmp(v1,"DEC") == 0)
        {
            ret = decreaseKey(A, stoi(v2), stoi(v3));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"MIN") == 0)
        {
            ret = getMin(A);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else
        {
            printf("INVALID\n");
        }
    }
      if(A)
        free(A);

    return 0;
}
