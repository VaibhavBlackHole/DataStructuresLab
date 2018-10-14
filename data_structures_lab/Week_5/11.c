#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

int push(int *A, int *top, int key, int n)
{
	//int value;
	
		if((*top)==n-1)
		{
			//printf("Sorry stack is full\n");
			return -1 ;
		}
		
		//scanf("%d", &value);
		(*top)++;
		A[*top]=key;
		return 1 ;
	
	
}

int pop(int *A, int *top, int no)
{
	int value = A[*top];
	if((*top)==-1)
	{
		if(no==-1)
			return 0;
		else
			return -1;
	}
	
	(*top)--;
	return value;
}

void displayElement(int *A, int *top)
{
	if((*top)==-1)
	{
		printf("\n");
		return ;
	}	
	for(int i=(*top); i>=0; i--)
		printf("%d\n", A[i]);
	//printf("\n");	
	return;
}
	
int main (int argc, char **argv)
{
	int n1, n2;
	int *arrp, *arrn, top1, top2;
	//printf("Enter the size of stack:");
	//scanf("%d", &n);
	//A = (int *)malloc(n*sizeof(int));
	top1 = -1;
	top2 = -1;
	
	

    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
            n1 = stoi(v1);
            arrp = (int*)malloc(n1*sizeof(int));
            continue;
        }
        if(lineNo == 2)
        {
        	n2 = stoi(v1);
        	arrn = (int*)malloc(n2*sizeof(int));
        	continue;
        }
        if(strcmp(v1,"PSH") == 0)
        {
            if(stoi(v2)>=0)
            {
            		ret = push(arrp, &top1, stoi(v2), n1);
            		if(ret<0)
            			printf("-1\n");
            }
            else if(stoi(v2)<0)
            {
            		ret =push(arrn, &top2, stoi(v2), n2);
            		if(ret<0)
            			printf("-1\n");
            }
        }
        else if(strcmp(v1,"POPN") == 0)
        {
            ret = pop(arrn, &top2, -1);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"POPP") == 0)
        {
            ret = pop(arrp, &top1, 1);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRTP") == 0)
        {
            displayElement(arrp, &top1);
        }
        else if(strcmp(v1,"PRTN") == 0)
        {
            displayElement(arrn, &top2);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(arrp)
        free(arrp);
    if(arrn)
    	free(arrn);
	return 0;
}
