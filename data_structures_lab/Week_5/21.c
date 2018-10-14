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

void push(stack *st, char* key)
{
	node *add;
	add=(node*)malloc(sizeof(node));
	add->value=*key;
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

char pop(stack *st)
{
	node* deleter;
	char ex_val ;
	if(st->top==NULL)
		return '-';
	
	deleter = st->top;
	ex_val = (st->top)->value;
	st->top=(st->top)->next_link;
	free(deleter);
	return 	ex_val;
}

char peek(stack *st)
{
	if(st->top==NULL)
		return '-';
	return (st->top)->value;
}

void display(stack *st)
{
	node* temp;
	temp =st->top;
	while(temp!=NULL)
	{
		printf("%c\n", temp->value);
		temp=temp->next_link;
	}	
	return;
}

int size(stack *st)
{
	node* temp;
	temp=st->top;
	int size = 0;
	while(temp!=NULL)
	{
		temp = temp->next_link;
		size++;
	}
	return size;
}

int isEmpty(stack *st)
{
	if(st->top==NULL)
		return 1;
	else return -1;
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    stack *st;
    st = createStackLinkedList();
    char ret;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);

        if(strcmp(v1,"PSH") == 0)
        {
            	push(st, v2);
        }
        else if(strcmp(v1,"POP") == 0)
        {
            ret = pop(st);
            if(ret=='-')
            	printf("-1\n");
            else
                printf("%c\n", ret);
        }
        else if(strcmp(v1,"TOP") == 0)
        {
            ret = peek(st);
            if(ret=='-')
            	printf("-1\n");
            else
            	printf("%c\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            display(st);
        }
        else if(strcmp(v1,"SZE") == 0)
        {
        	ret = size(st);
        	printf("%d\n", ret);
        }
        else if(strcmp(v1, "EMP")==0)
        {
        	ret = isEmpty(st);
        	printf("%d\n", ret);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(st)
        free(st);

    return 0;
}
