#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char c;
	struct node *left , *right;
}node;

typedef struct stack
{
	node **node;
	int top;
}stack;

stack *crStack(int l)
{
	stack *st = (stack*)malloc(sizeof(stack));
	st->node = (node**)malloc(l*sizeof(node*));
	st->top =-1;
	return st;
}

node *crNode(node *opd1 , node *opd2, char c)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->left = opd2;
	nd->right = opd1;
	nd->c = c;
	return nd;
}

int isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	return -1;
}

node *pop(stack *st)
{
	node *nd;
	nd = st->node[st->top];
	st->top = st->top-1;
	return nd;
}

void push(stack *st, node *nd)
{
	st->top=st->top+1;
	st->node[st->top]=nd;
	(st->node[st->top])->left = nd->left;
	(st->node[st->top])->right = nd->right;
	return;
}

void inorder(node* nd)
{
	if(nd==NULL)
		return;
	inorder(nd->left);
	printf("%c", nd->c);
	inorder(nd->right);
	return;
}

int main()
{
	char *exp;
	int l;
	node *opd1, *opd2, *nd;
	stack *st;
	exp = (char*)malloc(100*sizeof(char));
	scanf("%s", exp);
	l = strlen(exp);
	st = crStack(l);
	for(int i=0; i<l; i++)
	{
		if(isOperator(exp[i])==1)
		{
			opd1 = pop(st);
			opd2 = pop(st);
			nd = crNode(opd1, opd2, exp[i]);
			push(st, nd);
			// then pop the two elements
		}
		else
		{
			nd = crNode(NULL, NULL, exp[i]);
			push(st, nd);
		}
	}
	inorder(st->node[0]);
	
	for(int i=0; i<l; i++)
		free(st->node[i]);
	free(st->node);
	free(st);
	free(exp);
	//printf("\n");
	return 0;
}
