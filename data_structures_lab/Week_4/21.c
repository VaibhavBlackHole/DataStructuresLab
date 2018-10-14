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

typedef struct stack
{
	int top, capacity;
	int *s;	// s contains the array on which we are working
} stack;

stack* make_stack(int capacity)
{
	stack *stk;
	stk = (stack*)malloc(sizeof(stack));
	stk->top = -1;
	stk->capacity = capacity;
	stk->s = (int*)malloc(capacity*sizeof(int));
	return stk;
}

int push(stack *stk,int key)
{
	if(stk->top==(stk->capacity)-1)
		return -1;
	(stk->top)++;
	//printf("%d\n", stk->top);
	(stk->s)[stk->top]=key;
	return 1;
	
    /* Insert the element key into the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

int pop(stack *stk)
{
	int output=-1 ;
	if(stk->top==-1)
		return -1;
	output = (stk->s)[stk->top];
	(stk->top)--;
	return output;
    /* Delete the element A[i] from the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
}

int top(stack *stk)
{
	if(stk->top==-1)
		return -1;
	return (stk->s)[stk->top];
    /* Decrease the value of A[i] to newVal. Return 1 if the
    operation is successful and -1 otherwise. */
}

void print(stack *stk)
{
	int tpo;
	if(stk->top==-1)
		return;
	tpo = stk->top;
	while(tpo>=0)
	{
		printf("%d\n", (stk->s)[tpo]);
		tpo--;
	}
    /* Ensure that the subtree rooted at A[i] is a min heap. */
}

int size(stack *stk)
{
	if(stk->top==-1)
		return 0;
	return (stk->top)+1;
    /* Delete the root of the min heap represented by A. Return
    the deleted element if the operation is successful and -1
    otherwise. */
}

int isEmpty(stack *stk)
{
	if(stk->top==-1)
		return 1;
	return -1;
    /* Get the root of the min heap represented by A. Return
    the element if the operation is successful and -1 otherwise. */
}

int isFull(stack *stk)
{
	if(stk->top==(stk->capacity)-1)
		return 1;
	return -1;
    /* Display the heap represented by A in the increasing order
    of their indices, one element per line.*/
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    stack* stk = NULL;
    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {
            stk = make_stack(stoi(v1));
            continue;
        }

        if(strcmp(v1,"PSH") == 0)
        {
            ret =push(stk,stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"POP") == 0)
        {
            ret = pop(stk);
                printf("%d\n", ret);
        }
        else if(strcmp(v1,"TOP") == 0)
        {
            ret = top(stk);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(stk);
        }
        else if(strcmp(v1,"SZE") == 0)
        {
            ret = size(stk);
                printf("%d\n", ret);
        }
        else if(strcmp(v1,"EMP") == 0)
        {
            ret = isEmpty(stk);
   	         printf("%d\n", ret);
      
        }
        else if(strcmp(v1,"FUL") == 0)
        {
            ret = isFull(stk);
                printf("%d\n", ret);
        }
        else 
        {
            printf("INVALID\n");
        }
    }

    if(stk)
        free(stk);

    return 0;
}
