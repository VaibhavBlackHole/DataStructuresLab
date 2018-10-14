#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

// infix is the basic form in which we write any algebric equation. Ex- a*b+c-d/e+f
// postfix is the better way of representation. Ex- ab*c+de/-f+ <- way of representing above equation in postfix form.
// if the value inserted is an operator calculate the operation using last 2 operand with operator and put the final value on the stack, if it is an operand push it on the stack.
typedef struct stack
{
	int top, capacity;
	int *arr;
}stack;

stack* createStack(int capacity)
{
	stack *st;
	st = (stack*)malloc(sizeof(stack));
	st->capacity=capacity;
	st->top=-1;
	st->arr=(int*)malloc(capacity*sizeof(int));
	return st;
}

void push(stack *st, int c)
{
	if(st->top==st->capacity)
	{
		//printf("invalid\n");
		st->capacity=-1;
		return;
	}
	st->top = (st->top)+1;
	(st->arr)[st->top] = c;
	return;
}

int pop(stack *st)
{
	int ch;
	if(st->top==-1)
	{
		//printf("invalid\n");
		st->capacity=-1;
		return -1;
	}
	ch = (st->arr)[(st->top)];
	st->top = (st->top)-1;
	return ch;
}

int charCheckerValue(char c, stack *st)
{
	if(c=='+')
		return 1;
	else if(c=='-')
		return 2;
	else if(c=='*')
		return 3;
	else if(c=='/')
		return 4;
	else if(c=='^')
		return 5;
	else
	{
		//printf("invalid\n");
		st->capacity=-1;
		return -1;
	}
}

int charChecker(char c)
{
	if(c=='+' | c=='-' | c=='*' | c=='/' | c=='^')
		return 1;
	return -1;
}

long int power(int a, int b)
{
	long int i;
	if(b==1)
		return a;
	else if(b%2==0)
	{	
		i = power(a, b/2);
		return i*i;
	}  
	else
	{
		i = power(a, (b-1)/2);
		return i*i*a; 
	}
}

void calculateValue(stack *st, char *c)
{
	int ch1, ch2;
	int i;
	if(charChecker(c[0])!=1)
		push(st, stoi(c));
	else
	{
		ch1 = pop(st);
		ch2 = pop(st);
		if(ch1!=-1 && ch2!=-1)
		{
			if(charCheckerValue(c[0], st)==1)
			{
				i = ch1+ch2;
				push(st, i);
			}
			else if(charCheckerValue(c[0], st)==2)
			{
				i = ch2-ch1;
				push(st, i);
			}
			else if(charCheckerValue(c[0], st)==3)
			{
				i =ch1*ch2;
				push(st, i);
			}
			else if(charCheckerValue(c[0], st)==4 && ch1!=0)
			{
				i = ch2/ch1;
				push(st, i);
			}
			else if(charCheckerValue(c[0], st)==4 && ch1==0)
			{
				printf("division by 0\n");
				st->capacity=-2;
				return ;
			}
			else if(charCheckerValue(c[0], st)==5)
			{
				i = power(ch2, ch1);
				push(st, i);
			}
			else 
				return;
		}
	}
	return;
}

int main (int argc, char **argv)
{
	stack *st;
	char ar[100];
	
	st = createStack(128);

    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int ret;
    int lineNo = 0;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s", v1);
        lineNo++;

        calculateValue(st, v1);
        
    }
    if(st->top==0 && st->capacity!=-2)
    	printf("%d\n", (st->arr)[0]);
    else if(st->capacity!=-2)
    	printf("invalid\n");

     free(st);

    return 0;
}
