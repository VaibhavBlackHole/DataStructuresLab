#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

typedef struct node
{
	char value;
	struct node *next_link;
}node;

typedef struct stack
{
	node* top;
}stack;

stack* createStackLinkedList()
{
	stack *st;
	st=(stack*)malloc(sizeof(stack));
	st->top=NULL;
	return st;
}

void push(stack *st, char key)
{
	node *add;
	add=(node*)malloc(sizeof(node));
	add->value=key;
	if(st->top==NULL)
	{
		add->next_link=NULL;
		st->top=add;
		return;
	}
	
	add->next_link = st->top;
	st->top=add;
	return;
}

char pop(stack *st, char key)
{
	node* deleter;
	//char ex_val ;
	if(st->top==NULL)
		return '0';
	else if(st->top->value=='{' && key=='}' || st->top->value=='(' && key==')' || st->top->value=='[' && key==']')
	{
		deleter = st->top;
		//ex_val = (st->top)->value;
		st->top=(st->top)->next_link;
		free(deleter);
		return 	'1';
	}
	else
		return '0';
	
}


int main (int argc, char **argv)
{
    char line[128];
    char v1;
    char v2;
    char v3;
	int len=0 ;

    stack *st;
    st = createStackLinkedList();
    char ret;

    fgets(line, sizeof line, stdin) ;
    len = strlen(line);
    for(int i=0; i<len; i++)
    {
        v1 = line[i];

        if(v1=='{' || v1=='(' || v1=='[')
        {
            	push(st, v1);
        }
        else if(v1=='}' || v1==')' || v1==']')
        {
            ret = pop(st, v1);
            if(ret=='0')
            {
            	printf("0\n");
            	return 0;
            }
        }
        else if(v1!='\n')
        	printf("INVALID\n");
    }
	if(st->top!=NULL)
	printf("0\n");
	else 
	printf("1\n"); 
    if(st)
        free(st);

    return 0;
}
