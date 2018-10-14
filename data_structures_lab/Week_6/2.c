#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
	int top, capacity;
	char *ar;
}stack;

typedef struct queue
{
	int front, rear, capacity;
	char *ar;
}queue;

stack *createStack(int capacity)
{
	stack *st;
	st = (stack*)malloc(sizeof(stack));
	st->top = 0;
	st->capacity = capacity;
	st->ar = (char*)malloc(capacity*sizeof(char));
	for(int i=0; i<capacity; i++)
		(st->ar)[i]='0';
	return st;
}

queue *createQueue(int capacity)
{
	queue *qu;
	qu = (queue*)malloc(sizeof(queue));
	qu->front = 0;
	qu->rear = -1;
	qu->capacity = capacity;
	qu->ar = (char*)malloc(capacity*sizeof(char));
	return qu;
}

int priority(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' | c=='/')
		return 2;
	else if(c=='+' | c=='-')
		return 1;
	else 
		return -1;   
}

int checker(char c)
{
	if(c=='+' | c=='*' | c=='/' | c=='^' || c=='(' | c==')' | c=='-')
		return 1;
	else 
		return 0;
}

void push(stack *st, char key)
{
	st->top=(st->top)+1;
	(st->ar)[st->top]=key;
	//printf("pushing %c\n", (st->ar)[st->top]);
	return;
}

char pop(stack *st)
{
	char ch;
	if(st->top==0)
	{
		return '?';
	}
	ch = (st->ar)[st->top];
	st->top = (st->top)-1;
	//printf("popping %c\n", ch);
	return ch;
}

char peek(stack *st)
{
	//printf("Peek value %c\n", (st->ar)[st->top]);
	return (st->ar)[st->top];
}

void queuee(queue *qu, char c)
{
	qu->rear= (qu->rear)+1;
	(qu->ar)[qu->rear] = c;
	//printf("Queued value %c\n", c);
	return; 
}

void display(queue *qu)
{
	int rear=qu->rear, front=qu->front;
	int helper=0;
	while(rear>=front)
	{
		printf("%c", (qu->ar)[(qu->front)+helper]);
		front++;
		helper++;
	}
	if(helper!=0)
		printf("\n");
}

int main()
{
	stack *sto;
	queue *pfix;
	char inf[100], ch, ch2;
	int len, flag=0;
	
	scanf("%s", inf);
	len = strlen(inf);
	
	sto = createStack(len);
	pfix = createQueue(len);
	
	for(int i=0; i<len; i++)
	{
		if(checker(inf[i])!=1)		// means character is an operand (A), therefore add it on postfix queue
			queuee(pfix, inf[i]);
		else			// means character is an operator (*). Push it on operator stack
		{	
			if(inf[i]=='(')
				push(sto, '(');
			else if(inf[i]==')')
			{
				ch2=peek(sto);
				while(ch2!='(')
				{
					ch = pop(sto);
					queuee(pfix, ch);
					ch2=peek(sto);
				}
				
				ch2 = pop(sto);
			}
			
			else
			{
				if(priority(inf[i])>priority((sto->ar)[(sto->top)]))
					push(sto, inf[i]);
				else if(priority(inf[i])==priority((sto->ar)[(sto->top)]))
				{
					ch = pop(sto);
					queuee(pfix, ch);
					push(sto, inf[i]);
				}
				else
				{
					ch = peek(sto);
					while(priority(inf[i])<priority(ch))
					{
						ch = pop(sto);
						if(ch!='?')
							queuee(pfix, ch);
					}
					if((sto->ar)[sto->top]=='(')
					{
						flag=1;
						push(sto, inf[i]);
					}
					else if(priority(inf[i])==priority((sto->ar)[(sto->top)]) && flag==0)
					{
						ch = pop(sto);
						queuee(pfix, ch);
						push(sto, inf[i]);
					}
					else
						push(sto, inf[i]);
				}
			}
		}
	} 
	while(sto->top!=0 && (sto->ar)[sto->top]!='(')
	{
		char c;
		queuee(pfix,(sto->ar)[sto->top]);
		c=pop(sto);
	}
	
	display(pfix);

	return 0;
}
